#include "MessageFactory.h"

int main()
{
	std::unique_ptr<MessageFactory> smsSender = std::make_unique<SmsFactory>();
	smsSender->SendMessage();

	std::unique_ptr<MessageFactory> emailSender = std::make_unique<EmailFactory>();
	emailSender->SendMessage();
}
