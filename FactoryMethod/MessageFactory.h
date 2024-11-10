#ifndef MESSAGEFACTORY_H
#define MESSAGEFACTORY_H

#include <iostream>
#include <memory>

class IMessage
{
public:
	virtual ~IMessage() = default;
	virtual void SendMessage() = 0; // Pure virtual function
};

class SMS : public IMessage
{
public:
	void SendMessage() override {
		std::cout << "Message is sent via SMS!" << std::endl;
	}
};

class Email : public IMessage
{
public:
	void SendMessage() override {
		std::cout << "Message is sent via Email!" << std::endl;
	}
};

class MessageFactory
{
public:
	virtual ~MessageFactory() = default;

	virtual std::unique_ptr<IMessage> CreateMessage() = 0;

	void SendMessage() {
		auto message = CreateMessage();
		message->SendMessage();
	}

};

class EmailFactory : public MessageFactory
{
public:
	std::unique_ptr<IMessage> CreateMessage() override {
		return std::make_unique<Email>();
	}
};

class SmsFactory : public MessageFactory
{
public:
	std::unique_ptr<IMessage> CreateMessage() override {
		return std::make_unique<SMS>();
	}
};

#endif // MESSAGEFACTORY_H
