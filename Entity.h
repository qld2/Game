#pragma once
#include "ofMain.h"

class Entity
{
	const int TRANSLATIONAL_SPEED = 4;
	const int ROTATIONAL_SPEED = 4;
	float xLoc, yLoc;
	float orientation;

public:
	Entity(int x, int y, int o);
	~Entity();

	void draw();
	void update();
};

