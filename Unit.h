#pragma once
#include <SFML/Graphics.hpp>

class Unit {

public:
	virtual void render(sf::RenderWindow* window) = 0;
	virtual sf::Sprite& getSprite() = 0;

};

