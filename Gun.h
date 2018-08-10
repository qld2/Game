#pragma once
#include "Stopwatch.h"
#include "Bullet.h"
#include "Entity_headers/Entity.h"

class Gun {

	Stopwatch fireTimer;
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

protected:
	string name;

	float fireGap;
	float reloadTime;

	int clipSize;
	int bulletsOnPlayer;
	int bulletsInClip;

	float bulletRandomness;
};

