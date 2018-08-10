#pragma once
#include "Stopwatch.h"
#include "Bullet.h"
#include "Entity_headers/Entity.h"

class Gun {

	Stopwatch fireTimer;
	float fireGap = 1;

	Stopwatch reloadTimer;
	float reloadTime = 2;

	int MAX_EXISTING = 15;
	int clipSize = 20;
	int bulletsOnPlayer = 200;
	int bulletsInClip = clipSize;
	vector<Bullet> bullets;
	
	ofTrueTypeFont gunGUI;

public:
	Gun();
	~Gun();

	void update();
	void draw() const;
	void drawGUI() const;

	void shoot(float x, float y, float o);
	void reload();

	vector<Bullet>& getBullets();
};

