#pragma once
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "Bullet.h"
#include <math.h>
#include <cmath>
#include "TextureClass.h"
#include "TileSet.h"


class Gun {


protected:
	float gunspeed;

	float SpeedFactor;
	int recoil_count;
	sf::SoundBuffer ShotBuffer;
	sf::Sound ShotSound;

	sf::Time t1;
	sf::Clock c1;
	int bullet_type;
	int bullet_type2;
	float SpriteScaleX;
	float SpriteScaleY;
	float damage;

	int bullet_count;

	sf::Vector2f gunpos;
	sf::Vector2f mousepos;
	float dx;
	float dy;
	float rotation;
	sf::Vector2f aim_direction;
	sf::Vector2f aim_direction_normalized;

	std::vector<sf::Vector2f> DIRECTION;

	sf::Sprite sprite;
	std::vector<Bullet*> bullet_vector;

public:
	Gun(int type, int type2);

	virtual void update(sf::Time deltaTime, sf::Vector2f aim_direction, std::vector<TileSet*>& allAreas);
	sf::Sprite& getsprite();
	std::vector<Bullet*>& getBullets();
	int getBulletCount() const;
	int get_bullet_type() const;
	virtual void Shoot(sf::Time deltaTime, std::vector<TileSet*>& allAreas);
	virtual void move(sf::Time deltaTime, std::vector<TileSet*>& allAreas, float SpeedFactor);
	void recoil();
	float getDamage();
	~Gun();

};