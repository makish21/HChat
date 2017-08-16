#include "Key.h"



Key::Key()
{
	srand(time(NULL));

	for (auto i = 0; i < KEY_LENGTH; i++)
	{
		key_[i] = rand() % UCHAR_MAX;
	}
}

Key::~Key()
{
}

unsigned char & Key::operator[](int index)
{
	return key_[index];
}

sf::Packet & operator<<(sf::Packet & packet, const Key & key)
{
	for (auto i = 0; i < KEY_LENGTH; i++)
	{
		packet << key.key_[i];
	}

	return packet;
}

sf::Packet & operator >> (sf::Packet & packet, Key & key)
{
	for (auto i = 0; i < KEY_LENGTH; i++)
	{
		packet >> key.key_[i];
	}

	return packet;
}
