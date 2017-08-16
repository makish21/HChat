#include "Message.h"



Message::Message()
{
}


Message::~Message()
{
}

void Message::encrypt(Key key)
{
	for (auto i = 0; i < message_.length(); i++)
	{
		message_[i] = message_[i] ^ key[i % KEY_LENGTH];
	}
}

void Message::decrypt(Key key)
{
	for (auto i = 0; i < message_.length(); i++)
	{
		message_[i] = message_[i] ^ key[i % KEY_LENGTH];
	}
}

std::string Message::getString()
{
	return message_;
}

Message & Message::operator=(const std::string & right)
{
	if (this->message_ == right)
	{
		return *this;
	}
	message_ = right;
	return *this;
}

sf::Packet & operator<<(sf::Packet & packet, const Message & message)
{
	return packet << message.message_;
}

sf::Packet & operator >> (sf::Packet & packet, Message & message)
{
	return packet >> message.message_;
}

std::istream & operator >> (std::istream & istream, Message & message)
{
	return istream >> message.message_;
}

std::ostream & operator<<(std::ostream & ostream, Message & message)
{
	return ostream << message.message_;
}
