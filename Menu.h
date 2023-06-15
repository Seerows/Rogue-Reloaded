#pragma once
#include <SFML/Graphics.hpp>
#include "TextureClass.h"
#include <fstream>

class Menu
{
	sf::Sprite Background, companyLogo, gameLogo, signIn, signUp, exit, play, Background2, Background3, Background4, Background5;
	sf::Sprite submit, InputBox1, InputBox2, InputBox3, InputBox4, enter;
	sf::Font font;
	sf::Text promptUserName, promptUserPassword, promptHeading, promptErrorUserExist;
	sf::Text promptUserName2, promptUserPassword2, promptHeading2, promptErrorIncorrectIDPass, promptIDCreated, promptScore, promptHighestScore;
	sf::Text promptHeading3;
	sf::Text inputUserName, inputUserPassword;
	sf::Text inputUserName2, inputUserPassword2;
	sf::String UserPassword, UserPassword2;
	std::string password, password2;
	sf::RenderWindow* window;
	sf::Event event;
	bool nameSelected, passwordSelected;
	bool nameSelected2, passwordSelected2;
	bool error1, error2;
	int count;
	int timer, exitTimer;
	int backgroundCount;
	int dataCount;
	int Timer2, Timer3, Timer4;
	bool leave;

public:
	Menu(sf::RenderWindow* window);
	void run();
	void processEvents();
	void update(sf::Time deltaTime);
	void render();
	void renderCompanyLogo();
	void renderMenu();
	void renderSignIn();
	void renderSignUp();
	void renderExit();
	void renderPlayScreen();
	void createFile();
	void writeInFile();
	void verification();
	std::string getInputUserName();  //for signUp
	std::string getInputUser2Name(); //for signIN
	void DisplayScore();
};
