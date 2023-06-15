#include "Menu.h"

Menu::Menu(sf::RenderWindow* window)
{
	this->window = window;

	window->setMouseCursorVisible(true);
	backgroundCount = 1;
	error1 = 0;
	error2 = 0;
	dataCount = 0;
	exitTimer = 0;
	timer = 0;
	Timer2 = 0;
	Timer3 = 0;
	Timer4 = 0;
	nameSelected = 0;
	passwordSelected = 0;
	nameSelected2 = 0;
	passwordSelected2 = 0;
	leave = false;
	font.loadFromFile("Fonts/Renegade Pursuit.otf");

	//for SAM LOGO Screen
	companyLogo.setPosition(300, 0);

	//for Menu Screen
	gameLogo.setPosition(365, -300);
	gameLogo.setScale(1.f, 1.f);
	signIn.setPosition(600, 600);
	signIn.setScale(0.5f, 0.5f);
	signUp.setScale(0.5f, 0.5f);
	signUp.setPosition(1000, 600);
	exit.setScale(0.5f, 0.5f);
	exit.setPosition(800, 750);

	//for Sign Up Screen
	promptUserName.setFont(font);
	promptUserName.setString("Enter UserName: ");
	promptUserName.setPosition(470, 500);
	promptUserName.setCharacterSize(40);
	promptUserPassword.setFont(font);
	promptUserPassword.setString("Enter Password: ");
	promptUserPassword.setPosition(470, 700);
	promptUserPassword.setCharacterSize(40);
	promptHeading.setFont(font);
	promptHeading.setString("Creating Account");
	promptHeading.setPosition(400, 200);
	promptHeading.setCharacterSize(100);
	inputUserName.setFont(font);
	inputUserName.setPosition(940, 500);
	inputUserName.setCharacterSize(30);
	inputUserPassword.setFont(font);
	inputUserPassword.setPosition(940, 700);
	inputUserPassword.setCharacterSize(40);
	InputBox1.setPosition(900, 450);
	InputBox1.setScale(0.3f, 0.3f);
	InputBox2.setPosition(900, 650);
	InputBox2.setScale(0.3f, 0.3f);
	submit.setPosition(750, 750);
	submit.setScale(0.5f, 0.5f);
	promptErrorUserExist.setFont(font);
	promptErrorUserExist.setPosition(800, 1000);
	promptErrorUserExist.setCharacterSize(20);
	promptErrorUserExist.setString("UserName already exists....");
	promptIDCreated.setFont(font);
	promptIDCreated.setPosition(800, 1000);
	promptIDCreated.setCharacterSize(20);
	promptIDCreated.setString("Account Created Successfully. Go back to Sign In");


	//for Sign In Screen
	promptUserName2.setFont(font);
	promptUserName2.setString("UserName: ");
	promptUserName2.setPosition(470, 500);
	promptUserName2.setCharacterSize(40);
	promptUserPassword2.setFont(font);
	promptUserPassword2.setString("Password: ");
	promptUserPassword2.setPosition(470, 700);
	promptUserPassword2.setCharacterSize(40);
	promptHeading2.setFont(font);
	promptHeading2.setString("Survival Is The Only Option!");
	promptHeading2.setPosition(300, 200);
	promptHeading2.setCharacterSize(80);
	inputUserName2.setFont(font);
	inputUserName2.setPosition(940, 500);
	inputUserName2.setCharacterSize(30);
	inputUserPassword2.setFont(font);
	inputUserPassword2.setPosition(940, 700);
	inputUserPassword2.setCharacterSize(40);
	InputBox3.setPosition(900, 450);
	InputBox3.setScale(0.3f, 0.3f);
	InputBox4.setPosition(900, 650);
	InputBox4.setScale(0.3f, 0.3f);
	enter.setPosition(750, 750);
	enter.setScale(0.5f, 0.5f);
	promptErrorIncorrectIDPass.setFont(font);
	promptErrorIncorrectIDPass.setPosition(800, 1000);
	promptErrorIncorrectIDPass.setCharacterSize(20);
	promptErrorIncorrectIDPass.setString("Incorrect ID or Password....");

	//for Play Screen
	promptHeading3.setFont(font);
	promptHeading3.setPosition(600, 200);
	promptHeading3.setCharacterSize(80);
	promptHeading3.setFillColor(sf::Color::White);
	promptHeading3.setOutlineColor(sf::Color::Black);
	play.setPosition(-500, -500);
	play.setScale(0.5f, 0.5f);
	promptScore.setFont(font);
	promptScore.setPosition(0, 0);
	promptScore.setFillColor(sf::Color::Red);
	promptScore.setOutlineColor(sf::Color::Black);
	promptScore.setCharacterSize(30);
	promptScore.setString("Scorecard:");
	promptHighestScore.setFont(font);
	promptHighestScore.setFillColor(sf::Color::Black);
	promptHighestScore.setOutlineColor(sf::Color::White);
	promptHighestScore.setCharacterSize(35);
	promptHighestScore.setString("HighestScore: 0");

	Background2.setTexture(TextureClass::get()->retrieveTexture("Background2"));
	Background3.setTexture(TextureClass::get()->retrieveTexture("Background3"));
	Background4.setTexture(TextureClass::get()->retrieveTexture("Background4"));
	Background5.setTexture(TextureClass::get()->retrieveTexture("Background5"));
	companyLogo.setTexture(TextureClass::get()->retrieveTexture("CompanyLogo"));
	gameLogo.setTexture(TextureClass::get()->retrieveTexture("GameLogo"));
	signIn.setTexture(TextureClass::get()->retrieveTexture("SignIn"));
	signUp.setTexture(TextureClass::get()->retrieveTexture("SignUp"));
	exit.setTexture(TextureClass::get()->retrieveTexture("Exit"));
	InputBox1.setTexture(TextureClass::get()->retrieveTexture("InputBox1"));
	InputBox2.setTexture(TextureClass::get()->retrieveTexture("InputBox2"));
	InputBox3.setTexture(TextureClass::get()->retrieveTexture("InputBox3"));
	InputBox4.setTexture(TextureClass::get()->retrieveTexture("InputBox4"));
	submit.setTexture(TextureClass::get()->retrieveTexture("submit"));
	enter.setTexture(TextureClass::get()->retrieveTexture("enter"));
	play.setTexture(TextureClass::get()->retrieveTexture("play"));


	createFile();

}

void Menu::run() {
	
	sf::Clock clock;
	sf::Time TimePerFrame = sf::seconds(1.f / 60.f);
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	while (window->isOpen() && !leave) {

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

void Menu::processEvents() {

	while (window->pollEvent(event)) {

		if (event.type == sf::Event::Closed) {
			window->close();
		}
		if (event.type == sf::Event::KeyPressed) {
			/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
				std::cout << "End of Program." << std::endl;
				window->close();
			}*/
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				if (backgroundCount == 2)
				{
					backgroundCount = 5;
				}
				if (backgroundCount == 3 || backgroundCount == 4 || backgroundCount == 9)
				{
					backgroundCount = 2;
				}
			}
		}
		if (event.type == sf::Event::MouseButtonPressed)
		{
			sf::Vector2i mousePos = sf::Mouse::getPosition(*window);

			//For Exit Button
			if (mousePos.x >= exit.getPosition().x && mousePos.x <= exit.getPosition().x + exit.getTexture()->getSize().x &&
				mousePos.y >= exit.getPosition().y && mousePos.y <= exit.getPosition().y + exit.getTexture()->getSize().y && backgroundCount == 2)
			{
				backgroundCount = 5;
			}

			//For Sign Up button
			if (mousePos.x >= signUp.getPosition().x && mousePos.x <= signUp.getPosition().x + signUp.getTexture()->getSize().x &&
				mousePos.y >= signUp.getPosition().y && mousePos.y <= signUp.getPosition().y + signUp.getTexture()->getSize().y && backgroundCount == 2)
			{
				backgroundCount = 4;
			}

			//For Sign In button
			if (mousePos.x >= signIn.getPosition().x && mousePos.x <= signIn.getPosition().x + signIn.getTexture()->getSize().x &&
				mousePos.y >= signIn.getPosition().y && mousePos.y <= signIn.getPosition().y + signIn.getTexture()->getSize().y && backgroundCount == 2)
			{
				backgroundCount = 3;
			}

			//For Enter Button
			if (mousePos.x >= enter.getPosition().x && mousePos.x <= enter.getPosition().x + enter.getTexture()->getSize().x &&
				mousePos.y >= enter.getPosition().y && mousePos.y <= enter.getPosition().y + enter.getTexture()->getSize().y && backgroundCount == 3)
			{
				verification();
			}

			//For Submit Button
			if (mousePos.x >= submit.getPosition().x && mousePos.x <= submit.getPosition().x + submit.getTexture()->getSize().x &&
				mousePos.y >= submit.getPosition().y && mousePos.y <= submit.getPosition().y + submit.getTexture()->getSize().y && backgroundCount == 4)
			{
				writeInFile();
			}

			//For Play Button
			if (mousePos.x >= play.getPosition().x && mousePos.x <= play.getPosition().x + play.getTexture()->getSize().x &&
				mousePos.y >= play.getPosition().y && mousePos.y <= play.getPosition().y + play.getTexture()->getSize().y && backgroundCount == 9)
			{
				leave = true;
			}

			//For Input Text Box in SignUp screen
			if (mousePos.x >= InputBox1.getPosition().x && mousePos.x <= InputBox1.getPosition().x + InputBox1.getTexture()->getSize().x &&
				mousePos.y >= InputBox1.getPosition().y && mousePos.y <= InputBox1.getPosition().y + InputBox1.getTexture()->getSize().y && backgroundCount == 4)
			{
				nameSelected = 1;
				passwordSelected = 0;
			}
			if (mousePos.x >= InputBox2.getPosition().x && mousePos.x <= InputBox2.getPosition().x + InputBox2.getTexture()->getSize().x &&
				mousePos.y >= InputBox2.getPosition().y && mousePos.y <= InputBox2.getPosition().y + InputBox2.getTexture()->getSize().y && backgroundCount == 4)
			{
				passwordSelected = 1;
				nameSelected = 0;
			}

			//For Input Text Box in Sign In screen
			if (mousePos.x >= InputBox3.getPosition().x && mousePos.x <= InputBox3.getPosition().x + InputBox3.getTexture()->getSize().x &&
				mousePos.y >= InputBox3.getPosition().y && mousePos.y <= InputBox3.getPosition().y + InputBox3.getTexture()->getSize().y && backgroundCount == 3)
			{
				nameSelected2 = 1;
				passwordSelected2 = 0;
			}
			if (mousePos.x >= InputBox4.getPosition().x && mousePos.x <= InputBox4.getPosition().x + InputBox4.getTexture()->getSize().x &&
				mousePos.y >= InputBox4.getPosition().y && mousePos.y <= InputBox4.getPosition().y + InputBox4.getTexture()->getSize().y && backgroundCount == 3)
			{
				passwordSelected2 = 1;
				nameSelected2 = 0;
			}
		}


		if (event.type == sf::Event::TextEntered)
		{
			if (nameSelected && event.text.unicode < 128 && backgroundCount == 4)
			{
				if (event.text.unicode == '\b' && !inputUserName.getString().isEmpty())
				{
					inputUserName.setString(inputUserName.getString().substring(0, inputUserName.getString().getSize() - 1));
				}
				else
				{
					inputUserName.setString(inputUserName.getString() + static_cast<char>(event.text.unicode));
				}
			}
			if (passwordSelected && event.text.unicode < 128 && backgroundCount == 4)
			{


				if (event.text.unicode == '\b' && !UserPassword.isEmpty())
				{
					inputUserPassword.setString(inputUserPassword.getString().substring(0, inputUserPassword.getString().getSize() - 1));
					UserPassword = UserPassword.substring(0, UserPassword.getSize() - 1);
					password.pop_back();
				}
				else
				{
					UserPassword += '*';
					password += static_cast<char>(event.text.unicode);
					inputUserPassword.setString(UserPassword);
				}
			}
			if (nameSelected2 && event.text.unicode < 128 && backgroundCount == 3)
			{
				if (event.text.unicode == '\b' && !inputUserName2.getString().isEmpty())
				{
					inputUserName2.setString(inputUserName2.getString().substring(0, inputUserName2.getString().getSize() - 1));
				}
				else
				{
					inputUserName2.setString(inputUserName2.getString() + static_cast<char>(event.text.unicode));
				}
			}
			if (passwordSelected2 && event.text.unicode < 128 && backgroundCount == 3)
			{
				if (event.text.unicode == '\b' && !UserPassword2.isEmpty())
				{
					inputUserPassword2.setString(inputUserPassword2.getString().substring(0, inputUserPassword2.getString().getSize() - 1));
					UserPassword2 = UserPassword2.substring(0, UserPassword2.getSize() - 1);
					password2.pop_back();
				}
				else
				{
					UserPassword2 += '*';
					password2 += static_cast<char>(event.text.unicode);
					inputUserPassword2.setString(UserPassword2);
				}
			}
		}

	}
}

void Menu::update(sf::Time deltaTime)
{
	Background.setTexture(TextureClass::get()->retrieveTexture("Background_" + std::to_string(count / 13 % 261)));
	
	if (backgroundCount == 5)
	{
		exitTimer++;
		if (exitTimer == 300)
		{
			std::exit(0);
		}
	}

	sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
	//For Exit Button
	if (mousePos.x >= exit.getPosition().x && mousePos.x <= exit.getPosition().x + exit.getTexture()->getSize().x &&
		mousePos.y >= exit.getPosition().y && mousePos.y <= exit.getPosition().y + exit.getTexture()->getSize().y && backgroundCount == 2)
	{
		exit.setScale(0.6f, 0.6f);
		signIn.setScale(0.5f, 0.5f);
		signUp.setScale(0.5f, 0.5f);
	}

	//For Sign Up button
	else if (mousePos.x >= signUp.getPosition().x && mousePos.x <= signUp.getPosition().x + signUp.getTexture()->getSize().x &&
		mousePos.y >= signUp.getPosition().y && mousePos.y <= signUp.getPosition().y + signUp.getTexture()->getSize().y && backgroundCount == 2)
	{
		signUp.setScale(0.6f, 0.6f);
		exit.setScale(0.5f, 0.5f);
		signIn.setScale(0.5f, 0.5f);
	}

	//For Sign In button
	else if (mousePos.x >= signIn.getPosition().x && mousePos.x <= signIn.getPosition().x + signIn.getTexture()->getSize().x &&
		mousePos.y >= signIn.getPosition().y && mousePos.y <= signIn.getPosition().y + signIn.getTexture()->getSize().y && backgroundCount == 2)
	{
		signIn.setScale(0.6f, 0.6f);
		signUp.setScale(0.5f, 0.5f);
		exit.setScale(0.5f, 0.5f);
	}

	//For Enter Button
	else if (mousePos.x >= enter.getPosition().x && mousePos.x <= enter.getPosition().x + enter.getTexture()->getSize().x &&
		mousePos.y >= enter.getPosition().y && mousePos.y <= enter.getPosition().y + enter.getTexture()->getSize().y && backgroundCount == 3)
	{
		enter.setScale(0.6f, 0.6f);
	}

	//For Submit Button
	else if (mousePos.x >= submit.getPosition().x && mousePos.x <= submit.getPosition().x + submit.getTexture()->getSize().x &&
		mousePos.y >= submit.getPosition().y && mousePos.y <= submit.getPosition().y + submit.getTexture()->getSize().y && backgroundCount == 4)
	{
		submit.setScale(0.6f, 0.6f);
	}

	//For Play Button
	else if (mousePos.x >= play.getPosition().x && mousePos.x <= play.getPosition().x + play.getTexture()->getSize().x &&
		mousePos.y >= play.getPosition().y && mousePos.y <= play.getPosition().y + play.getTexture()->getSize().y && backgroundCount == 9)
	{
		play.setScale(0.6f, 0.6f);
	}

	else
	{
		signIn.setScale(0.5f, 0.5f);
		signUp.setScale(0.5f, 0.5f);
		exit.setScale(0.5f, 0.5f);
		enter.setScale(0.5f, 0.5f);
		submit.setScale(0.5f, 0.5f);
		play.setScale(0.5f, 0.5f);
	}

	count++;
	timer++;
}

void Menu::render()
{
	if (backgroundCount == 1)
	{
		backgroundCount = 2;
	}
	else if (backgroundCount == 2)
	{
		renderMenu();
	}
	else if (backgroundCount == 3)
	{
		renderSignIn();
	}
	else if (backgroundCount == 4)
	{
		renderSignUp();
	}
	else if (backgroundCount == 5)
	{
		renderExit();
	}
	else if (backgroundCount == 7)
	{
		window->draw(promptErrorUserExist);
		Timer2++;
		if (Timer2 == 100)
		{
			backgroundCount = 4;
			Timer2 = 0;
		}
	}
	else if (backgroundCount == 8)
	{
		window->draw(promptIDCreated);
		Timer3++;

		if (Timer3 == 100)
		{
			backgroundCount = 2;
			Timer3 = 0;
		}
	}
	else if (backgroundCount == 9)
	{
		play.setPosition(800, 820);
		renderPlayScreen();
		DisplayScore();
	}
	else if (backgroundCount == 10)
	{
		window->draw(promptErrorIncorrectIDPass);
		Timer4++;
		if (Timer4 == 100)
		{
			backgroundCount = 3;
			Timer4 = 0;
		}
	}

	window->display();

}

void Menu::renderCompanyLogo()
{
	backgroundCount = 1;
	window->draw(companyLogo);
}

void Menu::renderMenu()
{
	backgroundCount = 2;
	window->draw(Background);
	window->draw(gameLogo);
	window->draw(signIn);
	window->draw(signUp);
	window->draw(exit);
}

void Menu::renderSignIn()
{
	backgroundCount = 3;
	window->draw(Background2);
	window->draw(promptUserName2);
	window->draw(promptUserPassword2);
	window->draw(promptHeading2);
	window->draw(InputBox3);
	window->draw(InputBox4);
	window->draw(inputUserName2);
	window->draw(inputUserPassword2);
	window->draw(enter);
}

void Menu::renderSignUp()
{
	backgroundCount = 4;
	window->draw(Background3);
	window->draw(promptUserName);
	window->draw(promptUserPassword);
	window->draw(promptHeading);
	window->draw(InputBox1);
	window->draw(InputBox2);
	window->draw(inputUserName);
	window->draw(inputUserPassword);
	window->draw(submit);

}

void Menu::renderPlayScreen()
{
	promptHeading3.setString("Welcome   " + getInputUser2Name());
	window->draw(Background5);
	window->draw(promptHeading3);
	window->draw(play);
}


void Menu::renderExit()
{
	backgroundCount = 5;
	window->draw(Background4);
}

std::string Menu::getInputUserName()
{
	return inputUserName.getString();
}

std::string Menu::getInputUser2Name()
{
	return inputUserName2.getString().toAnsiString();
}

void Menu::createFile()
{
	std::ofstream file("userData.txt", std::ios_base::app);
	if (!file)
	{
		std::cout << "File not found" << std::endl;
	}
	file.close();
	std::ofstream file2("userScore.txt", std::ios_base::app);
	if (!file)
	{
		std::cout << "userScore.txt not found" << std::endl;
	}
	file2.close();
}

void Menu::writeInFile()
{
	bool found = false;
	int count = 0;
	std::string str;
	std::ifstream file("userData.txt");

	dataCount = 1;

	if (!file)
	{
		std::cout << "Unable to open file" << std::endl;
	}

	while (file >> str) {

		if (count == 0 && str == getInputUserName()) {
			dataCount = 0;
			backgroundCount = 7;
			found = true;
			break;
		}

		count++;
		if (count > 2) {
			count = 0;
		}

	}

	file.close();

	if (dataCount == 1)
	{
		std::string tmpString = inputUserName.getString().toAnsiString();

		std::ofstream file("userData.txt", std::ios_base::app);
		file << tmpString << " ";
		file << password << "\n";
		backgroundCount = 8;
		file.close();

	}
}


void Menu::verification()
{
	bool check1, check2;
	check1 = check2 = false;
	int count = 0;
	std::string str;
	std::ifstream file("userData.txt");

	while (file >> str) {

		if (count == 0 && str == getInputUser2Name()) {
			check1 = true;
		}

		if (count == 1 && str == password2) {
			check2 = true;
		}


		if (check1 && check2) {
			break;
		}

		if (++count > 1) {
			count = 0;
			check1 = check2 = false;
		}
	}

	if (check1 && check2) {
		backgroundCount = 9;
	}
	else {
		backgroundCount = 10;
	}

	file.close();

}

void Menu::DisplayScore()
{
	int i = 0;
	int highestScore = 0;
	int index;

	std::ifstream file("userScore.txt", std::ios_base::in);
	std::string score;
	while (getline(file, score))
	{
		index = score.find(" ", 0);
		std::string tempScore = score.substr(index + 1, score.length() - index + 1);
		std::string tempUser = score.substr(0, index);
		
		if (std::stoi(tempScore) > highestScore && tempUser == getInputUser2Name()) {
			highestScore = stoi(tempScore);
			promptHighestScore.setString("Highest Score: " + tempScore);
		}

		promptScore.setString(score);
		promptScore.setPosition(550.f, 450.f + 50.f * i);
		window->draw(promptScore);
		i++;
	}

	promptHighestScore.setPosition(800.f, 350.f);
	window->draw(promptHighestScore);

	file.close();
}