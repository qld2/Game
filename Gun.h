#pragma once
#include "Stopwatch.h"
#include "Bullet.h"
#include "Entity_headers/Entity.h"

class Gun
{
	Stopwatch* fireTimer;
	float fireGap = .1;

	int MAX_EXISTING = 15;
	vector<Bullet*> bullets;
	

public:
	Gun();
	~Gun();

	void update();
	void draw();

	void shoot(float x, float y, float o);

	vector<Bullet*>& getBullets();
};

