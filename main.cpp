
#include "sfwdraw.h"
#include "weapons.h"
#include "enemies.h"
//#include "Player.h"
//#include "Collision.h"
#include <ctime>
#include <vector>
#include <iostream>

//#include "GameState.h"
enum GameState{SPLASH, MAIN_MENU, PLAY, PAUSE, QUIT};
//GameState game;
const int screenWidth = 800;
const int screenHeight = 600;
GameState gameState;


void main()
{
	//Splash Textures

	//Menu Textures


	//In game Textures

	Collision collision;
	 
	sfw::initContext(screenWidth, screenHeight, "NSFW Draw");
	unsigned menuBackground = sfw::loadTextureMap("./res/mainMenuBackground.jpg");

	unsigned f = sfw::loadTextureMap("./res/tonc_font.png", 16, 6);
	unsigned d = sfw::loadTextureMap("./res/fontmap.png", 16, 16);
	unsigned r = sfw::loadTextureMap("./res/starWarsBackground.jpg");
	unsigned u = sfw::loadTextureMap("./res/crosshair.png");
	unsigned gun = sfw::loadTextureMap("./res/FPSWeapon.png");
	unsigned Firepistol = sfw::loadTextureMap("./res/weaponSprite.png", 2, 3);
	unsigned banana = sfw::loadTextureMap("./res/Banana.png");
	unsigned reticle = sfw::loadTextureMap("./res/reticleGreen.png");
	unsigned redReticle = sfw::loadTextureMap("./res/redcrosshair.png");
	unsigned enemyFighter = sfw::loadTextureMap("./res/enemyFighter.png");//enemy Fighter
	unsigned centerEnemyFighter = sfw::loadTextureMap("./res/centerTieFighter.png");

	unsigned friendlyFighter = sfw::loadTextureMap("./res/friendlyFighter.png");

	//Player Ship
	unsigned fpsView = sfw::loadTextureMap("./res/fpsShip.png");
	unsigned fpsFire = sfw::loadTextureMap("./res/fpsShipFire.png");
	unsigned shipWindow = sfw::loadTextureMap("./res/shipWindow.png");

	unsigned laser = sfw::loadTextureMap("./res/laser.png");
	unsigned hangar = sfw::loadTextureMap("./res/hangar.png");
	unsigned white = sfw::loadTextureMap("./res/white.jpg");
	unsigned glass = sfw::loadTextureMap("./res/optic.png");

	unsigned stars = sfw::loadTextureMap("./res/stars.jpg");
	gameState = SPLASH;
	//Creates the window

	float timer = 0;
	float speedTimer = 0;
	float shotTimer = 1;

	bool justJumped = false;
	float acc = 0;
	float retSpin = 0;
	float shipSpin = 0;

	float enemyTimer = 0;
	float enemySpawnInterval = 1.0f;



	
	//Line2D unitCircle;
	//unitCircle.P.X = 0;
	//unitCircle.P.Y = 0;
	//unitCircle.V.X = 360;
	//unitCircle.V.Y = 0;
	//
	//Enemies a(enemyFighter, 10, false);
	std::vector<Enemies> enemies;


	//enemies.push_back(Enemies(enemyFighter, 20, {700, 600}, {-1, -1}));

//	Player p1();
	
	float weapMov = 0;
	char c = '\0';

	sfw::setBackgroundColor(BLACK);

	while (sfw::stepContext())
	{
		timer += sfw::getDeltaTime();
		speedTimer += sfw::getDeltaTime() * sfw::getTime();
		srand(time(NULL));

		float RNG = rand() % 2 + 1;
		int RNG_SPAWN = rand() % 3 + 1;
		float RNG_ENEMY_SPEED = rand() % 5 + 3;

		switch (gameState)
		{
		case SPLASH:
			sfw::drawTexture(menuBackground, 0, 0, sfw::getTextureWidth(menuBackground), sfw::getTextureHeight(menuBackground), 0, false);

			//Splash();
		case MAIN_MENU:

			//sfw::drawTexture(menuBackground, 400, 300, sfw::getTextureWidth(menuBackground), sfw::getTextureHeight(menuBackground), 0, true);

			//Menu()
			break;
		case PLAY:
			



			break;
		case PAUSE:
			break;
		case QUIT:
			break;
		}


		
		sfw::drawTexture(r, (-500) - (sfw::getMouseX() / 3), 900 - (sfw::getMouseY() / 2), 1800, 1350, 0, false, 0);

		
		
			//sfw::drawTexture(hangar, (-100) - (sfw::getMouseX() / 3) - (timer * 35) , 900 - (sfw::getMouseY() / 2) + timer * 20, sfw::getTextureWidth(hangar) + timer * 20, sfw::getTextureHeight(hangar) + timer * 70, 0, false);
		if (timer < 4)
		{
			sfw::drawTexture(stars, 400, 300 - timer * 20, sfw::getTextureWidth(stars) - timer * 50, sfw::getTextureHeight(stars) + timer * 1600, 0, true);
		}
		else
		{
			justJumped = true;
		}

		//white screen flash
		if (justJumped == true)
		{
			if (timer > 4 && timer < 4.2)
			{
				sfw::drawTexture(white, 400, 300, sfw::getTextureWidth(white), sfw::getTextureHeight(white), 0, true);
			}
		}

		retSpin += sfw::getDeltaTime();

		for (int i = 0; i < enemies.size(); ++i)
		{
			if (enemies[i].getYPos() < screenHeight / 2)
			{
				enemies[i] = enemies.back();
				enemies.pop_back();
			}

		}
		
		// update enemies (makes sure that the enemies only spawn after the "jump" has occured
		if (justJumped == true)
		{
			for (int i = 0; i < enemies.size(); ++i)
			{
				enemies[i].UpdateEnemy();
			}
		}



		// spawn enemies
		enemyTimer += sfw::getDeltaTime();	// accumulate time
		if (enemyTimer > enemySpawnInterval)
		{
			enemyTimer -= enemySpawnInterval;

			switch (RNG_SPAWN)
			{
				//left
			case 1:
				enemies.push_back(Enemies(enemyFighter, 5, { 100,800 }, {  RNG_ENEMY_SPEED, -(RNG_ENEMY_SPEED) }));
				break;
				//center
			case 2:
				enemies.push_back(Enemies(centerEnemyFighter, 5, { 300,800 }, { 0, -(RNG_ENEMY_SPEED) }));
				break;
				//right
			case 3:
				enemies.push_back(Enemies(enemyFighter, 5, { 500,800 }, { -(RNG_ENEMY_SPEED), -(RNG_ENEMY_SPEED) }));
				break;
			}

			RNG_SPAWN = rand() % 3 + 1;

			switch (RNG_SPAWN)
			{
				//left
			case 1:
				enemies.push_back(Enemies(centerEnemyFighter, 5, { 100,800 }, { RNG_ENEMY_SPEED, -(RNG_ENEMY_SPEED) }));
				break;
				//center
			case 2:
				enemies.push_back(Enemies(centerEnemyFighter, 5, { 300,800 }, { 0, -(RNG_ENEMY_SPEED) }));
				break;
				//right
			case 3:
				enemies.push_back(Enemies(centerEnemyFighter, 5, { 500,800 }, { -(RNG_ENEMY_SPEED), -(RNG_ENEMY_SPEED) }));
				break;
			}
			
		}

		float prevMouseX = sfw::getMouseX() + retSpin;
		
		
		//shipSpin += sfw::getDeltaTime();
		shipSpin = -((sfw::getMouseX() -250) / 35);
		if (shipSpin > 25)
		{
			shipSpin = 25;
		}
		if (shipSpin < -25)
		{
			shipSpin = -25;
		}

		

		//sfw::drawTexture(banana, sfw::getTextureWidth(r) / 2, sfw::getTextureHeight(r) / 2, 1 * sfw::getDeltaTime(), .1 * sfw::getDeltaTime(), 0, true);


		//sfw::drawTexture(enemyFighter, 600, 600, sfw::getTextureWidth(enemyFighter) / 4, sfw::getTextureHeight(enemyFighter) / 4, 0, false, 0);
		

		//else if (weapMov < -3) weapMov += sfw::getDeltaTime() + 1;
		//else weapMov += sfw::getDeltaTime() + 1;
		
		

		//sfw::drawString(d, "TIME 4 FUN", 400, 300, 48, 48, -acc*24,'\0',MAGENTA);

		
	// keeps the hand from going to far up


 
		
		//sfw::drawString(d, "6", 400, 32, 24, 24);
		//sfw::drawString(d, "12", 400, 600 - 32, 24, 24);
		//sfw::drawString(d, "3", 800-32, 300, 24, 24);
		//sfw::drawString(d, "9", 32, 300, 24, 24);
		
		//Draws the glass window covering the ship and the blue hud in the center
		sfw::drawTexture(shipWindow, 300, 400, sfw::getTextureWidth(fpsView) + 250, sfw::getTextureHeight(fpsView), shipSpin, true);
		sfw::drawTexture(glass, sfw::getTextureWidth(fpsView) / 2.5, sfw::getTextureHeight(fpsView) / 2.5, sfw::getTextureWidth(glass) / 4, sfw::getTextureHeight(glass) / 5, shipSpin, true);

		if (sfw::getMouseButton(MOUSE_BUTTON_RIGHT))
		{
			sfw::drawTexture(reticle, sfw::getMouseX(), sfw::getMouseY(), sfw::getTextureWidth(reticle) / 2.5, sfw::getTextureHeight(reticle) / 2.5,retSpin * 45 , true, 0);
			sfw::drawTexture(redReticle, sfw::getMouseX(), sfw::getMouseY(), sfw::getTextureWidth(redReticle) / 2, sfw::getTextureHeight(redReticle) / 2, 0, true, 0);

			//Top left
			sfw::drawTexture(laser, sfw::getTextureWidth(fpsView) / 9 - 100, sfw::getTextureHeight(fpsView) - 200, 300, 74, shipSpin - 30, true, 0);
			//Top Right
			sfw::drawTexture(laser, 2 * sfw::getTextureWidth(fpsView) / 3, sfw::getTextureHeight(fpsView) - 200, 300, 74, -(shipSpin - 30), true, 0);
			//Bottom Left
			sfw::drawTexture(laser, sfw::getTextureWidth(fpsView) / 9, sfw::getTextureHeight(fpsView) / 3, 300, 74, -(shipSpin - 30), true, 0);
			//Bottom Right
			sfw::drawTexture(laser, 2 * sfw::getTextureWidth(fpsView) / 3, sfw::getTextureHeight(fpsView) / 3 , 300, 74, shipSpin - 30, true, 0);
			sfw::drawTexture(fpsFire, 400, 100 + RNG, sfw::getTextureWidth(fpsFire), sfw::getTextureHeight(fpsFire), shipSpin, true);

			

			// for each enemy

			for (int i = 0; i < enemies.size(); ++i)
			{
				//enemy hit circle
				Circle D(Vector2(enemies[i].getXPos(), enemies[i].getYPos()), enemies[i].getWidth() );
				//reticle hit circle
				Circle A(Vector2(sfw::getMouseX(), sfw::getMouseY()), 10);

				if (collision.CheckCircleCircleCollision(A,D))
				{
					enemies[i].takeDamage(1);
					std::cout << " HIT ! " << std::endl;
					std::cout << "Enemy hp: " << enemies[i].getEnemyHP() << std::endl;
					/// KILL THE ENEMY!
					if (enemies[i].getEnemyHP() <= 0)
					{
						//deletes the enemy
						enemies[i] = enemies.back();
						enemies.pop_back();
						

						//spawns a new enemy
						//enemies.push_back(Enemies(enemyFighter, 20, { 700, 600 }, { -1, -1 }));
					}
				}
			}
		

		}
		else
		{
			sfw::drawTexture(u, sfw::getMouseX(), sfw::getMouseY(), sfw::getTextureWidth(u) / 2, sfw::getTextureHeight(u) / 2);
			sfw::drawTexture(fpsView, 400, 100 + RNG, sfw::getTextureWidth(fpsView), sfw::getTextureHeight(fpsView), shipSpin, true);
		}

		//Ship Texture
		//sfw::drawString(d,"0" + killCount, sfw::getTextureWidth(fpsView) / 2.5, sfw::getTextureHeight(fpsView) / 2.5, 15, 15, shipSpin, '\0', RED);

		
	}

	sfw::termContext();
}