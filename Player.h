#ifndef Player_H
#define Player_H
#include <iostream>
#include "Collision.h"
#include "sfwdraw.h"
class Player
{
private:
	std::string name;
	Point PlayerPos;
	int health;
	unsigned int player_handle;
	bool isAlive = true;
	
public:
	Player();
	Player(unsigned int handle, std::string PlayerName, int StartingHP, float xPos, float yPos);
	//Get
	std::string GetName();
	float GetPlayerPos();
	int GetHP();
	//Sets
	void SetPlayerName(std::string newName);
	void SetPlayerPos(float newX, float newY);
	void SetPosX(float newX);
	void SetPosY(float newY);
	void SetHP(int newHP);



	void Draw();
	void Update();
};

#endif