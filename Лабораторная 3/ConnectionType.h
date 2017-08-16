#pragma once
#include <SFML\Network.hpp>
#include <iostream>
#include <Windows.h>
#include <sstream>
#include <fstream>
#include <iterator>
#include <algorithm>

#include "Message.h"
#include "Key.h"

class ConnectionType
{
public:
	ConnectionType();
	virtual ~ConnectionType();

	virtual void run(unsigned short port) = 0;

protected:
	sf::TcpSocket socket;

	sf::Thread receiveThread;
	sf::Thread sendThread;

	void sendMessage();
	void sendKey();

	void receiveMessage();
	void receiveKey();
private:
	Key key_;
};

