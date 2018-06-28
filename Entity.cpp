#include "Entity.h"
#include <cmath>

Entity::Entity(float x, float y, float o)
{
	xLoc = x;
	yLoc = y;
	orientation = o;

	arrowColor = new ofColor(255, 50);
	color = new ofColor(0, 100, 255);
}

Entity::Entity()
{
	xLoc = 150;
	yLoc = 150;
	orientation = 0;

	arrowColor = new ofColor(255, 50);
	color = new ofColor(255, 50);
}

Entity::~Entity()
{
	delete arrowColor;
	delete color;
}

void Entity::draw()
{
	ofVec2f p1(10, 0);
	ofVec2f p2(0, -15);
	ofVec2f p3(-10, 0);


	ofTranslate(xLoc, yLoc);
	ofRotateRad(orientation);

	ofSetColor(*color);
	ofDrawRectangle(0, 0, SIZE, SIZE);

	ofTranslate(0, SIZE * -1);
	ofSetColor(*arrowColor);
	ofDrawTriangle(p1, p2, p3);

	ofTranslate(0, SIZE);
	ofRotateRad(-1 * orientation);
	ofTranslate(-1 * xLoc, -1 * yLoc);
}


float Entity::getX() {
	return xLoc;
}

float Entity::getY() {
	return yLoc;
}