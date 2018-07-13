#pragma once
#include "Entity.h"
#include "Player.h"

class Enemy :
	public Entity
{
public:
	Enemy(float x, float y, float o, Player * p);
	Enemy();
	~Enemy();

	void update();
	void draw();
private:
	Player * player;

	void drawHealthBar();
	bool checkForCollision();
};

