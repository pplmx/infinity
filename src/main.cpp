#include "config_parser.h"
#include <iostream>
#include <cstdlib>
#include <filesystem>

namespace fs = std::filesystem;

int main() {
    std::cout << "Hello, World!" << std::endl;

    const char *home = getenv("HOME");
    if (!home) {
        std::cerr << "Error: HOME environment variable not set." << std::endl;
        return EXIT_FAILURE;
    }

    fs::path p = fs::path(home) / "JetBrains/CLionProjects/infinity/CMakeLists.txt";
    try {
        p = fs::canonical(p);
    } catch (const std::exception &ex) {
        std::cerr << "Canonical parser threw exception: " << ex.what() << std::endl;
        return EXIT_FAILURE;
    }

    ConfigParser configParser;
    configParser.load(p.string());

    return EXIT_SUCCESS;
}
