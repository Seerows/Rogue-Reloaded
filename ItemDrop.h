#pragma once
#include "SFML/Graphics.hpp"
#include "Player.h"

class Player;

class ItemDrop
{

private:
	std::vector<sf::Sprite> items;

public:
	ItemDrop();
	void setPosition(std::vector<TileSet*>& allAreas);
	void itemUpdate(Player* player);
	void itemRender(sf::RenderWindow* window);

};
