#ifndef SMS_NOTIFICATION_HPP
#define SMS_NOTIFICATION_HPP

#include "INotification.h"
#include <iostream>

class SmsNotification : public INotification {
public:
    void send(const std::string& message) const override {
        std::cout << "Sending SMS: " << message << std::endl;
    }
};

#endif // SMS_NOTIFICATION_HPP
