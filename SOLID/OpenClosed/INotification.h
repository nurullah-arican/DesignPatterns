#ifndef NOTIFICATION_HPP
#define NOTIFICATION_HPP

#include <string>

class INotification {
public:
    virtual void send(const std::string& message) const = 0;
    virtual ~INotification() = default;
};

#endif // NOTIFICATION_HPP