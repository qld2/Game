#pragma once
#include "ofMain.h"
//#include "CommonIncludes.h"

class Player;

class Entity
{
protected:
	int translationalSpeed = 8;
	int rotationalSpeed = 4;
	int SIZE = 50;
	float xLoc, yLoc;
	float orientation;

	static Player * p;

	ofColor* arrowColor;
	ofColor* color;

public:
	Entity(float x, float y, float o);
	Entity();
	~Entity();

	float getX();
	float getY();

	void draw();
	virtual void update() = 0;

private:

};

