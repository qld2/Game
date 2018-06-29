#include "..\Entity_headers\Entity.h"
#include <cmath>

Entity::Entity(float x, float y, float o)
{
	xLoc = x;
	yLoc = y;
	orientation = PI / 4 + o;

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

	//drawHealthBar();

	ofTranslate(xLoc, yLoc);
	ofRotateRad(orientation);

	ofSetColor(*color);
	ofDrawRectangle(0, 0, SIZE, SIZE);

	ofTranslate(SIZE, 0);
	ofSetColor(*arrowColor);
	//ofDrawTriangle(p1, p2, p3);
	ofDrawRectangle(0, 0, 10, 10);

	ofTranslate(SIZE * -1, 0);
	ofRotateRad(-1 * orientation);
	ofTranslate(-1 * xLoc, -1 * yLoc);
}


float Entity::getX() {
	return xLoc;
}

float Entity::getY() {
	return yLoc;
}

void Entity::refreshOrientation() {
	if (orientation >= 2 * PI) orientation -= 2 * PI;
	if (orientation < 0) orientation += 2 * PI;
}