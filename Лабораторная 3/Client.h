#pragma once
#include "ConnectionType.h"
class Client :
	public ConnectionType
{
public:
	Client();
	~Client();

	virtual void run(unsigned short port);

private:
	sf::IpAddress _server;
};

