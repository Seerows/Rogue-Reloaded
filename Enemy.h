#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "Player.h"

class Player;

class Enemy : public Unit
{
protected:
	sf::Sprite enemySprite, enemyHand;
	bool movingUp, movingDown, movingLeft, movingRight;
	float enemySpeed;
	float enemyHealth;
	int upCount, downCount, leftCount, rightCount, upRightCount, upLeftCount, downLeftCount, downRightCount, deathCount;
	int spriteSlowValue;
	sf::Vector2f direction;
	float distance;
	float angle;
	float angleBetweenEnemies;
	std::string filePath, filePath2;
	sf::Vector2f position;
	int timer;
	int shootingDistance;
	sf::Vector2f directionBetweenEnemies;
	float distanceBetweenEnemies;
	sf::Vector2f handPosition, handLeft, handDown, handRight, handUp, handUpRight, handUpLeft, handDownLeft, handDownRight;
	bool isDead;
	bool isReversed;

public:
	Enemy();
	void setEnemyHealth(const float health);
	float getEnemyHealth();
	void collisionChecking(Enemy* obj1, sf::Time deltaTime);
	virtual void update(sf::Time deltaTime, Player* player, std::vector<TileSet*>& allAreas);
	sf::Sprite& getSprite();
	void takeDamage(float damage);
	bool hasDied() const;
};