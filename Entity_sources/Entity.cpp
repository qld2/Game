#include "..\Entity_headers\Entity.h"
#include <cmath>

Entity::Entity(float x, float y, float o) : xLoc(x), yLoc(y), orientation(PI / 4 + o)
{
	color = ofColor(0, 100, 255);
	arrowColor = ofColor(255, 50);
}

Entity::Entity() : xLoc(100), yLoc(100), orientation(PI / 4)
{
	color = ofColor(0, 100, 255);
	arrowColor = ofColor(255, 50);
}

Entity::~Entity(){}

void Entity::draw() const {

	ofVec2f p1(0, -10);
	ofVec2f p2(15, 0);
	ofVec2f p3(0, 10);

	ofTranslate(xLoc, yLoc);
	ofRotateRad(orientation);

	ofSetColor(color);
	ofDrawRectangle(0, 0, size, size);

	ofTranslate(size, 0);
	ofSetColor(arrowColor);
	ofDrawTriangle(p1, p2, p3);

	ofTranslate(size * -1, 0);
	ofRotateRad(-1 * orientation);
	ofTranslate(-1 * xLoc, -1 * yLoc);
}

float* Entity::getBoundariesX() const {
	float* result = new float[boundaryCount];

	for (int i = 0; i < boundaryCount; i ++) {
		result[i] = xLoc + sqrt(2) * size * sin(i * PI / 2 - PI / 4 - orientation) / 2;
	}

	return result;
}

float* Entity::getBoundariesY() const {
	float* result = new float[boundaryCount];

	for (int i = 0; i < boundaryCount; i++) {
		result[i] = yLoc + sqrt(2) * size * cos(i * PI / 2 - PI / 4 - orientation) / 2;
	}

	return result;
}


float Entity::getX() const {
	return xLoc;
}

float Entity::getY() const {
	return yLoc;
}

float Entity::getO() const {
	return orientation;
}

void Entity::refreshOrientation() {
	if (orientation >= 2 * PI) orientation -= 2 * PI;
	if (orientation < 0) orientation += 2 * PI;
}

bool Entity::hasCollided(const Entity& other) const {
	float* xBoundaries = getBoundariesX();
	float* yBoundaries = getBoundariesY();
	float otherXLoc = other.getX();
	float otherYLoc = other.getY();
	float otherOrientation = other.getO();

	for (int i = 0; i < boundaryCount; i++) {
		int x = xBoundaries[i] - otherXLoc;
		int y = yBoundaries[i] - otherYLoc;

		float newX = cos(-otherOrientation) * x - sin(-otherOrientation) * y;
		float newY = sin(-otherOrientation) * x + cos(-otherOrientation) * y;

		if (newX >= -size / 2 && newX <= size / 2 &&
			newY >= -size / 2 && newY <= size / 2) return true;
	}

	return false;
}

float Entity::distanceTo(const Entity& other) const {
	float xLoc2 = other.getX();
	float yLoc2 = other.getY();

	return sqrt(pow((xLoc2 - xLoc), 2) + pow((yLoc2 - yLoc), 2));
}