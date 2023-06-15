#pragma once
#include <iostream>

class User
{
	std::string userName;
	std::string password;
	int score;

	friend class Menu;
	friend class Game;

public:
	User();

};
