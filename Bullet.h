#pragma once
class Bullet
{
	float velx, vely;

public:
	Bullet(float a_x, float a_y, float dx, float dy, float lifespan)
	{
		
	}

	virtual void onCollision()
	{
	
	}
	virtual void update()
	{
		//x += velx * sfw::getDeltaTime();
		//y += vely * sfw::getDeltaTime();
	}

};