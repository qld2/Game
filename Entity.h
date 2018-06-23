#pragma once
#include "ofMain.h"

class Entity
{
	const int TRANSLATIONAL_SPEED = 8;
	const int ROTATIONAL_SPEED = 4;
	const int SIZE = 50;
	float xLoc, yLoc;
	float orientation;

public:
	Entity(float x, float y, float o);
	~Entity();

	void draw();
	void update();

private:
	vector<float>& getBoundariesX();
	vector<float>& getBoundariesY();
	bool checkWallBoundaries(vector<float>& x, vector<float>& y, float deltaX, float deltaY);
};

