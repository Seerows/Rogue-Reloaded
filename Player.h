#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <cmath>
#include "TextureClass.h"
#include "PlayerGun1.h"
#include "PlayerGun2.h"
#include "TileSet.h"
#include "Unit.h"
#include "Enemy.h"
#include "ItemDrop.h"

class Enemy;

class Player : public Unit {

private:
	float health;
	int lives;
	bool damageEnabled;

	bool movingRight, movingLeft, movingUp, movingDown, dodging;
	bool pointingRight, pointingLeft, pointingUp, pointingDown, pointingUpRight, pointingUpLeft;
	bool pointingDownRight, pointingDownLeft;
	float angle, PlayerSpeed;
	int mouseCount;
	sf::Vector2i delta, total_delta, windowCenter;
	sf::Vector2f aim_direction;

	sf::Vector2f sum;
	float idlePositionY;
	int movingCount, idleCount, dodgingCount, frames, deathCount;
	sf::Vector2f handPosition, handLeft, handDown, handRight, handUp, handUpRight, handUpLeft;

	std::string file_path;
	sf::Texture texture, shadow;
	sf::Sprite sprite, sprite_shadow, sprite_hand;

	sf::Vector2f timed_movement, timed_view_movement;

	bool isShaking, isHealing;
	int shakeCount;
	sf::View originalView;

	bool isDead, gameOver;

	std::vector<bool> status;	//gameOver, reloading...

	int gunIndex, scrollCount;
	PlayerGun1 pistol;
	PlayerGun2 smg;
	std::vector<PlayerGun1*> allGuns;
	sf::Vector2f gunPosition;

public:
	Player();
	float getHealth() const;
	void playerKeyboardInput(sf::Keyboard::Key key, bool isPressed);
	void playerMouseInput(sf::RenderWindow* window);
	void playerClickInput(sf::Mouse::Button button, bool isPressed);
	void playerScrollInput(float delta);
	std::vector<bool> update(sf::Time deltaTime, sf::View& view, std::vector<Enemy*>* enemy_vector, std::vector<TileSet*>& allAreas);
	void playerMovingUpdate(sf::Vector2f& movement, sf::Vector2f& view_movement, sf::Time deltaTime);
	void playerIdleUpdate();
	void render(sf::RenderWindow* window);
	void takeDamage(float damage);
	sf::Sprite& getSprite();
	std::vector<PlayerGun1*>* getAllGuns();
	PlayerGun1* getEquippedGun() const ;
	bool hasEnteredArea(TileSet* area);
	bool isDodging() const;
	void operator++(int);
	
};