#include "Logger.h"
#include <iostream>

void Logger::LogError(const std::string& message) {
    std::cerr << "Error: " << message << std::endl;
}