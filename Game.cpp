#include "Game.h"

Game::Game(sf::RenderWindow* window, std::string userName) {

	this->window = window;
	this->userName = userName;

	window->setMouseCursorVisible(false);	

	player.getSprite().setPosition(sf::Vector2f(500, 300));
	view.setCenter(player.getSprite().getPosition());
	view.setSize(sf::Vector2f(window->getSize()));
	view.zoom(0.7f);

	enteredIA = enteredMA = enteredFA = false;
	IA_cleared = MA_cleared = FA_cleared = false;

	sf::Vector2f tileSize = sf::Vector2f(16, 16);	

	startingArea.loadFloor(&TextureClass::get()->retrieveTexture("StartingAreaFloor"), tileSize, 16, 9);
	startingArea.move(sf::Vector2f(tileSize.x * startingArea.getScale().x, tileSize.y * startingArea.getScale().y));
	allAreas.push_back(&startingArea);
	sf::Vector2i startingAreaExceptions[] = { sf::Vector2i(18, 4), sf::Vector2i(18, 5), sf::Vector2i(18, 6), sf::Vector2i(18, 7), sf::Vector2i(18,8) };
	startingAreaWall.loadWall(&TextureClass::get()->retrieveTexture("StartingAreaWall"), tileSize, 18, 11, startingAreaExceptions, 5);
	allWalls.push_back(&startingAreaWall);

	SA_bridge.loadFloor(&TextureClass::get()->retrieveTexture("SA_BridgeFloor"), tileSize, 10, 3);
	SA_bridge.move(sf::Vector2f(tileSize.x * 17 * startingArea.getScale().x, tileSize.y * 4 * startingArea.getScale().y));
	allAreas.push_back(&SA_bridge);
	sf::Vector2i SA_bridgeExceptions[] = { sf::Vector2i(1, 1), sf::Vector2i(1, 2), sf::Vector2i(1, 3), sf::Vector2i(1, 4), sf::Vector2i(1, 5), sf::Vector2i(12, 1), sf::Vector2i(12, 2), sf::Vector2i(12, 3), sf::Vector2i(12, 4), sf::Vector2i(12, 5) };
	SA_bridgeWall.loadWall(&TextureClass::get()->retrieveTexture("SA_BridgeWall"), tileSize, 12, 5, SA_bridgeExceptions, 10);
	SA_bridgeWall.setPosition(SA_bridge.getPosition() + sf::Vector2f(-48, -48));
	allWalls.push_back(&SA_bridgeWall);

	initialArea.loadFloor(&TextureClass::get()->retrieveTexture("InitialAreaFloor"), tileSize, 20, 20);
	initialArea.move(sf::Vector2f(tileSize.x * 27 * startingArea.getScale().x, tileSize.y * -7 * startingArea.getScale().y));
	allAreas.push_back(&initialArea);
	sf::Vector2i initialAreaExceptions[] = { sf::Vector2i(1,12), sf::Vector2i(1,13), sf::Vector2i(1,14), sf::Vector2i(1,15), sf::Vector2i(1,16), sf::Vector2i(10, 1), sf::Vector2i(11, 1), sf::Vector2i(12, 1), sf::Vector2i(13, 1), sf::Vector2i(14, 1) };
	initialAreaWall.loadWall(&TextureClass::get()->retrieveTexture("InitialAreaWall"), tileSize, 22, 22, initialAreaExceptions, 10);
	initialAreaWall.move(initialArea.getPosition() + sf::Vector2f(-48, -48));
	allWalls.push_back(&initialAreaWall);

	IA_bridge.loadFloor(&TextureClass::get()->retrieveTexture("IA_BridgeFloor"), tileSize, 3, 10);
	IA_bridge.setPosition(initialArea.getPosition() + sf::Vector2f(tileSize.x * 9 * startingArea.getScale().x, tileSize.y * -10 * startingArea.getScale().y));
	allAreas.push_back(&IA_bridge);
	sf::Vector2i IA_bridgeExceptions[] = { sf::Vector2i(1, 1), sf::Vector2i(2, 1), sf::Vector2i(3, 1), sf::Vector2i(4, 1), sf::Vector2i(5, 1),  sf::Vector2i(1, 12), sf::Vector2i(2, 12), sf::Vector2i(3, 12), sf::Vector2i(4, 12), sf::Vector2i(5, 12) };
	IA_bridgeWall.loadWall(&TextureClass::get()->retrieveTexture("IA_BridgeWall"), tileSize, 5, 12, IA_bridgeExceptions, 10);
	IA_bridgeWall.setPosition(IA_bridge.getPosition() + sf::Vector2f(-48, -48));
	allWalls.push_back(&IA_bridgeWall);

	middleArea.loadFloor(&TextureClass::get()->retrieveTexture("MiddleAreaFloor"), tileSize, 20, 20);
	middleArea.setPosition(IA_bridgeWall.getPosition() + sf::Vector2f(tileSize.x * -8 * startingArea.getScale().x, tileSize.y * -19 * startingArea.getScale().y));
	allAreas.push_back(&middleArea);
	sf::Vector2i middleAreaExceptions[] = { sf::Vector2i(10, 1), sf::Vector2i(11, 1), sf::Vector2i(12, 1), sf::Vector2i(13, 1), sf::Vector2i(14, 1), sf::Vector2i(14, 22), sf::Vector2i(10, 22), sf::Vector2i(11, 22), sf::Vector2i(12, 22), sf::Vector2i(13, 22), sf::Vector2i(14, 22)};
	middleAreaWall.loadWall(&TextureClass::get()->retrieveTexture("MiddleAreaWall"), tileSize, 22, 22, middleAreaExceptions, 11);
	middleAreaWall.setPosition(middleArea.getPosition() + sf::Vector2f(-48, -48));
	allWalls.push_back(&middleAreaWall);

	MA_bridge.loadFloor(&TextureClass::get()->retrieveTexture("MA_BridgeFloor"), tileSize, 5, 14);
	MA_bridge.setPosition(middleArea.getPosition() + sf::Vector2f(tileSize.x * 8 * middleArea.getScale().x, tileSize.y * -14 * middleArea.getScale().y));
	allAreas.push_back(&MA_bridge);
	sf::Vector2i MA_bridgeExceptions[] = { sf::Vector2i(1, 1), sf::Vector2i(2, 1), sf::Vector2i(3, 1), sf::Vector2i(4, 1), sf::Vector2i(5, 1), sf::Vector2i(6, 1), sf::Vector2i(7, 1), sf::Vector2i(1, 16), sf::Vector2i(2, 16), sf::Vector2i(3, 16), sf::Vector2i(4, 16), sf::Vector2i(5, 16), sf::Vector2i(6, 16), sf::Vector2i(7, 16) };
	MA_bridgeWall.loadWall(&TextureClass::get()->retrieveTexture("MA_BridgeWall"), tileSize, 7, 16, MA_bridgeExceptions, 14);
	MA_bridgeWall.setPosition(MA_bridge.getPosition() + sf::Vector2f(-48, -48));
	allWalls.push_back(&MA_bridgeWall);

	finalArea.loadFloor(&TextureClass::get()->retrieveTexture("FinalAreaFloor"), tileSize, 20, 20);
	finalArea.setPosition(MA_bridgeWall.getPosition() + sf::Vector2f(tileSize.x * -7 * middleArea.getScale().x, tileSize.y * -19 * middleArea.getScale().y));
	allAreas.push_back(&finalArea);
	sf::Vector2i finalAreaExceptions[] = { sf::Vector2i(9, 22), sf::Vector2i(10, 22), sf::Vector2i(11, 22), sf::Vector2i(12, 22), sf::Vector2i(13, 22), sf::Vector2i(14, 22), sf::Vector2i(15, 22) };
	finalAreaWall.loadWall(&TextureClass::get()->retrieveTexture("FinalAreaWall"), tileSize, 22, 22, finalAreaExceptions, 7);
	finalAreaWall.setPosition(finalArea.getPosition() + sf::Vector2f(-48, -48));
	allWalls.push_back(&finalAreaWall);

	allWalkableAreas = allAreas;

	status.push_back(false);
	status.push_back(false);
	Lost = Won = false;

	item.setPosition(allAreas);

	scoreCalculated = false;
	score = numberOfEnemiesKilled = 0;

	Exit = false;

	ResultFont.loadFromFile("Fonts/Renegade Pursuit.otf");
	ResultText.setFont(ResultFont);
	ResultText.setScale(1.8f, 1.8f);
	ResultText.setPosition(825, 260);

	Continue.setTexture(TextureClass::get()->retrieveTexture("Continue"));
	Continue.setOrigin(sf::Vector2f(Continue.getTexture()->getSize()) / 2.f);
	Continue.setScale(0.65f, 0.65f);
	Continue.setPosition(-300, -300);

}

void Game::run() {

	sf::Clock clock;
	sf::Time TimePerFrame = sf::seconds(1.f / 60.f);
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	while (window->isOpen() && !Exit) {
		processEvents();
		timeSinceLastUpdate += clock.restart();

		while (timeSinceLastUpdate > TimePerFrame) {
			timeSinceLastUpdate -= TimePerFrame;
			processEvents();
			update(TimePerFrame);
		}
		render();
	}
}

void Game::processEvents() {

	while (window->pollEvent(event)) {

		if (!Lost && !Won) {
			if (event.type == sf::Event::Closed) {
				window->close();
			}

			if (event.type == sf::Event::KeyPressed) {
				/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
					std::cout << "End of Program." << std::endl;
					window->close();
				}*/
				player.playerKeyboardInput(event.key.code, true);
			}

			if (event.type == sf::Event::KeyReleased) {
				player.playerKeyboardInput(event.key.code, false);
			}

			if (event.type == sf::Event::MouseMoved) {
				player.playerMouseInput(window);
			}

			if (event.type == sf::Event::MouseButtonPressed) {
				player.playerClickInput(event.mouseButton.button, true);
			}

			if (event.type == sf::Event::MouseButtonReleased) {
				player.playerClickInput(event.mouseButton.button, false);
			}

			if (event.type == sf::Event::MouseWheelScrolled) {
				player.playerScrollInput(event.mouseWheelScroll.delta);
			}
		}
		else {
			if (event.type == sf::Event::KeyPressed) {
				/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
					std::cout << "End of Program." << std::endl;
					window->close();
				}*/
			}

			sf::Vector2f mousePosition = sf::Vector2f(float(sf::Mouse::getPosition(*window).x), float(sf::Mouse::getPosition(*window).y));

			if (event.type == sf::Event::MouseButtonPressed) {
				if (event.mouseButton.button == sf::Mouse::Left) {
					if (Continue.getGlobalBounds().contains(mousePosition)) {
						Exit = true;
					}
				}
			}

			

		}

	}
}

void Game::calculateScore() {
	if (!scoreCalculated) {
		scoreCalculated = true;
		if (Won) {
			score += 300;
		}
		
		for (int i = 0; i < player.getAllGuns()->size(); i++) {
			score += (player.getAllGuns()->at(i)->getRemainingBullets() * 4);
		}
		
		score += (100 * numberOfEnemiesKilled);

		std::ofstream file("userScore.txt", std::ios_base::app);
		file << userName << " " << score << "\n";
		file.close();

	}
}

void Game::update(sf::Time deltaTime){
	
	if (!Lost && !Won) {		//if not game over
		Rect.top = player.getSprite().getPosition().y - sf::Vector2f(view.getSize() / 2.f).y;
		Rect.left = player.getSprite().getPosition().x - sf::Vector2f(view.getSize() / 2.f).x;
		Rect.width = view.getSize().x;
		Rect.height = view.getSize().y;

		item.itemUpdate(&player);

		if (player.hasEnteredArea(allAreas.at(2)) && !IA_cleared) {

			if (!enteredIA) {
				allWalkableAreas.clear();
				allWalkableAreas.push_back(allAreas.at(2));

				enteredIA = true;
				for (int i = 0; i < 5; i++) {
					enemies.push_back(new SideKick1);
					enemies.at(i)->getSprite().setPosition(allAreas.at(2)->getPosition().x + 600.f - 200.f * i / 2, allAreas.at(2)->getPosition().y + 500.f + 170.f * i / 2 * std::powf(-1.f, float(i)));
				}
				enemies.push_back(new SideKick2);
				enemies.at(int(enemies.size()) - 1)->getSprite().setPosition(allAreas.at(2)->getPosition().x + 700.f, allAreas.at(2)->getPosition().y + 250.f);
				enemies.push_back(new SideKick2);
				enemies.at(int(enemies.size()) - 1)->getSprite().setPosition(allAreas.at(2)->getPosition().x + 700.f, allAreas.at(2)->getPosition().y + 850.f);
			}

			if (enemies.empty()) {
				IA_cleared = true;
				enemies.clear();
			}

		}
		else if (player.hasEnteredArea(allAreas.at(4)) && !MA_cleared) {

			if (!enteredMA) {
				allWalkableAreas.clear();
				allWalkableAreas.push_back(allAreas.at(4));

				enteredMA = true;
				for (int i = 0; i < 6; i++) {
					enemies.push_back(new SideKick2);
					enemies.at(i)->getSprite().setPosition(allWalkableAreas.at(0)->getPosition().x + 150.f + 350.f * (i % 3), allWalkableAreas.at(0)->getPosition().y + 350.f + 150.f * (i / 3));
				}
				enemies.push_back(new SideKick2);
				enemies.at(int(enemies.size())-1)->getSprite().setPosition(allWalkableAreas.at(0)->getPosition().x + 150.f + 350.f, allWalkableAreas.at(0)->getPosition().y + 350.f + 150 * 2);
			}

			if (enemies.empty()) {
				MA_cleared = true;
				enemies.clear();
			}

		}
		else if (player.hasEnteredArea(allAreas.at(6)) && !FA_cleared) {

			if (!enteredFA) {
				allWalkableAreas.clear();
				allWalkableAreas.push_back(allAreas.at(6));

				enteredFA = true;
				for (int i = 0; i < 4; i++) {
					enemies.push_back(new SideKick2);
					enemies.at(i)->getSprite().setPosition(allWalkableAreas.at(0)->getPosition().x + 170 + 550.f * (i % 2), allWalkableAreas.at(0)->getPosition().y + 300.f + 250.f * (i / 2));
				}
				enemies.push_back(new Boss);
				enemies.at(4)->getSprite().setPosition(allWalkableAreas.at(0)->getPosition().x + 150 + 290, allWalkableAreas.at(0)->getPosition().y + 300 + 125);
			}

			if (enemies.empty()) {
				FA_cleared = true;
				Won = true;
				enemies.clear();
			}

		}
		else {
			allWalkableAreas = allAreas;
		}

		enemyUpdate(deltaTime);

		status = player.update(deltaTime, view, &enemies, allWalkableAreas);
		Lost = status.at(0);

		hud.hudUpdate(player.getHealth(), view, status.at(1), player.getEquippedGun());

	}
	else {
		window->setMouseCursorVisible(true);
		if (Lost) {
			Result.setTexture(TextureClass::get()->retrieveTexture("GameOver"));
			Result.setScale(1.2f, 1.2f);
			ResultText.setString("   DEFEAT\n\nScore: " + std::to_string(score));
		}
		else if (Won) {
			Result.setTexture(TextureClass::get()->retrieveTexture("Victory"));
			Result.setScale(1.f, 1.f);
			ResultText.setString(" VICTORY\n\nScore: " + std::to_string(score));
		}

		Continue.setPosition(ResultText.getPosition() + sf::Vector2f(120.f, 500.f));
		Result.setPosition(0.f, 0.f);
		
		calculateScore();

	}
	

}

void Game::enemyUpdate(sf::Time deltaTime) {

	for (int i = 0; i < enemies.size(); i++) {
		enemies.at(i)->update(deltaTime, &player, allWalkableAreas);
		if (enemies.at(i)->hasDied()) {
			numberOfEnemiesKilled++;
			delete enemies.at(i);
			enemies.erase(enemies.begin() + i);
		}
	}

	for (int i = 0; i < int(enemies.size()); i++) {
		for (int j = i+1; j < int(enemies.size()); j++) {
			if (i != j) {
				enemies.at(i)->collisionChecking(enemies.at(j), deltaTime);
			}
		}
	}


}

void Game::render() {
	window->clear();

	if (!Lost && !Won) {
		window->setView(view);
	}
	else {
		window->setView(window->getDefaultView());
	}
	

	if (!Lost && !Won) {
		for (int i = 0; i < allAreas.size(); i++) {
			if (Rect.intersects(allAreas.at(i)->getGlobalBounds())) {
				window->draw(*allAreas.at(i));
			}
		}

		for (int i = 0; i < allWalls.size(); i++) {
			if (Rect.intersects(allWalls.at(i)->getGlobalBounds())) {
				window->draw(*allWalls.at(i));
			}
		}
		
		for (int i = 0; i < enemies.size(); i++) {
			enemies.at(i)->render(window);
		}

		item.itemRender(window);
		player.render(window);
		hud.hudRender(window);
	
	}
	else {
		window->draw(Result);
		window->draw(ResultText);
		window->draw(Continue);
	}

	window->display();
}
