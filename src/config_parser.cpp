//
// Created by pplmx on 2022/09/25.
//

#include "config_parser.h"
#include "str_tools.h"
#include <fstream>
#include <iostream>

using std::ifstream;
using std::vector;
using std::string;

ConfigParser::ConfigParser() = default;

ConfigParser::~ConfigParser() = default;

void ConfigParser::load(const std::string &path) {
    ifstream ifs(path);
    if (!ifs.is_open()) {
        std::cerr << "Error opening file: " << path << std::endl;
        return;
    }

    lines.clear();

    for (string line; getline(ifs, line);) {
        line = trim(line);

        if (line.empty() || line.starts_with("#")) {
            continue;
        }

        line = trim_comments(line);
        lines.push_back(line);
        std::cout << line << std::endl;
    }

    ifs.close();

    std::cout << "\n\n";
    for (const auto &line: lines) {
        std::cout << line << std::endl;
    }
}
