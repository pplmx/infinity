#include "config_parser.h"
#include <iostream>
#include <filesystem>
#include <cstdlib>

namespace fs = std::filesystem;

// Helper function to safely get an environment variable
std::string get_env_variable(const char* var)
{
    if (const char* val = std::getenv(var))
    {
        return val;
    }
    throw std::runtime_error(std::string("Environment variable not set: ") + var);
}

int main()
{
    try
    {
        // Get the current executable path
        const fs::path exe_path = fs::current_path() / "../../xmake.lua";

        // Load and parse the configuration
        ConfigParser configParser;
        configParser.load(exe_path.string());

        std::cout << "Configuration loaded successfully." << std::endl;
        return EXIT_SUCCESS;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
}
