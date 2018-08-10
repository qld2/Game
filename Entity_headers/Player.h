#pragma once
#include "Entity.h"
#include "..\Stopwatch.h"
#include "..\Gun.h"

class Player :
	public Entity	
{
	Gun gun;
public:
	Player(float x, float y, float o);
	Player();
	~Player();

	Stopwatch healthTimer;
	
	void update() override;
	void draw() const;
	void drawGUI() const;

	void updateHealth();
	
	
	void shoot();

	vector<Bullet>& getBullets();
	int getHealth() const;
private:
	bool checkWallBoundariesX(float* x, float newX);
	bool checkWallBoundariesY(float* y, float newY);
	bool checkWallBoundariesO(float deltaO);
	void reachBoundary(float* x, float* y, float deltaX, float deltaY);
	
	void drawHealthBar() const;
};

