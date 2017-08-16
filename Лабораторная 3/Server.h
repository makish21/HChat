#pragma once
#include "ConnectionType.h"
#include <SFML\Network.hpp>
#include <iostream>
class Server :
	public ConnectionType
{
public:
	Server();
	~Server();

	virtual void run(unsigned short port);

private:
	sf::TcpListener listener_;
};

