#include "config_parser.h"
#include <iostream>
#include <filesystem>

#ifdef _WIN32

#include <stdlib.h>

#endif

namespace fs = std::filesystem;

// Helper function to safely get an environment variable
std::string get_env_variable(const char *var) {
    char *val_cstr = nullptr;
    size_t len = 0;
    if (_dupenv_s(&val_cstr, &len, var) != 0 || val_cstr == nullptr) {
        throw std::runtime_error(std::string("Environment variable not set: ") + var);
    }
    std::string val(val_cstr);
    free(val_cstr);
    return val;
}

int main() {
    std::cout << "Hello, World!" << std::endl;

    std::string home;
    try {
#ifdef _WIN32
        home = get_env_variable("USERPROFILE");
#else
        home = get_env_variable("HOME");
#endif
    } catch (const std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
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
