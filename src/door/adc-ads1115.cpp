#include "adc-ads1115.h"

#include <stdexcept>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>

// ADS1115 Register-Konstanten
constexpr uint8_t ADS1115_REG_CONVERSION = 0x00;
constexpr uint8_t ADS1115_REG_CONFIG = 0x01;

Ads1115::Ads1115(const std::string& device_path, uint8_t i2c_address)
{
    // Faktor zur Umrechnung für einen Gain von +/-4.096V
    voltage_multiplier_ = 4.096f / 32767.0f;

    file_descriptor_ = open(device_path.c_str(), O_RDWR);
    if (file_descriptor_ < 0) {
        throw std::runtime_error("I2C-Bus konnte nicht geöffnet werden: " + device_path);
    }

    if (ioctl(file_descriptor_, I2C_SLAVE, i2c_address) < 0) {
        close(file_descriptor_); // Aufräumen im Fehlerfall
        throw std::runtime_error("Kommunikation mit I2C-Gerät fehlgeschlagen.");
    }
}

Ads1115::~Ads1115()
{
    if (file_descriptor_ >= 0) {
        close(file_descriptor_);
    }
}

float Ads1115::get_value() const
{
    // 1. Konfiguration für eine einzelne Messung schreiben
    uint8_t config_buffer[3] = {
        ADS1115_REG_CONFIG,
        0xC3, // Config MSB: Starte Konvertierung, AIN0, Gain +/-4.096V, Single-Shot
        0x83  // Config LSB: 128 SPS, Standard-Komparator
    };

    if (write(file_descriptor_, config_buffer, 3) != 3) {
        throw std::runtime_error("Konfiguration konnte nicht auf den Sensor geschrieben werden.");
    }

    // 2. Warte, bis die Konvertierung abgeschlossen ist (ca. 8ms)
    usleep(8 * 1000);

    // 3. Den Pointer auf das Konvertierungsregister setzen
    uint8_t reg_ptr_buffer[1] = {ADS1115_REG_CONVERSION};
    if (write(file_descriptor_, reg_ptr_buffer, 1) != 1) {
        throw std::runtime_error("Register-Pointer für das Auslesen konnte nicht gesetzt werden.");
    }

    // 4. Den 16-Bit Messwert auslesen
    uint8_t data_buffer[2];
    if (read(file_descriptor_, data_buffer, 2) != 2) {
        throw std::runtime_error("Messdaten konnten nicht vom Sensor gelesen werden.");
    }

    // 5. Bytes zu einem Wert zusammensetzen und in Spannung umrechnen
    int16_t raw_adc = (data_buffer[0] << 8) | data_buffer[1];
    return raw_adc * voltage_multiplier_;
}
