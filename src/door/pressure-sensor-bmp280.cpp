#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>
#include <cstdint>

#include "pressure-sensor-bmp280.h"

#define BMP280_ADDR 0x76
#define BMP280_REG_CONTROL 0xF4
#define BMP280_REG_CONFIG  0xF5
#define BMP280_REG_PRESSURE_MSB 0xF7

BMP280::BMP280()
: _pressure {}{}

float BMP280::get_pressure() const
{
    int fd = open("/dev/i2c-1", O_RDWR);
    if (fd < 0) {
        perror("Failed to open /dev/i2c-1");
        return 1;
    }

    if (ioctl(fd, I2C_SLAVE, BMP280_ADDR) < 0) {
        perror("Failed to acquire bus access and/or talk to slave");
        close(fd);
        return 1;
    }

    // Write config
    uint8_t config1[2] = {BMP280_REG_CONTROL, 0x27};  // Temp+Press oversampling x1, normal mode
    uint8_t config2[2] = {BMP280_REG_CONFIG, 0xA0};   // Standby 1000ms, filter off
    write(fd, config1, 2);
    write(fd, config2, 2);

    // sleep for 100ms to allow sensor to stabilize
    usleep(100000);

    // TODO: Read calibration data

    double pressure = 0.0;
    if (var1_p != 0) {
        int64_t p = 1048576 - raw_press;
        p = (((p << 31) - var2_p) * 3125) / var1_p;
        var1_p = ((int64_t)dig_P9 * (p >> 13) * (p >> 13)) >> 25;
        var2_p = ((int64_t)dig_P8 * p) >> 19;
        p = ((p + var1_p + var2_p) >> 8) + (((int64_t)dig_P7) << 4);
        pressure = p / 25600.0;  // Convert to hPa
    }

    std::cout << "Pressure: " << pressure << " hPa" << std::endl;

    close(fd);

    return _pressure;
}