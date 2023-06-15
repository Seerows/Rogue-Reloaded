#include "Enemy.h"

Enemy::Enemy()
{
	enemyHealth = 50.0;
	enemySpeed = 150.0;
	spriteSlowValue = 7;
	filePath = "Texture/";
	upCount = 0;
	downCount = 0;
	leftCount = 0;
	rightCount = 0;
	upLeftCount = 0;
	upRightCount = 0;
	deathCount = 0;
	isDead = false;
	isReversed = false;
}

void Enemy::update(sf::Time deltaTime, Player* player, std::vector<TileSet*>& allAreas) {

}


void Enemy::setEnemyHealth(const float a)
{
	enemyHealth = a;
}

float Enemy::getEnemyHealth()
{
	return enemyHealth;
}

sf::Sprite& Enemy::getSprite()
{
	return enemySprite;
}


void Enemy::collisionChecking(Enemy* obj1, sf::Time deltaTime)
{

	directionBetweenEnemies.x = obj1->enemySprite.getPosition().x - enemySprite.getPosition().x;
	directionBetweenEnemies.y = obj1->enemySprite.getPosition().y - enemySprite.getPosition().y;
	distanceBetweenEnemies = std::sqrt(std::powf(directionBetweenEnemies.x, 2) + std::pow(directionBetweenEnemies.y, 2.f));

	directionBetweenEnemies /= distanceBetweenEnemies;

	angleBetweenEnemies = atan2f(-1 * (float)directionBetweenEnemies.y, (float)directionBetweenEnemies.x);
	angleBetweenEnemies = angleBetweenEnemies * 180.f * (7.f / 22);

	if (distanceBetweenEnemies < 100 && !isReversed && !obj1->isReversed)
	{
		directionBetweenEnemies.y *= -1;
		directionBetweenEnemies.x *= -1;
		enemySprite.move(directionBetweenEnemies * enemySpeed * deltaTime.asSeconds());
	}

}


void Enemy::takeDamage(float damage)
{
	enemyHealth -= damage;
}

bool Enemy::hasDied() const {
	return isDead;
}