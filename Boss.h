#pragma once
#include "Enemy.h"
#include "EnemyGun2.h"

class Boss : public Enemy
{
	EnemyGun2 pistol;

public:
	Boss();
	void enemySpriteCreate();
	void update(sf::Time deltaTime, Player* player, std::vector<TileSet*>& allAreas);
	void render(sf::RenderWindow* window);
};
