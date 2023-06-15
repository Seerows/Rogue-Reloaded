#include "PlayerGun2.h"

PlayerGun2::PlayerGun2(int capacity, int Tcapacity, float SpeedFactor, float Damage) : PlayerGun1(capacity, 2, 2)
{
	sprite.setTexture(TextureClass::get()->retrieveTexture("SMG"));
	sprite.setOrigin(9, 10);
	SpriteScaleX = 0.2f;
	SpriteScaleY = 0.2f;
	sprite.setScale(SpriteScaleX, SpriteScaleY);
	this->SpeedFactor = SpeedFactor;
	damage = Damage;

	count = 0;
	recoil_count = 0;
	this->Tcapacity = Tcapacity;
	Total_bullets_fired = 0;
	this->capacity = capacity;
	reload_check = false;
	leftclicked = false;
	rightclicked = false;
	check = false;
	emptycheck = false;
	TemporaryCapacity = (Tcapacity - capacity) - Total_bullets_fired;
	text.setPosition(100, 100);
	BulletsInMag = capacity;

	if (!ShotBuffer.loadFromFile("Sounds/SmgShot.wav"))
	{
		std::cout << "Error loading smg shot sound." << std::endl;
	}
	ShotSound.setBuffer(ShotBuffer);
}

void PlayerGun2::update(sf::Time deltaTime, sf::Vector2f aim_direction, std::vector<TileSet*>& allAreas)
{
	Gun::update(deltaTime, aim_direction, allAreas);

	if (check == false)
	{
		TextToDisplay = std::to_string(BulletsInMag - bullet_vector.size()) + " / " + std::to_string(TemporaryCapacity);
	}
	if (c1.getElapsedTime().asSeconds() > 2)
	{
		check = false;
		TextToDisplay = std::to_string(BulletsInMag - bullet_vector.size()) + " / " + std::to_string(TemporaryCapacity);
	}

	if (reload_check > 0)
		t1 = c1.getElapsedTime();
	if (clk.getElapsedTime().asSeconds() >= 0.18)
	{
		if (leftclicked)
		{
			if ((t1.asSeconds() == 0.0 && reload_check == 0) || (t1.asSeconds() >= 1.5f && reload_check > 0))//amendment
			{//amendment

				recoil_count = 1;


				if (Total_bullets_fired < Tcapacity)
				{
					if (bullet_vector.size() < capacity) {
						Total_bullets_fired++;

						Shoot(deltaTime, allAreas);
						ShotSound.play();
					}
					else {
						DFsound.play();
					}
				}


				recoil();
				clk.restart();

			}

		}

	}
	move(deltaTime, allAreas, SpeedFactor);
}