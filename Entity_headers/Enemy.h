#pragma once
#include "Entity.h"
#include "Player.h"

class Enemy :
	public Entity
{
public:
	Enemy(float x, float y, float o, Player& p);
	~Enemy();

	void update();
	void draw();

	bool hasDied();
private:
	Player& player;

	void drawHealthBar() const;
	bool checkForCollision();
	bool checkForBullets();
};

