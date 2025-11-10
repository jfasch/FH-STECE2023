#ifndef SMALL_FILE_HANDLING_H
#define SMALL_FILE_HANDLING_H

#include <string>

void write_string_to_file(const char *dest_filepath, const std::string &content);

void write_number_to_file(const char *dest_filepath, const int number);

int read_number_from_file(const char *source_filepath);
 
std::string read_string_from_file(const char *source_filepath);
#endif