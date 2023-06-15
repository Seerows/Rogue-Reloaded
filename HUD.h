#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "TextureClass.h"
#include "PlayerGun1.h"

class HUD{

private:
	sf::Vector2i health_sprite_size;
	std::vector<sf::Sprite> health_sprite_vector;

	sf::Sprite reload, reload_bg;
	sf::Sprite equipped_gun;
	sf::Text bullet_counter;

	float numOfHearts;
	bool proxy;

public:
	HUD();
	void hudUpdate(float health, sf::View& view, bool reloading, PlayerGun1* gun);
	void hudRender(sf::RenderWindow* window);

};

