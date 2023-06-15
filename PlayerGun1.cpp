#include "PlayerGun1.h"

PlayerGun1::PlayerGun1(int capacity, int Tcapacity, float SpeedFactor, float Damage) :Gun(2, 1), text("abcd", font, 30)
{
	this->capacity = capacity;
	count = 0;
	recoil_count = 0;
	reload_check = false;
	leftclicked = false;
	rightclicked = false;
	this->Tcapacity = Tcapacity;
	Total_bullets_fired = 0;
	check = false;
	emptycheck = false;
	sprite.setTexture(TextureClass::get()->retrieveTexture("Player_Pistol"));
	SpriteScaleX = 0.2f;
	SpriteScaleY = 0.2f;
	sprite.setOrigin(25.f, 70.f);
	font.loadFromFile("Fonts/Renegade Pursuit.otf");
	TemporaryCapacity = (Tcapacity - capacity) - Total_bullets_fired;
	BulletsInMag = capacity;
	this->SpeedFactor = SpeedFactor;
	damage = Damage;

	if (!ShotBuffer.loadFromFile("Sounds/RevolverShot.wav"))
	{
		std::cout << "Error loading revolver shot sound." << std::endl;
	}
	ShotSound.setBuffer(ShotBuffer);

	if (!DFbuffer.loadFromFile("Sounds/DryFire.wav"))
	{
		std::cout << "Error loading dry fire sound." << std::endl;
	}
	DFsound.setBuffer(DFbuffer);

}


PlayerGun1::PlayerGun1(int capacity, int type1, int type2) :Gun(type1, type2), text("abcd", font, 30)
{
	this->capacity = capacity;
	count = 0;
	recoil_count = 0;
	reload_check = false;
	leftclicked = false;
	rightclicked = false;
	Tcapacity = 40;
	Total_bullets_fired = 0;
	check = false;
	emptycheck = false;
	TemporaryCapacity = (Tcapacity - capacity) - Total_bullets_fired;
	font.loadFromFile("Fonts/Renegade Pursuit.otf");
	text.setPosition(100, 100);
	BulletsInMag = capacity;

	if (!DFbuffer.loadFromFile("Sounds/DryFire.wav"))
	{
		std::cout << "Error loading dry fire sound." << std::endl;
	}
	DFsound.setBuffer(DFbuffer);
}

void PlayerGun1::handle_keyboard_input(sf::Keyboard::Key key, bool IsPressed)
{

	if (key == sf::Keyboard::R && TemporaryCapacity > 0)
	{
		if (bullet_vector.size() == 0 && Total_bullets_fired != Tcapacity)
		{
			//std::cout << "Magazine at full capacity." << std::endl;
		}
		else if (Total_bullets_fired == Tcapacity)
		{
			BulletsInMag = 0;
			TemporaryCapacity = 0;
			DFsound.play();
		}
		else
		{
			check = true;
			
			if (TemporaryCapacity <= bullet_vector.size())
			{
				BulletsInMag = (capacity - int(bullet_vector.size())) + TemporaryCapacity;
				TemporaryCapacity = 0;
			}
			else
			{
				BulletsInMag = capacity;
				TemporaryCapacity -= int(bullet_vector.size());
			}

			c1.restart();
			reload_check++;

		}
		for (int i = 0; i <= bullet_count; i++) {
			delete bullet_vector.at(i);
		}
		bullet_vector.clear();
		bullet_count = -1;
		count = 0;
		DIRECTION.clear();
	}

}

void PlayerGun1::handle_left_mouse_input(bool IsClicked)
{
	leftclicked = IsClicked;
}

void PlayerGun1::handle_right_mouse_input(bool IsClicked)
{
	rightclicked = IsClicked;
}

int PlayerGun1::getCapacity() const {
	return capacity;
}


bool PlayerGun1::isReloading() const {
	return check;
}

void PlayerGun1::setclick(bool a)
{
	leftclicked = a;
}

int PlayerGun1::getBulletsInMag() const
{
	return BulletsInMag - int(bullet_vector.size());
}

int PlayerGun1::getTemporaryCapacity() const
{
	return TemporaryCapacity;
}


void PlayerGun1::update(sf::Time deltaTime, sf::Vector2f aim_direction, std::vector<TileSet*>& allAreas)
{
	Gun::update(deltaTime,  aim_direction, allAreas);
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
	if (leftclicked)
	{
		if ((t1.asSeconds() == 0.0 && reload_check == 0) || (t1.asSeconds() >= 2.0 && reload_check > 0))
		{
			leftclicked = false;

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

		}
	}
	move(deltaTime, allAreas, SpeedFactor);

}

void PlayerGun1::recoil()
{
	if (bullet_vector.size() < capacity)
	{
		if (bullet_vector.size() == capacity)
			count++;

		if (Total_bullets_fired < Tcapacity)
		{
			Gun::recoil();
		}
	}

	if (count > 0)
	{
		if (Total_bullets_fired < Tcapacity)
		{
			Gun::recoil();
		}
		count = 0;
	}
}


sf::Time PlayerGun1::getTime() const
{
	return t1;
}

sf::Time PlayerGun1::getClockTime()
{
	return c1.getElapsedTime();
}

bool PlayerGun1::getReloadCheck() const
{
	return reload_check;
}
int PlayerGun1::getTcapacity() const
{
	return Tcapacity;
}

int PlayerGun1::getBulletsFired() const
{
	return Total_bullets_fired;
}
void PlayerGun1::incrementBulletsFired()
{
	Total_bullets_fired++;
}

sf::Text& PlayerGun1::getText()
{
	return text;
}

int PlayerGun1::getVectorSize() const 
{
	return int(bullet_vector.size());
}

std::string& PlayerGun1::getString() {
	return TextToDisplay;
}

void PlayerGun1::setCheck(bool a)
{
	check = a;
}

void PlayerGun1::setTime(sf::Time time)
{
	t1 = time;
}

bool PlayerGun1::getclick() const
{
	return leftclicked;
}

int PlayerGun1::getRemainingBullets() {
	return (Tcapacity - Total_bullets_fired);
}