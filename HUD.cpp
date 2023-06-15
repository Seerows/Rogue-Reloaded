#include "HUD.h"

HUD::HUD() {
	
	for (int i = 0; i < 6; i++) {
		health_sprite_vector.push_back(sf::Sprite(TextureClass::get()->retrieveTexture("playerHealth")));
		health_sprite_vector.at(i).setScale(1.7f, 1.7f);
	}
	
	numOfHearts = 6;
	health_sprite_size = sf::Vector2i(TextureClass::get()->retrieveTexture("playerHealth").getSize());
	proxy = false;
}

void HUD::hudUpdate(float health, sf::View& view, bool reloading, PlayerGun1* gun) {

	sf::Vector2f view_center = view.getCenter();
	sf::Vector2f view_size = view.getSize();

	sf::Vector2f delta = view_center - view_size/2.2f;
	
	for (float i = 0; i < ceil(numOfHearts); i++) {
		health_sprite_vector.at(int(i)).setPosition(sf::Vector2f(delta.x + i * 2.1f * health_sprite_size.x, delta.y));
	}
	
	numOfHearts = health;

	reload_bg.setTexture(TextureClass::get()->retrieveTexture("Reload_BG"));
	reload_bg.setPosition(view_center + sf::Vector2f(view_size.x/2.6f, view_size.y/3.6f));
	reload_bg.setScale(0.16f, 0.25f);

	reload.setTexture(TextureClass::get()->retrieveTexture("Reload"));
	reload.setOrigin(sf::Vector2f(reload.getTexture()->getSize()) / 2.1f);
	reload.setPosition(reload_bg.getPosition() + sf::Vector2f(reload_bg.getTexture()->getSize().x * reload_bg.getScale().x, reload_bg.getTexture()->getSize().y * reload_bg.getScale().y) / 2.f);
	reload.setScale(0.7f, 0.7f);

	if (reloading) {
		proxy = true;
	}

	if (reloading){
		reload.rotate(3.f);
	}
	else if(proxy){
		reload.setRotation(0.f);
		proxy = false;
	}

	equipped_gun.setTexture(*(gun->getsprite().getTexture()), true);
	equipped_gun.setScale(gun->getsprite().getScale());

	if (equipped_gun.getScale().y < 0) {
		equipped_gun.setScale(sf::Vector2f(equipped_gun.getScale().x, equipped_gun.getScale().y * -1));
	}

	equipped_gun.setPosition(view_center + sf::Vector2f(view_size.x / 3.6f, view_size.y / 3.2f));
	equipped_gun.scale(2.f, 2.f);

	bullet_counter.setFont(*gun->getText().getFont());
	bullet_counter.setString(gun->getString());
	bullet_counter.setPosition(view_center + sf::Vector2f(view_size.x / 3.6f, view_size.y / 2.7f));

}

void HUD::hudRender(sf::RenderWindow* window) {

	for (int i = 0; i<numOfHearts; i++) {

		if (numOfHearts-i == 0.5) {
			health_sprite_vector.at(i).setTextureRect(sf::IntRect(0, 0, health_sprite_size.x / 2, health_sprite_size.y));
		}

		window->draw(health_sprite_vector.at(i));
		health_sprite_vector.at(i).setTextureRect(sf::IntRect(sf::Vector2i(0, 0), health_sprite_size));
	}

	window->draw(reload_bg);
	window->draw(reload);
	window->draw(equipped_gun);
	window->draw(bullet_counter);

}
