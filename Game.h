#pragma once
#include <fstream>
#include "SideKick2.h"
#include "SideKick1.h"
#include "Boss.h"
#include "Player.h"
#include "TextureClass.h"
#include "TileSet.h"
#include "HUD.h"
#include "ItemDrop.h"

class Game {

private:

	sf::RenderWindow* window;
	sf::Event event;
	Player player;
	sf::View view;

	HUD hud;

	TileSet startingArea, startingAreaWall;
	TileSet SA_bridge, SA_bridgeWall;
	TileSet initialArea, initialAreaWall;
	TileSet IA_bridge, IA_bridgeWall;
	TileSet middleArea, middleAreaWall;
	TileSet MA_bridge, MA_bridgeWall;
	TileSet finalArea, finalAreaWall;

	std::vector<TileSet*> allAreas;
	std::vector<TileSet*> allWalkableAreas;
	std::vector<TileSet*> allWalls;

	bool enteredIA, enteredMA, enteredFA;
	bool IA_cleared, MA_cleared, FA_cleared;
	std::vector<bool> status;

	std::vector<Enemy*> enemies;
	sf::FloatRect Rect;
	ItemDrop item;

	bool Lost, Won;
	sf::Sprite Result, Continue;
	sf::Font ResultFont;
	sf::Text ResultText;

	bool Exit;

	std::string userName;

	int numberOfEnemiesKilled;
	int score;
	bool scoreCalculated;

	void calculateScore();
	void enemyUpdate(sf::Time deltaTime);
	void processEvents();
	void update(sf::Time deltaTime);
	void render();


public:
	Game(sf::RenderWindow* window, std::string userName);
	void run();

};
