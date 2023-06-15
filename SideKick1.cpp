#include "SideKick1.h"

SideKick1::SideKick1() : pistol(1, 2, 0.5)
{
	enemySpriteCreate();
	enemySpeed = 50;
	spriteSlowValue = 10;
	timer = 0;
	shootingDistance = 150;
}

void SideKick1::enemySpriteCreate()
{
	enemySprite.setTexture(TextureClass::get()->retrieveTexture("enemyIdleDown"));
	enemyHand.setTexture(TextureClass::get()->retrieveTexture("enemyHand"));
	enemySprite.setScale(2.5f, 2.5f);
	handLeft = sf::Vector2f(-20, 30);
	handDown = sf::Vector2f(27, 30);
	handRight = sf::Vector2f(27, 30);
	handUp = sf::Vector2f(-20, 30);
	handUpRight = sf::Vector2f(27, 30);
	handUpLeft = sf::Vector2f(-20, 30);
	handDownRight = sf::Vector2f(27, 30);
	handDownLeft = sf::Vector2f(-20, 30);
	handPosition = handDown;

	enemyHand.setPosition(handPosition);
	enemyHand.setScale(1.f, 1.f);
}

void SideKick1::update(sf::Time deltaTime, Player* player, std::vector<TileSet*>& allAreas)
{

	for (int i = 0; i <= pistol.getBulletCount(); i++) {   //for bullet collision
		if (pistol.getBullets().at(i)->get_bullet_sprite().getGlobalBounds().intersects(player->getSprite().getGlobalBounds()) && pistol.getBullets().at(i)->getIsShot()) {
			if (!player->isDodging()) {
				pistol.getBullets().at(i)->setIsShot(false);
				player->takeDamage(0.5f);
			}
		}
	}

	direction.x = player->getSprite().getPosition().x - enemySprite.getPosition().x; //direction between player and enemy
	direction.y = player->getSprite().getPosition().y - enemySprite.getPosition().y;
	distance = std::sqrt(std::powf(direction.x, 2.f) + std::pow(direction.y, 2.f));

	direction /= distance;

	if (distance < 400)
	{
		pistol.set_status(1);  //to start shooting
	}

	else
	{
		pistol.set_status(0); //to stop shooting
	}

	if (distance < 150)		// for the standing animation and also stopping enemy when close to player
	{
		if (angle <= 122.5 && angle > 67.5)   //Up
		{
			enemySprite.setTexture(TextureClass::get()->retrieveTexture("enemyIdleUp"));
			enemySprite.setTextureRect(sf::IntRect(0, 0, enemySprite.getTexture()->getSize().x, enemySprite.getTexture()->getSize().y));
			handPosition = handUp;
		}
		if (angle <= -67.5 && angle > -112.5) //Down
		{
			enemySprite.setTexture(TextureClass::get()->retrieveTexture("enemyIdleDown"));
			enemySprite.setTextureRect(sf::IntRect(0, 0, enemySprite.getTexture()->getSize().x, enemySprite.getTexture()->getSize().y));
			handPosition = handDown;
		}
		if (angle == 180 || angle == -180) //Left
		{
			enemySprite.setTexture(TextureClass::get()->retrieveTexture("enemyLeft0"));
			enemySprite.setTextureRect(sf::IntRect(0, 0, enemySprite.getTexture()->getSize().x, enemySprite.getTexture()->getSize().y));
			handPosition = handLeft;
		}
		if (angle > -67.5 && angle <= 12.5) //Right and Down Right
		{
			enemySprite.setTexture(TextureClass::get()->retrieveTexture("enemyLeft0"));
			enemySprite.setTextureRect(sf::IntRect(enemySprite.getTexture()->getSize().x, 0, enemySprite.getTexture()->getSize().x * -1, enemySprite.getTexture()->getSize().y));
			handPosition = handRight;
			if (angle > -67.5 && angle <= -27.5) {
				enemySprite.setTexture(TextureClass::get()->retrieveTexture("enemyLeft0"));
				enemySprite.setTextureRect(sf::IntRect(enemySprite.getTexture()->getSize().x, 0, enemySprite.getTexture()->getSize().x * -1, enemySprite.getTexture()->getSize().y));
				handPosition = handDownRight;
			}
		}
		if ((angle <= -112.5 && angle > -180) || (angle < 180 && angle > 167.5))  //Down Left 
		{
			enemySprite.setTexture(TextureClass::get()->retrieveTexture("enemyLeft0"));
			handPosition = handLeft;
			enemySprite.setTextureRect(sf::IntRect(0, 0, enemySprite.getTexture()->getSize().x, enemySprite.getTexture()->getSize().y));
			if (angle > -152.5 && angle < -112.5) {
				enemySprite.setTexture(TextureClass::get()->retrieveTexture("enemyLeft0"));
				enemySprite.setTextureRect(sf::IntRect(0, 0, enemySprite.getTexture()->getSize().x, enemySprite.getTexture()->getSize().y));
				handPosition = handDownLeft;
			}
		}
		if (angle > 12.5 && angle <= 67.5) {  //Up Right
			enemySprite.setTexture(TextureClass::get()->retrieveTexture("enemyUpLeft0"));
			enemySprite.setTextureRect(sf::IntRect(enemySprite.getTexture()->getSize().x, 0, enemySprite.getTexture()->getSize().x * -1, enemySprite.getTexture()->getSize().y));
			handPosition = handUpRight;
		}
		if (angle <= 167.5 && angle > 112.5) { //Up Left
			enemySprite.setTexture(TextureClass::get()->retrieveTexture("enemyUpLeft0"));
			enemySprite.setTextureRect(sf::IntRect(0, 0, enemySprite.getTexture()->getSize().x, enemySprite.getTexture()->getSize().y));
			handPosition = handUpLeft;
		}

		enemySpeed = 0.f;
		distance = 0.f;
	}

	if (distance >= 150)
	{
		enemySpeed = 50;
	}

	angle = atan2f(-1 * (float)direction.y, (float)direction.x);  //angle between player and enemy
	angle = angle * 180 * (7.0 / 22);

	if (distance >= 150) //walking animation 
	{
		if (angle <= 122.5 && angle > 67.5)               //Up
		{
			enemySprite.setTexture(TextureClass::get()->retrieveTexture("enemyUp" + std::to_string(upCount / spriteSlowValue % 4)));
			upCount++;
			enemySprite.setTextureRect(sf::IntRect(0, 0, enemySprite.getTexture()->getSize().x, enemySprite.getTexture()->getSize().y));
			handPosition = handUp;
		}
		if (angle <= -67.5 && angle > -112.5)         //Down
		{
			enemySprite.setTexture(TextureClass::get()->retrieveTexture("enemyDown" + std::to_string(downCount / spriteSlowValue % 6)));
			downCount++;
			enemySprite.setTextureRect(sf::IntRect(0, 0, enemySprite.getTexture()->getSize().x, enemySprite.getTexture()->getSize().y));
			handPosition = handDown;
		}

		if (angle == 180 || angle == -180)       //Left
		{
			enemySprite.setTexture(TextureClass::get()->retrieveTexture("enemyLeft" + std::to_string(leftCount / spriteSlowValue % 6)));
			leftCount++;
			enemySprite.setTextureRect(sf::IntRect(0, 0, enemySprite.getTexture()->getSize().x, enemySprite.getTexture()->getSize().y));
			handPosition = handLeft;
		}

		if (angle > -67.5 && angle <= 12.5)            //Right and Down Right
		{
			enemySprite.setTexture(TextureClass::get()->retrieveTexture("enemyLeft" + std::to_string(rightCount / spriteSlowValue % 6)));
			enemySprite.setTextureRect(sf::IntRect(enemySprite.getTexture()->getSize().x, 0, enemySprite.getTexture()->getSize().x * -1, enemySprite.getTexture()->getSize().y));
			rightCount++;
			handPosition = handRight;
			if (angle > -67.5 && angle <= -27.5)
			{
				enemySprite.setTexture(TextureClass::get()->retrieveTexture("enemyLeft" + std::to_string(rightCount / spriteSlowValue % 6)));
				downRightCount++;
				enemySprite.setTextureRect(sf::IntRect(enemySprite.getTexture()->getSize().x, 0, enemySprite.getTexture()->getSize().x * -1, enemySprite.getTexture()->getSize().y));
				handPosition = handDownRight;
			}
		}
		if ((angle <= -112.5 && angle > -180) || (angle < 180 && angle > 167.5))  //Down Left 
		{
			enemySprite.setTexture(TextureClass::get()->retrieveTexture("enemyLeft" + std::to_string(leftCount / spriteSlowValue % 6)));
			leftCount++;
			enemySprite.setTextureRect(sf::IntRect(0, 0, enemySprite.getTexture()->getSize().x, enemySprite.getTexture()->getSize().y));
			handPosition = handLeft;
			if (angle > -152.5 && angle < -112.5) {
				enemySprite.setTexture(TextureClass::get()->retrieveTexture("enemyLeft" + std::to_string(leftCount / spriteSlowValue % 6)));
				downLeftCount++;
				enemySprite.setTextureRect(sf::IntRect(0, 0, enemySprite.getTexture()->getSize().x, enemySprite.getTexture()->getSize().y));
				handPosition = handDownLeft;
			}
		}
		if (angle > 12.5 && angle <= 67.5) {  //Up Right
			enemySprite.setTexture(TextureClass::get()->retrieveTexture("enemyUpLeft" + std::to_string(upRightCount / spriteSlowValue % 7)));
			enemySprite.setTextureRect(sf::IntRect(enemySprite.getTexture()->getSize().x, 0, enemySprite.getTexture()->getSize().x * -1, enemySprite.getTexture()->getSize().y));
			upRightCount++;
			handPosition = handUpRight;
		}
		if (angle <= 167.5 && angle > 112.5) {
			enemySprite.setTexture(TextureClass::get()->retrieveTexture("enemyUpLeft" + std::to_string(upLeftCount / spriteSlowValue % 7)));
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

	if (enemyHealth <= 0)
	{
		timed_movement *= 0.f;

		enemySprite.setTexture(TextureClass::get()->retrieveTexture("enemyDeathDownRight" + std::to_string(deathCountDownRight / 7 % 5)));
		enemySprite.setTextureRect(sf::IntRect(0, 0, enemySprite.getTexture()->getSize().x, enemySprite.getTexture()->getSize().y));
		if (deathCountDownRight++ / 7 % 5 == 4) {
			isDead = true;
		}
	}

	enemySprite.move(timed_movement);
	enemyHand.move(timed_movement);
	enemyHand.setPosition(enemySprite.getPosition() + handPosition);
	pistol.update(deltaTime, direction, allAreas);
	pistol.getsprite().setPosition(enemyHand.getPosition() + sf::Vector2f(enemyHand.getTexture()->getSize().x / 2.f, enemyHand.getTexture()->getSize().y / 2.f) + sf::Vector2f(3.f, -3.f));
	
}


void SideKick1::render(sf::RenderWindow* window)
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

