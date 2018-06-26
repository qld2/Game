#pragma once
#include "ofMain.h"

class Entity
{
protected:
	int translationalSpeed = 8;
	int rotationalSpeed = 4;
	int SIZE = 50;
	float xLoc, yLoc;
	float orientation;

public:
	ofColor* arrowColor;
	ofColor* color;

public:
	Entity(float x, float y, float o);
	Entity();
	~Entity();

	void draw();
	virtual void update() = 0;

private:

};

