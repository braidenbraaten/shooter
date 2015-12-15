#include "Player.h"



Player::Player()
{
	name = "default";
	health = 100;
	PlayerPos.X = 400;
	PlayerPos.Y = 300;
}
Player::Player(unsigned int handle, std::string PlayerName, int StartingHP, float xPos, float yPos)
{
	player_handle = handle;
	name = PlayerName;
	health = StartingHP;
	PlayerPos.X = xPos;
	PlayerPos.Y = yPos;
}


//        DRAW
void Player::Draw()
{
	sfw::drawTexture(player_handle, PlayerPos.X, PlayerPos.Y, sfw::getTextureWidth(player_handle), sfw::getTextureHeight(player_handle), 0, false);
}

void Player::Update()
{

	if (PlayerPos.X < 0  ){PlayerPos.X = 0;  }
	if (PlayerPos.X > 800){PlayerPos.X = 800;}
	if (PlayerPos.Y < 0  ){PlayerPos.Y = 0;  }
	if (PlayerPos.Y > 600){PlayerPos.Y = 600;}

	if (health <= 0)
	{
		isAlive = false;
	}

}

//         ////SETS\\\\\

void Player::SetPlayerName(std::string newName){name = newName;}

void Player::SetPlayerPos(float x, float y){PlayerPos.X = x; PlayerPos.Y = y;}
void Player::SetPosX(float x)			   {PlayerPos.X = x;}
void Player::SetPosY(float y)			   {PlayerPos.Y = y;}

void Player::SetHP(int newHP){health = newHP;}

//          ///GETS\\\

std::string Player::GetName(){return name;}

float Player::GetPlayerPos(){return PlayerPos.X, PlayerPos.Y;}
int   Player::GetHP()       {return health;}
