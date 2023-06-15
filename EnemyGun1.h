#pragma once
#include "Gun.h"

class EnemyGun1 :public Gun
{

protected:
	sf::Time t2;
	sf::Clock c2;
	bool status;

public:
	EnemyGun1(int type, float SpeedFactor, float Damage);
	EnemyGun1(int type);
	void set_status(const bool a);
	virtual void update(sf::Time deltaTime, sf::Vector2f aim_direction, std::vector<TileSet*>& allAreas);

};

