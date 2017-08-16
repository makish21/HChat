#pragma once
#include <string>
#include <SFML\Network.hpp>

#include "Key.h"

class Message
{
public:
	Message();
	~Message();

	void encrypt(Key);
	void decrypt(Key);

	std::string getString();

	Message& operator=(const std::string& right);

	friend sf::Packet& operator<<(sf::Packet& packet, const Message& message);
	friend sf::Packet& operator>>(sf::Packet& packet, Message& message);

	friend std::istream& operator >> (std::istream& istream, Message& message);
	friend std::ostream& operator << (std::ostream& ostream, Message& message);

private:
	std::string message_;
};

