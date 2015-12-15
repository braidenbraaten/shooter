#pragma once
#include "Player.h"
#include "enemies.h"
#include "Bullet.h"
#include <vector>
class GameState
{
	Player player;
	Enemies enemies;
	std::vector<Bullet> bullets;
public:

	void makeBullet(float x, float y, float dx, float dy, float lifespan)
	{
		
	}
	//void killBullet();
		//update objects
		//respond to events or special logic that changes how the game plays
		void update()
		{
	/*		player.update();
			enemies.UpdateEnemy();
			for (int i = 0; i < bullets.size(); ++i){bullets[i].update();}*/
			player.Update();
		}
		void draw() 
		{
			player.Draw();
			/*player.draw(); */
		}
	//store all objects
	//update all ( + collision)
	//draw all



	//needs some way to spawn / destroy bullets and enemies
	//level transitions / changes in gameplay

};