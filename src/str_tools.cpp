//
// Created by pplmx on 2022/09/25.
//

#include "str_tools.h"
#include <regex>

const auto LEADING_SPACE = std::regex("^\\s+");
const auto TRAILING_SPACE = std::regex("\\s+$");
const auto COMMENTS = std::regex("#.*$");

string ltrim(const string &s) {
    return std::regex_replace(s, LEADING_SPACE, string(""));
}

string rtrim(const string &s) {
    return std::regex_replace(s, TRAILING_SPACE, string(""));
}

string trim(const string &s) {
    return ltrim(rtrim(s));
}

string trim_comments(const string &s) {
    return std::regex_replace(s, COMMENTS, string(""));
}
