#pragma once
#include "PlayerGun1.h"
class PlayerGun2 :public PlayerGun1
{
	sf::Clock clk;

public:

	PlayerGun2(int capacity, int Tcapacity, float SpeedFactor, float Damage);
	void update(sf::Time deltaTime, sf::Vector2f aim_direction, std::vector<TileSet*>& allAreas);

};

