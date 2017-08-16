#include "Server.h"



Server::Server()
{
}


Server::~Server()
{
}

void Server::run(unsigned short port)
{
	std::cout << "You are server.\nLocal IP: " << sf::IpAddress::getLocalAddress() <<
		"\nPublic IP: " << sf::IpAddress::getPublicAddress() << std::endl;

	switch (listener_.listen(port))
	{
		case sf::Socket::Status::Done:
		break;

		case sf::Socket::Status::NotReady:
		std::cout << "Server not ready to send/receive data" << std::endl;
		return;
	}

	std::cout << "Server is listening to port " << port << ", waiting for connections... " << std::endl;

	sf::Socket::Status status = listener_.accept(socket);

	if (status == sf::Socket::Status::Done)
	{
		std::cout << "Client connected: " << socket.getRemoteAddress() << std::endl;

		sendKey();

		receiveThread.launch();
		//sendThread.launch();
		sendMessage();
	}
}