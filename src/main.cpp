#include <iostream>
#include "config_parser.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    ConfigParser::load(R"(C:\Users\pplmx\JetBrains\CLionProjects\infinity\CMakeLists.txt)");
    return 0;
}

