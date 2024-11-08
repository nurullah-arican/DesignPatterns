#ifndef LOGGER_H
#define LOGGER_H

#include <string>

class Logger {
public:
    void LogError(const std::string& message);
};

#endif // LOGGER_H