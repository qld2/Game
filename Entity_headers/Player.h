#pragma once
#include "Entity.h"
class Player :
	public Entity	
{
public:
	Player(float x, float y, float o);
	Player();
	~Player();

	void update() override;

private:
	bool checkWallBoundariesX(float* x, float newX);
	bool checkWallBoundariesY(float* y, float newY);
	bool checkWallBoundariesO(float deltaO);
	void reachBoundary(float* x, float* y, float deltaX, float deltaY);

	void drawHealthBar() override;
	void updateHealth();
};

