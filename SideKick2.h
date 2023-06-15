#pragma once
#include "Enemy.h"
#include "EnemyGun1.h"

class SideKick2 : public Enemy
{
	EnemyGun1 pistol;

public:
	SideKick2();
	int timer;
	void enemy2SpriteCreate();
	void update(sf::Time deltaTime, Player* player, std::vector<TileSet*>& allAreas);
	void render(sf::RenderWindow* window);
};