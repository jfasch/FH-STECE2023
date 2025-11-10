#include <string>
#include "small_file_handling.h"
#include <stdio.h>
#include <iostream>

#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

void write_string_to_file(const char *dest_filepath, const std::string &content)
{
    int dest_fd = open(dest_filepath, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);

    ssize_t nbytes_written = write(dest_fd, content.c_str(), content.length());

    if(nbytes_written != (ssize_t) content.length())
    {
        //error handling
    }

    close(dest_fd);
}

void write_number_to_file(const char *dest_filepath,const int number)
{
    int dest_fd = open(dest_filepath, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);

    ssize_t nbytes_written = write(dest_fd,(const void*) number, sizeof(int));

    if(nbytes_written != (ssize_t) sizeof(int))
    {
        //error handling
    }

    close(dest_fd);
}

int read_number_from_file(const char *source_filepath)
{
    int source_fd = open(source_filepath, O_RDONLY , S_IRUSR | S_IWUSR);

    int number_to_read = 0;

    ssize_t nbytes_read = read(source_fd, (void*) &number_to_read, sizeof(int));

    if(nbytes_read != (ssize_t) sizeof(int))
    {
        //error handling
    }

    close(source_fd);

    return number_to_read;
}
 
std::string read_string_from_file(const char *source_filepath)
{
    int source_fd = open(source_filepath, O_RDONLY , S_IRUSR | S_IWUSR);

    char buffer[1024];
    size_t buffer_size = sizeof(buffer);


    ssize_t nbytes_read = read(source_fd, buffer, buffer_size);

    if(nbytes_read < 0)
    {
        //error handling
    }

    close(source_fd);

    std::string return_string(buffer, nbytes_read);

    return return_string;
}