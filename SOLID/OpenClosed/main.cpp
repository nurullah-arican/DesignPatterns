#include "NotificationSender.h"
#include "EmailNotification.h"
#include "SmsNotification.h"

int main() {
    auto emailNotification = std::make_shared<EmailNotification>();
    NotificationSender emailSender(emailNotification);
    emailSender.sendNotification("Hello via Email!");

    auto smsNotification = std::make_shared<SmsNotification>();
    NotificationSender smsSender(smsNotification);
    smsSender.sendNotification("Hello via SMS!");

    return 0;
}
