#pragma once
#include "Gun.h"

class PlayerGun1 :public Gun
{
protected:
	bool leftclicked;
	bool rightclicked;
	//int recoil_count;
	int reload_check;
	int count;
	sf::Time t1;
	sf::Clock c1;
	int capacity;
	int Tcapacity;
	int Total_bullets_fired;
	bool emptycheck;
	bool check;
	sf::Font font;
	sf::Text text;
	std::string TextToDisplay;
	int TemporaryCapacity;
	int BulletsInMag;
	sf::SoundBuffer DFbuffer;
	sf::Sound DFsound;

public:
	PlayerGun1(int capacity, int Tcapacity, float SpeedFactor, float Damage);
	PlayerGun1(int capacity, int type1, int type2);
	void handle_keyboard_input(sf::Keyboard::Key key, bool IsPressed);
	void handle_left_mouse_input(bool IsClicked);
	void handle_right_mouse_input(bool IsClicked);
	virtual void update(sf::Time deltaTime, sf::Vector2f aim_direction, std::vector<TileSet*>& allAreas);
	bool isReloading() const;
	int getCapacity() const;
	void recoil();
	void setclick(bool a);
	sf::Time getClockTime();
	sf::Text& getText();
	sf::Time getTime() const;
	bool getReloadCheck() const;
	int getTcapacity() const;
	int getBulletsFired() const;
	void incrementBulletsFired();
	int getVectorSize() const;
	void setCheck(bool a);
	void setTime(sf::Time time);
	bool getclick() const;
	int getBulletsInMag() const;
	int getTemporaryCapacity() const;
	std::string& getString();
	int getRemainingBullets();

};

