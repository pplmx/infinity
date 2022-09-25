//
// Created by pplmx on 2022/09/25.
//

#ifndef INFINITY_CONFIG_PARSER_H
#define INFINITY_CONFIG_PARSER_H


class ConfigParser {

public:
    ConfigParser();
    virtual ~ConfigParser();
    static void load(const char *path) ;

};


#endif //INFINITY_CONFIG_PARSER_H
