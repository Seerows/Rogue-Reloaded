#include "Gun.h"

Gun::Gun(int type, int type2)
{
	damage = 1;
	bullet_type = type;
	bullet_type2 = type2;
	Bullet bullet(type, type2);
	gunspeed = 1;

	bullet_count = -1;
	this->SpeedFactor = 1;

	dx = 0.0;
	dy = 0.0;
	rotation = 0.0;
	recoil_count = 0;
	bullet.set_maxspeed(2);
}

void Gun::update(sf::Time deltaTime, sf::Vector2f aim_direction, std::vector<TileSet*>& allAreas)
{
	aim_direction_normalized = aim_direction / (float)sqrt(pow(aim_direction.x, 2) + pow(aim_direction.y, 2));
	rotation = std::atan2f(aim_direction_normalized.y, aim_direction_normalized.x) * (180.f / ((float)std::atan(1) * 4));
	sprite.setRotation(rotation);

	if (rotation > 112 || rotation < -112)
	{
		sprite.setScale(SpriteScaleX, -SpriteScaleY);
	}
	else
	{
		sprite.setScale(SpriteScaleX, SpriteScaleY);
	}
}

void Gun::recoil()
{
	if (recoil_count >= 11) {
		if (sprite.getRotation() >= 345 && sprite.getRotation() < 360)
		{
			sprite.rotate(12.f);
		}
	}
	else if (recoil_count != 0)
	{
		recoil_count++;

		sprite.rotate(-6.f);
	}
}
void Gun::move(sf::Time deltaTime, std::vector<TileSet*>& allAreas, float SpeedFactor)
{
	for (int i = 0; i <= bullet_count; i++) {
		if (bullet_vector.at(i)->getIsShot()) {
			bool contained = false;
			for (int j = 0; j < allAreas.size(); j++) {
				contained = contained || allAreas.at(j)->getGlobalBounds().contains(bullet_vector.at(i)->get_bullet_sprite().getPosition());
			}

			if (contained) {
				bullet_vector.at(i)->shoot(DIRECTION.at(i), deltaTime, SpeedFactor);
			}
			else {
				bullet_vector.at(i)->setIsShot(false);
			}
		}

	}


}

std::vector<Bullet*>& Gun::getBullets() {
	return bullet_vector;
}
//
int Gun::getBulletCount() const {
	return bullet_count;
}

int Gun::get_bullet_type() const
{
	return bullet_type;
}

sf::Sprite& Gun::getsprite()
{
	return sprite;
}

//
//bool Gun::isReloading() const {
//	return check;
//}
//
void Gun::Shoot(sf::Time deltaTime, std::vector<TileSet*>& allAreas) {

	Bullet* temp = new Bullet(bullet_type, bullet_type2);
	bullet_count++;

	DIRECTION.push_back(aim_direction_normalized);
	bullet_vector.push_back(temp);
	bullet_vector.at(bullet_count)->set_bullet_position(sprite.getPosition(), rotation);

	bullet_vector.at(bullet_count)->setIsShot(true);
	bullet_vector.at(bullet_count)->rotate_sprite(rotation);

}

float Gun::getDamage() {
	return damage;
}

Gun::~Gun() {
	for (int i = 0; i <= bullet_count; i++) {
		delete bullet_vector.at(i);
	}
}
