#pragma once
#include "sfwdraw.h"


void Crosshairs(unsigned tex)
{
	sfw::drawTexture(tex, sfw::getMouseX(), sfw::getMouseY(), sfw::getTextureWidth(tex) / 2.5, sfw::getTextureHeight(tex) / 2.5, 0, true, 0);

}



class Weapons
{
private:


	int damage = 10;
	int ammo = 25;
	int clipSize = 5;
	float reloadSpeed = 1.5f;
	float AOE = 0.0f;

public:

	//gets
	int getDamage() { return damage; }
	int getAmmo()   { return ammo;   }
	int getClipSize() { return clipSize; }
	float getReloadSpeed() { return reloadSpeed; }
	float getAOE() { return AOE; }
	
	//sets
	void setDamage(int newDamage) { damage = newDamage; }
	void setAmmo(int newAmmo) { ammo = newAmmo; }
	void setClipSize(int newClipSize) { clipSize = newClipSize; }
	void setReloadSpeed(float newReloadSpeed) { reloadSpeed = newReloadSpeed; }
	void setAOE(float newAOE) { AOE = newAOE; }

};