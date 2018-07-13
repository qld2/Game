#pragma once
#include "Entity.h"
#include "..\Stopwatch.h"
#include "..\Gun.h"

class Player :
	public Entity	
{
	Gun* gun;
public:
	Player(float x, float y, float o);
	Player();
	~Player();

	Stopwatch* healthTimer;
	
	void update() override;
	void draw();
	void updateHealth();
	void drawHealthBar();
	void shoot();
private:
	bool checkWallBoundariesX(float* x, float newX);
	bool checkWallBoundariesY(float* y, float newY);
	bool checkWallBoundariesO(float deltaO);
	void reachBoundary(float* x, float* y, float deltaX, float deltaY);
};

