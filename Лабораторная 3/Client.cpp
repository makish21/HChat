#include "Client.h"



Client::Client()
{
}


Client::~Client()
{
}

void Client::run(unsigned short port)
{
	std::string address;
	std::cout << "Please, enter IP address: ";
	std::cin >> address;

	sf::IpAddress server = address;

	if (socket.connect(server, port) == sf::Socket::Done)
	{
		std::cout << "Connected to server " << server << std::endl;
		
		receiveKey();

		receiveThread.launch();
		sendMessage();
	}
}
