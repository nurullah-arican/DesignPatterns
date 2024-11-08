#include "FileManager.h"
#include <fstream>
#include <iostream>

FileManager::FileManager(Logger& logger) : logger_(logger) {}

void FileManager::ReadFile(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        logger_.LogError("Could not open file.");
        return;
    }
    std::cout << "File content read successfully." << std::endl;
}