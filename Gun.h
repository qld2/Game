#pragma once
#include "Stopwatch.h"
#include "Bullet.h"

class Gun
{
	Stopwatch* fireTimer;
	float fireGap = 1e9;

	int MAX_EXISTING = 15;
	int bulletsExisting = 0;
	Bullet** bullets = new Bullet*[MAX_EXISTING];
	

public:
	Gun();
	~Gun();

	void update();
	void draw();

	void shoot(float x, float y, float o);
};

