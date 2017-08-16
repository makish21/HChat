#include "ConnectionType.h"



ConnectionType::ConnectionType() :
	receiveThread(&ConnectionType::receiveMessage, this),
	sendThread(&ConnectionType::sendMessage, this)
{
}


ConnectionType::~ConnectionType()
{
}

void ConnectionType::sendMessage()
{
	while (1)
	{
		Message message;

		std::string string;
		std::getline(std::cin, string);

		message = string;
		message.encrypt(key_);

		sf::Packet packet;
		packet << message;

		if (socket.send(packet) != sf::Socket::Done)
			break;
	}
}

void ConnectionType::sendKey()
{
	sf::Packet packet;

	packet << key_;

	if (socket.send(packet) != sf::Socket::Done)
		return;
}

void ConnectionType::receiveMessage()
{
	while (1)
	{
		Message message;

		sf::Packet packet;

		if (socket.receive(packet) != sf::Socket::Done)
			break;

		packet >> message;
		message.decrypt(key_);

		HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(handle, 0x0003);

		std::cout << message.getString() << std::endl;

		SetConsoleTextAttribute(handle, 0x0007);
	}
}

void ConnectionType::receiveKey()
{
	sf::Packet packet;

	if (socket.receive(packet) != sf::Socket::Done)
		return;

	packet >> key_;
}
