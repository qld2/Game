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

private:
	Player * player;

	void drawHealthBar() override;
	bool checkForCollision();
};

