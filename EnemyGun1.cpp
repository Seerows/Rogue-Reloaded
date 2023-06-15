#include "EnemyGun1.h"

EnemyGun1::EnemyGun1(int type, float SpeedFactor, float Damage) : Gun(1, type)
{
	if (type == 1)
	{
		sprite.setTexture(TextureClass::get()->retrieveTexture("Enemy_Pistol"));
		SpriteScaleX = 0.2f;
		SpriteScaleY = 0.2f;
		sprite.setScale(SpriteScaleX, SpriteScaleY);
		sprite.setOrigin(25, 70);
	}

	else if (type == 2)
	{
		sprite.setTexture(TextureClass::get()->retrieveTexture("Enemy_Pistol_2"));
		SpriteScaleX = 1.0;
		SpriteScaleY = 1.0;
		sprite.setScale(SpriteScaleX, SpriteScaleY);
		sprite.setOrigin(8, 10);
	}

	this->SpeedFactor = SpeedFactor;
	damage = Damage;
	status = true;

	if (!ShotBuffer.loadFromFile("Sounds/SideKickShot.wav"))
	{
		std::cout << "Error loading SideKick shot sound." << std::endl;
	}
	ShotSound.setBuffer(ShotBuffer);
	ShotSound.setVolume(10);
}

EnemyGun1::EnemyGun1(int type) :Gun(1, type)
{
	status = true;
	if (!ShotBuffer.loadFromFile("Sounds/SideKickShot.wav"))
	{
		std::cout << "Error loading SideKick shot sound." << std::endl;
	}
	ShotSound.setBuffer(ShotBuffer);
	ShotSound.setVolume(10);
}


void EnemyGun1::set_status(const bool a)
{
	status = a;
}


void EnemyGun1::update(sf::Time deltaTime, sf::Vector2f aim_direction, std::vector<TileSet*>& allAreas)
{
	Gun::update(deltaTime, aim_direction, allAreas);
	move(deltaTime, allAreas, SpeedFactor);
	if (status == true)
	{
		if (t2.asSeconds() >= 1.0)
		{
			recoil_count = 1;
			Shoot(deltaTime, allAreas);
			recoil();
			ShotSound.play();

			c2.restart();
		}

		t2 = c2.getElapsedTime();
	}

}