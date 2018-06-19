#include "Entity.h"
#include <cmath>

Entity::Entity(int x, int y, int o)
{
	xLoc = x;
	yLoc = y;
	orientation = o;
}


Entity::~Entity()
{
}

void Entity::draw()
{

}

void Entity::update()
{
	if (ofGetKeyPressed('j')) {
		orientation -= ROTATIONAL_SPEED;
	}

	if (ofGetKeyPressed('l')) {
		orientation += ROTATIONAL_SPEED;
	}
	
	ofTranslate(xLoc, yLoc);
	ofRotate(orientation);

	if (ofGetKeyPressed('w')) {
		yLoc -= TRANSLATIONAL_SPEED * cos(ofDegToRad(orientation));
		xLoc += TRANSLATIONAL_SPEED * sin(ofDegToRad(orientation));
	}

	if (ofGetKeyPressed('d')) {
		yLoc += TRANSLATIONAL_SPEED * cos(PI / 2 - ofDegToRad(orientation));
		xLoc += TRANSLATIONAL_SPEED * sin(PI / 2 - ofDegToRad(orientation));
	}

	if (ofGetKeyPressed('s')) {
		yLoc += TRANSLATIONAL_SPEED * cos(ofDegToRad(orientation));
		xLoc -= TRANSLATIONAL_SPEED * sin(ofDegToRad(orientation));
	}

	if (ofGetKeyPressed('a')) {
		yLoc -= TRANSLATIONAL_SPEED * cos(PI / 2 - ofDegToRad(orientation));
		xLoc -= TRANSLATIONAL_SPEED * sin(PI / 2 - ofDegToRad(orientation));
	}

	ofDrawRectangle(0, 0, 50, 50);

	ofRotate(0);
	ofTranslate(0, 0);
}
