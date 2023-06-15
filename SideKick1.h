#pragma once
#include "Enemy.h"
#include "EnemyGun1.h"

class SideKick1 : public Enemy
{
	EnemyGun1 pistol;
	int deathCountUp, deathCountDown, deathCountLeft, deathCountRight, deathCountUpRight, deathCountUpLeft, deathCountDownLeft, deathCountDownRight;
public:
	SideKick1();
	void enemySpriteCreate();
	void update(sf::Time deltaTime, Player* player, std::vector<TileSet*>& allAreas);
	void render(sf::RenderWindow* window);
};
