//
// Created by pplmx on 2022/09/25.
//

#include "config_parser.h"
#include "str_tools.h"
#include <fstream>
#include <vector>

using std::ifstream, std::vector;

ConfigParser::ConfigParser() = default;

ConfigParser::~ConfigParser() = default;

void ConfigParser::load(const char *path) {
    ifstream ifs(path);
    vector<string> lines;
    for (string line; getline(ifs, line);) {
        // remove the empty line
        line = trim(line);
        if (line.empty()) {
            continue;
        }
        // remove the comment line or the content after the sign "#"
        if (line.starts_with("#")) {
            continue;
        }
        line = trim_comments(line);
        lines.push_back(line);
        printf("%s\n", line.c_str());
    }
    printf("\n\n");
    for (const auto &line: lines) {
        printf("%s\n", line.c_str());
    }
    ifs.close();
}
