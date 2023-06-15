#include "ItemDrop.h"

ItemDrop::ItemDrop() {
	for (int i = 0; i < 5; i++) {
		items.push_back(sf::Sprite(TextureClass::get()->retrieveTexture("playerHealth")));
	}
}

void ItemDrop::setPosition(std::vector<TileSet*>& allAreas) {
	items.at(0).setPosition(allAreas.at(2)->getPosition() + sf::Vector2f(19.2 * 48.f, 19.2 * 48.f));
	items.at(1).setPosition(allAreas.at(4)->getPosition() + sf::Vector2f(0.5 * 48.f, 19.2 * 48.f));
	items.at(2).setPosition(allAreas.at(4)->getPosition() + sf::Vector2f(19.2 * 48.f, 19.2 * 48.f));
	items.at(3).setPosition(allAreas.at(6)->getPosition() + sf::Vector2f(0.5 * 48.f, 0.5 * 48.f));
	items.at(4).setPosition(allAreas.at(6)->getPosition() + sf::Vector2f(19.2 * 48.f, 0.5 * 48.f));
}

void ItemDrop::itemUpdate(Player* player) {
	for (int i = 0; i < items.size(); i++) {
		if (player->getSprite().getGlobalBounds().intersects(items.at(i).getGlobalBounds())) {
			(*player)++;
			items.erase(items.begin() + i);
		}
	}
}

void ItemDrop::itemRender(sf::RenderWindow* window) {
	for (int i = 0; i < items.size(); i++) {
		window->draw(items.at(i));
	}
}
