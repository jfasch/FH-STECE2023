#include "database.h"

#include <regex>
#include <print>

Record split_line(const std::string& line)
{
    static const std::regex re_line("^(\\d+)\\s+(\\w+)\\s+(\\w+)\\s*$");

    std::smatch match;
    if (std::regex_search(line, match, re_line)) {
        return Record(std::stoi(match[1].str()), match[2].str(), match[3].str());
    }
    else
        return Record();
}

void Database::insert(const Record& r) {
    std::println("insert id={}, firstname={}, lastname={}", r.id, r.firstname, r.lastname);
}
void Database::commit() {
    std::println("commit");
}
void Database::rollback() {
    std::println("rollback");
}
