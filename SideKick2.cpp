#include "SideKick2.h"

SideKick2::SideKick2() : pistol(2, 1.8, 1)
{
	enemy2SpriteCreate();
	enemySpeed = 50;
	spriteSlowValue = 10;
	timer = 0;
	shootingDistance = 100;
	enemyHealth = 100;
}

void SideKick2::enemy2SpriteCreate()
{
	enemySprite.setTexture(TextureClass::get()->retrieveTexture("enemy2IdleDown"));
	enemyHand.setTexture(TextureClass::get()->retrieveTexture("enemy2Hand"));
	enemySprite.setScale(2.25f, 2.25f);
	handLeft = sf::Vector2f(-10, 40);
	handDown = sf::Vector2f(28, 40);
	handRight = sf::Vector2f(30, 40);
	handUp = sf::Vector2f(-8, 40);
	handUpRight = sf::Vector2f(28, 40);
	handUpLeft = sf::Vector2f(-10, 40);
	handDownRight = sf::Vector2f(30, 40);
	handDownLeft = sf::Vector2f(-15, 40);
	handPosition = handDown;

	enemyHand.setPosition(handPosition);
	enemyHand.setScale(1.f, 1.f);
}

void SideKick2::update(sf::Time deltaTime, Player* player, std::vector<TileSet*>& allAreas)
{

	for (int i = 0; i <= pistol.getBulletCount(); i++) {   //for bullet collision
		if (pistol.getBullets().at(i)->get_bullet_sprite().getGlobalBounds().intersects(player->getSprite().getGlobalBounds()) && pistol.getBullets().at(i)->getIsShot()) {
			if (!player->isDodging()) {
				pistol.getBullets().at(i)->setIsShot(false);
				player->takeDamage(0.5f);
			}
		}
	}

	direction.x = player->getSprite().getPosition().x - enemySprite.getPosition().x;  //direction between player and enemy
	direction.y = player->getSprite().getPosition().y - enemySprite.getPosition().y;
	distance = std::sqrt(std::powf(direction.x, 2.f) + std::pow(direction.y, 2.f));

	direction /= distance;  //don't ask this line

	if (distance < 400)
	{
		pistol.set_status(1);  //to start shooting
	}

	else
	{
		pistol.set_status(0); //to stop shooting
	}

	if (distance < 250)    // for the standing animation and also stopping enemy when close to player
	{

		if (angle <= 122.5 && angle > 67.5)   //Up
		{
			enemySprite.setTexture(TextureClass::get()->retrieveTexture("enemy2IdleUp"));
			handPosition = handUp;
		}
		if (angle <= -67.5 && angle > -112.5) //Down
		{
			enemySprite.setTexture(TextureClass::get()->retrieveTexture("enemy2IdleDown"));
			handPosition = handDown;
		}
		if (angle == 180 || angle == -180) //Left
		{
			enemySprite.setTexture(TextureClass::get()->retrieveTexture("enemy2Left0"));
			handPosition = handLeft;
		}
		if (angle > -67.5 && angle <= 12.5) //Right and Down Right
		{
			enemySprite.setTexture(TextureClass::get()->retrieveTexture("enemy2Right0"));
			handPosition = handRight;
			if (angle > -67.5 && angle <= -27.5) {
				enemySprite.setTexture(TextureClass::get()->retrieveTexture("enemy2IdleDownRight"));
				handPosition = handDownRight;
			}
		}
		if ((angle <= -112.5 && angle > -180) || (angle < 180 && angle > 167.5))  //Down Left 
		{
			enemySprite.setTexture(TextureClass::get()->retrieveTexture("enemy2Left0"));
			handPosition = handLeft;
			if (angle > -152.5 && angle < -112.5) {
				enemySprite.setTexture(TextureClass::get()->retrieveTexture("enemy2IdleDownLeft"));
				handPosition = handDownLeft;
			}
		}
		if (angle > 12.5 && angle <= 67.5) {  //Up Right
			enemySprite.setTexture(TextureClass::get()->retrieveTexture("enemy2IdleUpRight"));
			handPosition = handUpRight;
		}
		if (angle <= 167.5 && angle > 112.5) { //Up Left
			enemySprite.setTexture(TextureClass::get()->retrieveTexture("enemy2IdleUpLeft"));
			handPosition = handUpLeft;
		}
		enemySprite.setTextureRect(sf::IntRect(0, 0, enemySprite.getTexture()->getSize().x, enemySprite.getTexture()->getSize().y));
		enemySpeed = 0;
		distance = 0;
	}
	if (distance > 250)
	{
		enemySpeed = 50;
	}
	angle = atan2f(-1 * (float)direction.y, (float)direction.x);  //angle between player and enemy
	angle = angle * 180 * (7.f / 22);

	if (distance >= 250) //walking animation 
	{
		if (angle <= 122.5 && angle > 67.5)               //Up
		{
			enemySprite.setTexture(TextureClass::get()->retrieveTexture("enemy2Up" + std::to_string(upCount / spriteSlowValue % 6)));
			upCount++;
			enemySprite.setTextureRect(sf::IntRect(0, 0, enemySprite.getTexture()->getSize().x, enemySprite.getTexture()->getSize().y));
			handPosition = handUp;
		}
		else if (angle <= -67.5 && angle > -112.5)         //Down
		{
			enemySprite.setTexture(TextureClass::get()->retrieveTexture("enemy2Down" + std::to_string(downCount / spriteSlowValue % 6)));
			downCount++;
			enemySprite.setTextureRect(sf::IntRect(0, 0, enemySprite.getTexture()->getSize().x, enemySprite.getTexture()->getSize().y));
			handPosition = handDown;
		}

		else if (angle == 180 || angle == -180)       //Left
		{
			enemySprite.setTexture(TextureClass::get()->retrieveTexture("enemy2Left" + std::to_string(leftCount / spriteSlowValue % 6)));
			leftCount++;
			enemySprite.setTextureRect(sf::IntRect(0, 0, enemySprite.getTexture()->getSize().x, enemySprite.getTexture()->getSize().y));
			handPosition = handLeft;
		}

		else if (angle > -67.5 && angle <= 12.5)            //Right and Down Right
		{
			enemySprite.setTexture(TextureClass::get()->retrieveTexture("enemy2Right" + std::to_string(rightCount / spriteSlowValue % 6)));
			rightCount++;
			handPosition = handRight;
			enemySprite.setTextureRect(sf::IntRect(0, 0, enemySprite.getTexture()->getSize().x, enemySprite.getTexture()->getSize().y));
			if (angle > -67.5 && angle <= -27.5)
			{
				enemySprite.setTexture(TextureClass::get()->retrieveTexture("enemy2Right" + std::to_string(rightCount / spriteSlowValue % 6)));
				enemySprite.setTextureRect(sf::IntRect(0, 0, enemySprite.getTexture()->getSize().x, enemySprite.getTexture()->getSize().y));
				handPosition = handDownRight;
			}
		}
		else if ((angle <= -112.5 && angle > -180) || (angle < 180 && angle > 167.5))  //Down Left 
		{
			enemySprite.setTexture(TextureClass::get()->retrieveTexture("enemy2Left" + std::to_string(leftCount / spriteSlowValue % 6)));
			leftCount++;
			enemySprite.setTextureRect(sf::IntRect(0, 0, enemySprite.getTexture()->getSize().x, enemySprite.getTexture()->getSize().y));
			handPosition = handLeft;
			if (angle > -152.5 && angle < -112.5) {
				enemySprite.setTexture(TextureClass::get()->retrieveTexture("enemy2Left" + std::to_string(leftCount / spriteSlowValue % 6)));
				//leftCount++;
				enemySprite.setTextureRect(sf::IntRect(0, 0, enemySprite.getTexture()->getSize().x, enemySprite.getTexture()->getSize().y));
				handPosition = handDownLeft;
			}
		}
		else if (angle > 12.5 && angle <= 67.5) {  //Up Right
			enemySprite.setTexture(TextureClass::get()->retrieveTexture("enemy2UpRight" + std::to_string(upRightCount / spriteSlowValue % 6)));
			upRightCount++;
			enemySprite.setTextureRect(sf::IntRect(0, 0, enemySprite.getTexture()->getSize().x, enemySprite.getTexture()->getSize().y));
			handPosition = handUpRight;
		}
		else if (angle <= 167.5 && angle > 112.5) {
			enemySprite.setTexture(TextureClass::get()->retrieveTexture("enemy2UpLeft" + std::to_string(upLeftCount / spriteSlowValue % 6)));
			upLeftCount++;
			enemySprite.setTextureRect(sf::IntRect(0, 0, enemySprite.getTexture()->getSize().x, enemySprite.getTexture()->getSize().y));
			handPosition = handUpLeft;
		}

	}
	sf::Vector2f timed_movement = direction * deltaTime.asSeconds() * enemySpeed;

	// for wall collision
	bool enemy_contained = false, contained_UL = false, contained_UR = false, contained_DL = false, contained_DR = false;
	bool bullet_contained = false;
	sf::Vector2f playerPos = enemySprite.getPosition();


	for (int i = 0; i < allAreas.size(); i++) {
		contained_UL = contained_UL || allAreas[i]->getGlobalBounds().contains(playerPos + timed_movement);
		contained_UR = contained_UR || allAreas[i]->getGlobalBounds().contains(playerPos + timed_movement + sf::Vector2f(48, 0));
		contained_DR = contained_DR || allAreas[i]->getGlobalBounds().contains(playerPos + timed_movement + sf::Vector2f(48, 70));
		contained_DL = contained_DL || allAreas[i]->getGlobalBounds().contains(playerPos + timed_movement + sf::Vector2f(0, 70));
	}
	enemy_contained = contained_UL && contained_UR && contained_DR && contained_DL;

	if (!enemy_contained) {
		timed_movement = sf::Vector2f(0, 0);
	}

	if (enemyHealth <= 0) //Death Animation
	{
		enemySprite.setTexture(TextureClass::get()->retrieveTexture("enemy2Death" + std::to_string(deathCount / 7 % 6)));
		enemySprite.setTextureRect(sf::IntRect(0, 0, enemySprite.getTexture()->getSize().x, enemySprite.getTexture()->getSize().y));
		deathCount++;
		if (deathCount / 7 % 6 == 5) {
			isDead = true;
		}
		timed_movement = sf::Vector2f(0, 0);
		pistol.set_status(0);
	}

	enemySprite.move(timed_movement);
	enemyHand.move(timed_movement);
	enemyHand.setPosition(enemySprite.getPosition() + handPosition);
	pistol.update(deltaTime, direction, allAreas);
	pistol.getsprite().setPosition(enemyHand.getPosition() + sf::Vector2f(enemyHand.getTexture()->getSize().x / 2.f, enemyHand.getTexture()->getSize().y / 2.f) + sf::Vector2f(3.f, -3.f));

}

void SideKick2::render(sf::RenderWindow* window)
{
	if (!isDead) {
		if (enemyHealth > 0) {
			window->draw(pistol.getsprite());
		}

		if (angle <= 122.5 && angle > 67.5 && enemyHealth > 0) { window->draw(enemyHand); }
		window->draw(enemySprite);
		if (!(angle <= 122.5 && angle > 67.5) && enemyHealth > 0) { window->draw(enemyHand); }
		for (int i = 0; i <= pistol.getBulletCount(); i++) {
			if (pistol.getBullets().at(i)->getIsShot()) {
				window->draw(pistol.getBullets().at(i)->get_bullet_sprite());
			}
		}
	}

}

