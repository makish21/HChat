#include <iostream>
#include <cstdlib>
#include <string>
#include "ConnectionType.h"
#include "Server.h"
#include "Client.h"

#define PORT 50001

int main()
{
	ConnectionType* connectionType;

	std::string name;
	char ct = 's';

	//std::cout << "Please, enter your name: >";
	//std::cin >> name;

	std::cout << "Srever (s) or client (c)?: >";
	std::cin >> ct;

	if (ct == 's')
	{
		connectionType = new Server();
	}
	else if (ct == 'c')
	{
		connectionType = new Client();
	}
	else
	{
		connectionType = new Server();
	}

	connectionType->run(PORT);

	std::cout << "Press enter to exit..." << std::endl;
	std::cin.ignore(10000, '\n');

	return EXIT_SUCCESS;
}
