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

	float* x = getBoundariesX();
	float* y = getBoundariesY();

	for (int i = 0; i < boundaryCount; i++) {
		ofDrawRectangle(x[i], y[i], 20, 20);
	}

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

float* Entity::getBoundariesX() {
	float* result = new float[boundaryCount];

	for (int i = 0; i < boundaryCount; i ++) {
		result[i] = xLoc + sqrt(2) * SIZE * sin(i * PI / 2 - PI / 4 - orientation) / 2;
	}

	return result;
}

float* Entity::getBoundariesY() {
	float* result = new float[boundaryCount];

	for (int i = 0; i < boundaryCount; i++) {
		result[i] = yLoc + sqrt(2) * SIZE * cos(i * PI / 2 - PI / 4 - orientation) / 2;
	}

	return result;
}


float Entity::getX() {
	return xLoc;
}

float Entity::getY() {
	return yLoc;
}

float Entity::getO() {
	return orientation;
}

void Entity::refreshOrientation() {
	if (orientation >= 2 * PI) orientation -= 2 * PI;
	if (orientation < 0) orientation += 2 * PI;
}

bool Entity::hasCollided(Entity* other) {
	float* xBoundaries = getBoundariesX();
	float* yBoundaries = getBoundariesY();
	float otherXLoc = other->getX();
	float otherYLoc = other->getY();
	float otherOrientation = other->getO();

	for (int i = 0; i < boundaryCount; i++) {
		int x = xBoundaries[i] - otherXLoc;
		int y = yBoundaries[i] - otherYLoc;

		float newX = cos(-otherOrientation) * x - sin(-otherOrientation) * y;
		float newY = sin(-otherOrientation) * x + cos(-otherOrientation) * y;

		if (newX >= -SIZE / 2 && newX <= SIZE / 2 &&
			newY >= -SIZE / 2 && newY <= SIZE / 2) return true;
	}

	return false;
}

float Entity::distanceTo(Entity* other) {
	float xLoc2 = other->getX();
	float yLoc2 = other->getY();

	return sqrt(pow((xLoc2 - xLoc), 2) + pow((yLoc2 - yLoc), 2));
}