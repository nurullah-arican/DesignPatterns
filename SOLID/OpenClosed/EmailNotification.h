#ifndef EMAIL_NOTIFICATION_HPP
#define EMAIL_NOTIFICATION_HPP

#include "INotification.h"
#include <iostream>

class EmailNotification : public INotification {
public:
    void send(const std::string& message) const override {
        std::cout << "Sending Email: " << message << std::endl;
    }
};

#endif // EMAIL_NOTIFICATION_HPP
