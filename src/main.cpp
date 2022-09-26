#include "config_parser.h"
#include <iostream>
#include <cstdlib>
#include <filesystem>

namespace fs = std::filesystem;

int main() {
    std::cout << "Hello, World!" << std::endl;
    const char *home = getenv("HOME");
    auto p = fs::path(home) / fs::path("JetBrains/CLionProjects/infinity/CMakeLists.txt");
    try {
        p = canonical(p);
    } catch (const std::exception &ex) {
        printf("Canonical parser threw exception: %s.", ex.what());
    }
    ConfigParser::load(p.make_preferred().c_str());
    return 0;
}
