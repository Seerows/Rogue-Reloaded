#include "EnemyGun2.h"
EnemyGun2::EnemyGun2(float SpeedFactor, float Damage) : EnemyGun1(3)
{
	this->SpeedFactor = SpeedFactor;
	damage = Damage;
	sprite.setTexture(TextureClass::get()->retrieveTexture("Enemy_Boss_Gun"));
	SpriteScaleX = 1.0;
	SpriteScaleY = 1.0;
	sprite.setScale(SpriteScaleX, SpriteScaleY);
	sprite.setOrigin(2, 12);
	
	
}

void EnemyGun2::Shoot(sf::Time deltaTime, std::vector<TileSet*>& allAreas)
{
	sf::Vector2f temp;
	Bullet* temp1 = new Bullet(bullet_type, bullet_type2);
	Bullet* temp2 = new Bullet(bullet_type, bullet_type2);
	Bullet* temp3 = new Bullet(bullet_type, bullet_type2);

	bullet_count += 3;
	temp = aim_direction_normalized + sf::Vector2f(0, 0.25);

	DIRECTION.push_back(temp / (float)sqrt(pow(temp.x, 2) + pow(temp.y, 2)));


	DIRECTION.push_back(aim_direction_normalized);
	temp = aim_direction_normalized + sf::Vector2f(0, -0.25);
	DIRECTION.push_back(temp / (float)sqrt(pow(temp.x, 2) + pow(temp.y, 2)));

	bullet_vector.push_back(temp1);
	bullet_vector.push_back(temp2);
	bullet_vector.push_back(temp3);

	for (int i = bullet_count - 2; i <= bullet_count; i++)
	{
		bullet_vector.at(i)->set_bullet_position(sprite.getPosition(), rotation);
		bullet_vector.at(i)->setIsShot(true);
		bullet_vector.at(i)->rotate_sprite(rotation);
	}
	
}


void EnemyGun2::update(sf::Time deltaTime, sf::Vector2f aim_direction, std::vector<TileSet*>& allAreas)
{
	Gun::update(deltaTime, aim_direction, allAreas);
	move(deltaTime, allAreas, SpeedFactor);
	if (status == true)
	{

		if (t2.asSeconds() >= 2.0)
		{

			recoil_count = 1;
			Shoot(deltaTime, allAreas);
			//std::cout << recoil_count << std::endl;
			recoil();

			c2.restart();
		}

		t2 = c2.getElapsedTime();
	}
}