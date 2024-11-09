#ifndef MESSAGESENDER_H
#define MESSAGESENDER_H

#include <iostream>
#include <string>
#include <memory>

// Interface: MessageSender
class MessageSender {
public:
    virtual void send(const std::string& message) = 0;
    virtual ~MessageSender() = default;
};

// Low-level class: EmailSender implementing MessageSender
class EmailSender : public MessageSender {
public:
    void send(const std::string& message) override {
        std::cout << "Sending email: " << message << std::endl;
    }
};

// Low-level class: SmsSender implementing MessageSender
class SmsSender : public MessageSender {
public:
    void send(const std::string& message) override {
        std::cout << "Sending SMS: " << message << std::endl;
    }
};

// High-level class: Notification depending on the MessageSender interface
class Notification {
public:
    Notification(std::unique_ptr<MessageSender> sender) : sender(std::move(sender)) {}

    void notify(const std::string& message) {
        sender->send(message);
    }

private:
    std::unique_ptr<MessageSender> sender;
};


#endif // MESSAGESENDER_H


