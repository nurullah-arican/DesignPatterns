#include "MessageSender.h"

int main()
{
    std::unique_ptr<MessageSender> emailSender = std::make_unique<EmailSender>();
    Notification emailNotification(std::move(emailSender));
    emailNotification.notify("Hello via Email!");

    std::unique_ptr<MessageSender> smsSender = std::make_unique<SmsSender>();
    Notification smsNotification(std::move(smsSender));
    smsNotification.notify("Hello via SMS!");

    return 0;
}