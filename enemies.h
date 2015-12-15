#pragma once

//#include "sfwdraw.h"
#include "Collision.h"
#include "sfwdraw.h"


class Enemies
{
private:
	int health = 0;
	Point enemyPos;
	Point velocity;
	Point prevEnemyPos;
	Collision enemyCollision;
	float scale = 1.0f;
	bool isAlive = true;
	float angle = 0;
	unsigned int m_handle;
	int width;
	int height;
	Enemies();
public:
	Enemies(unsigned int handle, int startingHP, Point startPos, Point startVel)
	{
		m_handle = handle;
		setHP(startingHP);
		enemyPos.X = startPos.X; // <- change these position 
		enemyPos.Y = startPos.Y;

		velocity.X = startVel.X;
		velocity.Y = startVel.Y;

		width = sfw::getTextureWidth(m_handle) / 4;
		height = sfw::getTextureHeight(m_handle) / 4;
		//Rectangle(enemyPos.X, enemyPos.Y, width, height);
		
	}

	void Draw(float angle = 0)
	{
		sfw::drawTexture(m_handle, enemyPos.X, enemyPos.Y, (velocity.X < 0)? width : -width, height, angle, false, 0);
	}

	void UpdateEnemy(float spin = 0)
	{
		//scale += sfw::getDeltaTime();
		//enemyPos.X += sfw::getDeltaTime() / 4;
		angle = spin;
		

		enemyPos.X += velocity.X;
		enemyPos.Y += velocity.Y;

		prevEnemyPos.X = enemyPos.X;
		prevEnemyPos.Y = enemyPos.Y;

		
		

		if (health <= 0)
		{
			isAlive = false;
			Draw(angle * 180);
		}
		else
		{
			Draw(spin);
		}

		if (isAlive == false)
		{
			
		}
	
	}

	int getEnemyHP()
	{
		return health;
	}
	void setHP(int newHP)
	{
		health = newHP;
	}

	void takeDamage(int damage)
	{
		health -= damage;
	}

	float getXPos()
	{
		return enemyPos.X;
	}
	float getYPos()
	{
		return enemyPos.Y;
	}

	float getWidth()
	{
		return width;
	}

	float getHeight()
	{
		return height;
	}
	
};