//
// Created by pplmx on 2022/09/25.
//

#include <string>
#include <algorithm>

// Function to trim leading spaces
std::string ltrim(const std::string &s) {
    size_t start = s.find_first_not_of(" \t\n\r\f\v");
    return (start == std::string::npos) ? "" : s.substr(start);
}

// Function to trim trailing spaces
std::string rtrim(const std::string &s) {
    size_t end = s.find_last_not_of(" \t\n\r\f\v");
    return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}

// Function to trim both leading and trailing spaces
std::string trim(const std::string &s) {
    return ltrim(rtrim(s));
}

// Function to remove comments
std::string trim_comments(const std::string &s) {
    size_t pos = s.find('#');
    return (pos == std::string::npos) ? s : s.substr(0, pos);
}
