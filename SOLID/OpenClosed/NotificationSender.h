#ifndef NOTIFICATION_SENDER_HPP
#define NOTIFICATION_SENDER_HPP

#include "INotification.h"
#include <memory>
#include <string>

class NotificationSender {
private:
    std::shared_ptr<INotification> notification;

public:
    NotificationSender(std::shared_ptr<INotification> notif) : notification(notif) {}

    void sendNotification(const std::string& message) const {
        notification->send(message);
    }
};

#endif // NOTIFICATION_SENDER_HPP
