#include "TextureClass.h"

TextureClass* TextureClass::instance = nullptr;

TextureClass::TextureClass() {
	instance = this;

	//Background
	TextureClass::get()->addTexture("StartingAreaFloor", "Texture/Background/SA_floor.png");
	TextureClass::get()->addTexture("StartingAreaWall", "Texture/Background/SA_wall.png");
	TextureClass::get()->addTexture("SA_BridgeFloor", "Texture/Background/SA_bridge_floor.png");
	TextureClass::get()->addTexture("SA_BridgeWall", "Texture/Background/SA_bridge_wall.png");

	TextureClass::get()->addTexture("InitialAreaFloor", "Texture/Background/IA_floor.png");
	TextureClass::get()->addTexture("InitialAreaWall", "Texture/Background/IA_wall.png");
	TextureClass::get()->addTexture("IA_BridgeFloor", "Texture/Background/IA_bridge_floor.png");
	TextureClass::get()->addTexture("IA_BridgeWall", "Texture/Background/IA_bridge_wall.png");

	TextureClass::get()->addTexture("MiddleAreaFloor", "Texture/Background/MA_floor.png");
	TextureClass::get()->addTexture("MiddleAreaWall", "Texture/Background/MA_wall.png");
	TextureClass::get()->addTexture("MA_BridgeFloor", "Texture/Background/MA_bridge_floor.png");
	TextureClass::get()->addTexture("MA_BridgeWall", "Texture/Background/MA_bridge_wall.png");

	TextureClass::get()->addTexture("FinalAreaFloor", "Texture/Background/FA_floor.png");
	TextureClass::get()->addTexture("FinalAreaWall", "Texture/Background/FA_wall.png");


	//Player
	TextureClass::get()->addTexture("playerDO_", "Texture/Player/DO_.png");
	TextureClass::get()->addTexture("playerRO_", "Texture/Player/RO_.png");
	TextureClass::get()->addTexture("playerUO_", "Texture/Player/UO_.png");
	TextureClass::get()->addTexture("playerUR_", "Texture/Player/UR_.png");

	for (int i = 0; i <= 5; i++) {
		std::string temp = std::to_string(i);
		TextureClass::get()->addTexture("playerDO_" + temp, "Texture/Player/DO_" + temp + ".png");
		TextureClass::get()->addTexture("playerRO_" + temp, "Texture/Player/RO_" + temp + ".png");
		TextureClass::get()->addTexture("playerUO_" + temp, "Texture/Player/UO_" + temp + ".png");
		TextureClass::get()->addTexture("playerUR_" + temp, "Texture/Player/UR_" + temp + ".png");
	}

	for (int i = 0; i <= 8; i++) {
		std::string temp = std::to_string(i);
		TextureClass::get()->addTexture("playerDodge_DO_" + temp, "Texture/Player/Dodge_DO_" + temp + ".png");
		TextureClass::get()->addTexture("playerDodge_RO_" + temp, "Texture/Player/Dodge_RO_" + temp + ".png");
		TextureClass::get()->addTexture("playerDodge_UO_" + temp, "Texture/Player/Dodge_UO_" + temp + ".png");
		TextureClass::get()->addTexture("playerDodge_UR_" + temp, "Texture/Player/Dodge_UR_" + temp + ".png");

		TextureClass::get()->addTexture("playerDeath_DE_" + temp, "Texture/Player/DE_" + temp + ".png");
	}

	TextureClass::get()->addTexture("playerHand", "Texture/Player/Hand.png");
	TextureClass::get()->addTexture("playerShadow", "Texture/Player/shadow.png");


	//Gun
	TextureClass::get()->addTexture("Enemy_Pistol", "Texture/Gun/Enemy_Pistol.png");
	TextureClass::get()->addTexture("Player_Pistol", "Texture/Gun/Player_Pistol.png");
	TextureClass::get()->addTexture("SMG", "Texture/Gun/smg.png");
	TextureClass::get()->addTexture("Reload", "Texture/Gun/reload.png");
	TextureClass::get()->addTexture("Reload_BG", "Texture/Gun/reload_bg.png");
	TextureClass::get()->addTexture("Enemy_Pistol_2", "Texture/Gun/enemy_rifle.png");
	TextureClass::get()->addTexture("Enemy_Boss_Gun", "Texture/Gun/boss_gun.png");

	//Bullet
	TextureClass::get()->addTexture("Enemy_Pistol_Bullet", "Texture/Bullet/bullet4.png");
	TextureClass::get()->addTexture("Player_Pistol_Bullet", "Texture/Bullet/bullet3.png");
	TextureClass::get()->addTexture("SMG_Bullet", "Texture/Bullet/bullet2.png");
	TextureClass::get()->addTexture("EnemyBullet2", "Texture/Bullet/bullet5.png");
	TextureClass::get()->addTexture("EnemyBullet3", "Texture/Bullet/bullet6.png");


	//HUD
	TextureClass::get()->addTexture("playerHealth", "Texture/HUD/player_health.png");

	//Enemy::SideKick1
	for (int i = 0; i < 6; i++)
	{
		TextureClass::get()->addTexture("enemyDown" + std::to_string(i), "Texture/SideKick1/D_" + std::to_string(i) + ".png");
		TextureClass::get()->addTexture("enemyLeft" + std::to_string(i), "Texture/SideKick1/L_" + std::to_string(i) + ".png");
	}

	for (int i = 0; i < 4; i++)
	{
		TextureClass::get()->addTexture("enemyUp" + std::to_string(i), "Texture/SideKick1/U_" + std::to_string(i) + ".png");
	}

	for (int i = 0; i < 7; i++)
	{
		TextureClass::get()->addTexture("enemyUpLeft" + std::to_string(i), "Texture/SideKick1/U_L_" + std::to_string(i) + ".png");
	}
	TextureClass::get()->addTexture("enemyIdleUp", "Texture/SideKick1/I_U.png");
	TextureClass::get()->addTexture("enemyIdleDown", "Texture/SideKick1/I_D.png");
	TextureClass::get()->addTexture("enemyHand", "Texture/SideKick1/hand.png");

	for (int i = 0; i < 5; i++)
	{
		TextureClass::get()->addTexture("enemyDeathDownRight" + std::to_string(i), "Texture/SideKick1/Death_D_R_" + std::to_string(i) + ".png");
	}

	//Enemy::SideKick2
	std::string filePath = "Texture/";
	std::string filePath2 = "SideKick2/";
	TextureClass::get()->addTexture("enemy2Idle", filePath + filePath2 + "I_0.png");
	for (int i = 0; i < 6; i++)
	{
		TextureClass::get()->addTexture("enemy2Up" + std::to_string(i), filePath + filePath2 + "U_" + std::to_string(i) + ".png");
		TextureClass::get()->addTexture("enemy2Down" + std::to_string(i), filePath + filePath2 + "D_" + std::to_string(i) + ".png");
		TextureClass::get()->addTexture("enemy2Left" + std::to_string(i), filePath + filePath2 + "L_" + std::to_string(i) + ".png");
		TextureClass::get()->addTexture("enemy2Right" + std::to_string(i), filePath + filePath2 + "R_" + std::to_string(i) + ".png");
		TextureClass::get()->addTexture("enemy2UpLeft" + std::to_string(i), filePath + filePath2 + "U_" + "L_" + std::to_string(i) + ".png");
		TextureClass::get()->addTexture("enemy2UpRight" + std::to_string(i), filePath + filePath2 + "U_" + "R_" + std::to_string(i) + ".png");
	}

	TextureClass::get()->addTexture("enemy2IdleUp", filePath + filePath2 + "I_U" + ".png");
	TextureClass::get()->addTexture("enemy2IdleDown", filePath + filePath2 + "I_D" + ".png");
	TextureClass::get()->addTexture("enemy2IdleUpLeft", filePath + filePath2 + "I_U_L" + ".png");
	TextureClass::get()->addTexture("enemy2IdleUpRight", filePath + filePath2 + "I_U_R" + ".png");
	TextureClass::get()->addTexture("enemy2IdleDownLeft", filePath + filePath2 + "I_D_L" + ".png");
	TextureClass::get()->addTexture("enemy2IdleDownRight", filePath + filePath2 + "I_D_R" + ".png");
	TextureClass::get()->addTexture("enemy2Hand", filePath + filePath2 + "hand.png");

	for (int i = 0; i < 6; i++)
	{
		TextureClass::get()->addTexture("enemy2Death" + std::to_string(i), filePath + filePath2 + "Death" + std::to_string(i) + ".png");
	}

	//Enemy::Boss
	TextureClass::get()->addTexture("enemy3IdleDown", "Texture/Boss/I_D.png");
	TextureClass::get()->addTexture("enemy3IdleUp", "Texture/Boss/I_U.png");
	for (int i = 0; i < 6; i++)
	{
		TextureClass::get()->addTexture("enemyRow1_" + std::to_string(i), "Texture/Boss/row1_" + std::to_string(i) + ".png");
		TextureClass::get()->addTexture("enemyRow2_" + std::to_string(i), "Texture/Boss/row2_" + std::to_string(i) + ".png");
		TextureClass::get()->addTexture("enemyRow3_" + std::to_string(i), "Texture/Boss/row3_" + std::to_string(i) + ".png");
		TextureClass::get()->addTexture("enemyRow4_" + std::to_string(i), "Texture/Boss/row4_" + std::to_string(i) + ".png");
	}
	for (int i = 0; i < 8; i++)
	{
		TextureClass::get()->addTexture("enemy3Death" + std::to_string(i), "Texture/Boss/Death_left" + std::to_string(i) + ".png");
	}

	
	//Menu
	TextureClass::get()->addTexture("GameOver", "Texture/Result/GameOverScreen.png");
	TextureClass::get()->addTexture("Victory", "Texture/Result/VictoryScreen.png");
	TextureClass::get()->addTexture("Continue", "Texture/Result/Continue.png");

	TextureClass::get()->addTexture("CompanyLogo", "Texture/Menu/CompanyLogo2.png");
	TextureClass::get()->addTexture("GameLogo", "Texture/Menu/GameLogo.png");
	TextureClass::get()->addTexture("SignIn", "Texture/Menu/SignIn.png");
	TextureClass::get()->addTexture("SignUp", "Texture/Menu/SignUp.png");
	TextureClass::get()->addTexture("Exit", "Texture/Menu/Exit.png");
	TextureClass::get()->addTexture("Background2", "Texture/SignIn/Menu3.jpg");
	TextureClass::get()->addTexture("Background3", "Texture/SignUp/Menu2.jpg");
	TextureClass::get()->addTexture("Background4", "Texture/Exit/Menu4.png");
	TextureClass::get()->addTexture("Background5", "Texture/PlayScreen/Menu5.jpg");
	TextureClass::get()->addTexture("InputBox1", "Texture/SignUp/inputBox.png");
	TextureClass::get()->addTexture("InputBox2", "Texture/SignUp/inputBox.png");
	TextureClass::get()->addTexture("InputBox3", "Texture/SignUp/inputBox.png");
	TextureClass::get()->addTexture("InputBox4", "Texture/SignUp/inputBox.png");
	TextureClass::get()->addTexture("submit", "Texture/SignUp/submit.png");
	TextureClass::get()->addTexture("enter", "Texture/SignIn/enter.png");
	TextureClass::get()->addTexture("play", "Texture/PlayScreen/play.png");

	for (int i = 0; i < 261; i++)
		TextureClass::get()->addTexture("Background_" + std::to_string(i), "Texture/Menu/file(" + std::to_string(i) + ")" + ".jpg");

}

TextureClass* TextureClass::get() {
	return instance;
}

void TextureClass::addTexture(const std::string label, const std::string& filename) {
	std::unique_ptr<sf::Texture> texture(new sf::Texture());
	if (!texture->loadFromFile(filename)) {
		throw std::runtime_error("TextureClass::addTexture() - Failed to load " + filename);
	}
	TextureMap.insert(std::make_pair(label, std::move(texture)));
}

sf::Texture& TextureClass::retrieveTexture(const std::string label) {
	auto  result = TextureMap.find(label);
	return *(result->second);
}