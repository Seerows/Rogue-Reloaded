#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "TextureClass.h"
#include "Game.h"
#include "Menu.h"

int main() {

	sf::RenderWindow window;
	window.setFramerateLimit(60);
	window.create(sf::VideoMode(1920, 1080), "My window", sf::Style::Fullscreen);
	window.setVerticalSyncEnabled(true);
	window.setMouseCursorVisible(false);
	
	sf::Texture logo_texture;
	sf::Sprite logo;

	logo_texture.loadFromFile("Texture/Menu/CompanyLogo2.png");
	logo.setTexture(logo_texture);

	logo.setPosition(360, 0);

	window.clear();
	window.draw(logo);
	window.display();

	TextureClass texture;

	while (1) {
		Menu mo(&window);
		mo.run();
		
		Game go(&window, mo.getInputUser2Name());
		go.run();
	}
	

	std::cout << "Complete\n";
	return 0;
}

