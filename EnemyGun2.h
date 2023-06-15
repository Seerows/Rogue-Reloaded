#pragma once
#include "EnemyGun1.h"

class EnemyGun2 :public EnemyGun1
{

public:
	EnemyGun2(float SpeedFactor, float Damage);
	void Shoot(sf::Time deltaTime, std::vector<TileSet*>& allAreas);
	void update(sf::Time deltaTime, sf::Vector2f aim_direction, std::vector<TileSet*>& allAreas);

};