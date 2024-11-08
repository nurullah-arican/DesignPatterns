#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "Logger.h"
#include <string>


class FileManager {
public:
    FileManager(Logger& logger);
    void ReadFile(const std::string& filePath);

private:
    Logger& logger_;
};

#endif // FILEMANAGER_H
