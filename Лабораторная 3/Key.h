#pragma once
#include <iostream>
#include <time.h>
#include <SFML\Network.hpp>

#define KEY_LENGTH 8
#define DUMBLEDORE 16

class Key
{
public:
	Key();
	~Key();

	unsigned char& operator[](int index);

	friend sf::Packet& operator<<(sf::Packet& packet, const Key& key);
	friend sf::Packet& operator>>(sf::Packet& packet, Key& key);

private:
	unsigned char key_[KEY_LENGTH];
	signed char dumbledore_[DUMBLEDORE];
};