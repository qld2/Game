#pragma once
#include "ofMain.h"
//#include "CommonIncludes.h"

class Entity
{
protected:
	int translationalSpeed = 8;
	float rotationalSpeed = PI / 64;
	int SIZE = 50;
	
	float xLoc, yLoc;
	float orientation;
	int health;

	ofColor* arrowColor;
	ofColor* color;

	static const int boundaryCount = 4;
	
	float distanceTo(Entity* other);
	void refreshOrientation();
	virtual void drawHealthBar() = 0;
public:
	Entity(float x, float y, float o);
	Entity();
	~Entity();

	float getX();
	float getY();
	float getO();
	float* getBoundariesX();
	float* getBoundariesY();

	void draw();
	virtual void update() = 0;

	bool hasCollided(Entity* other);
};

