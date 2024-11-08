#include "FileManager.h"
#include "Logger.h"

int main() {
    Logger logger;
    FileManager fileManager(logger);

    fileManager.ReadFile("example.txt");

    return 0;
}