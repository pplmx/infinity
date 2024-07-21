//
// Created by pplmx on 2022/09/25.
//

#ifndef CONFIG_PARSER_H
#define CONFIG_PARSER_H

#include <string>
#include <vector>

class ConfigParser {
public:
    ConfigParser();

    ~ConfigParser();

    void load(const std::string &path);

private:
    std::vector<std::string> lines;
};

#endif // CONFIG_PARSER_H
