#pragma once
#include "ofMain.h"
//#include "CommonIncludes.h"

class Entity
{
protected:	
	float xLoc, yLoc;
	float orientation;
	
	int translationalSpeed = 8;
	float rotationalSpeed = PI / 50;
	int size = 50;

	int maxHealth = 0;
	int health = 0;

	ofColor color;
	ofColor arrowColor;

	static const int boundaryCount = 4;
	
	float distanceTo(const Entity& other) const;
	void refreshOrientation();
	//virtual void drawHealthBar() = 0;
public:
	Entity(float x, float y, float o);
	Entity();
	~Entity();

	float getX() const;
	float getY() const;
	float getO() const;
	float* getBoundariesX() const;
	float* getBoundariesY() const;

	void draw() const;
	virtual void update() = 0;

	bool hasCollided(const Entity& other) const;
};

