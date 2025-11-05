#include <string>
#include <iostream>
#include <string.h>

int main()
{
    std::string source = "blah";
    const char* source_raw = source.c_str();
    // std::cout << source_raw << std::endl;

    // char* dest = (char*)malloc(source.size());
    // strcpy(dest, source_raw);

    std::string dest = source;

    std::cout << dest << std::endl;

    return 0;
}
