#include "Entity.h"
#include <cmath>

Entity::Entity(float x, float y, float o)
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
	vector<float>& boundariesX = getBoundariesX();
	vector<float>& boundariesY = getBoundariesY();

	if (ofGetKeyPressed('j')) {
		orientation -= ROTATIONAL_SPEED;
	}

	if (ofGetKeyPressed('l')) {
		orientation += ROTATIONAL_SPEED;
	}
	
	ofTranslate(xLoc, yLoc);
	ofRotate(orientation);

	if (ofGetKeyPressed('w')) {
		int deltaX = TRANSLATIONAL_SPEED * sin(ofDegToRad(orientation));
		int deltaY = -1 * TRANSLATIONAL_SPEED * cos(ofDegToRad(orientation));

		if (checkWallBoundaries(boundariesX, boundariesY, deltaX, deltaY)) {
			xLoc += deltaX;
			yLoc += deltaY;
		}
	}

	if (ofGetKeyPressed('d')) {
		int deltaX = TRANSLATIONAL_SPEED * sin(PI / 2 - ofDegToRad(orientation));
		int deltaY = TRANSLATIONAL_SPEED * cos(PI / 2 - ofDegToRad(orientation));

		if (checkWallBoundaries(boundariesX, boundariesY, deltaX, deltaY)) {
			xLoc += deltaX;
			yLoc += deltaY;
		}
	}

	if (ofGetKeyPressed('s')) {
		int deltaX = -1 * TRANSLATIONAL_SPEED * sin(ofDegToRad(orientation));
		int deltaY = TRANSLATIONAL_SPEED * cos(ofDegToRad(orientation));

		if (checkWallBoundaries(boundariesX, boundariesY, deltaX, deltaY)) {
			xLoc += deltaX;
			yLoc += deltaY;
		}
	}

	if (ofGetKeyPressed('a')) {
		int deltaX = -1 * TRANSLATIONAL_SPEED * sin(PI / 2 - ofDegToRad(orientation));
		int deltaY = -1 * TRANSLATIONAL_SPEED * cos(PI / 2 - ofDegToRad(orientation));

		if (checkWallBoundaries(boundariesX, boundariesY, deltaX, deltaY)) {
			xLoc += deltaX;
			yLoc += deltaY;
		}
	}

	

	ofDrawRectangle(0, 0, SIZE, SIZE);

	ofRotate(0);
	ofTranslate(0, 0);
	
	ofSetColor(255, 100, 0);
	
	for (int i = 0; i < 4; i++) {
		ofDrawRectangle(boundariesX[i], boundariesX[i], 3, 3);
	}
	
	ofSetColor(0, 100, 255);
	

	delete &boundariesX;
	delete &boundariesY;
}

vector<float>& Entity::getBoundariesX() {
	//vector<float> * result = new vector<float>({xLoc - SIZE / 2, xLoc + SIZE / 2, xLoc + SIZE / 2, xLoc - SIZE / 2});
	vector<float> * result = new vector<float>();
	
	for (float i = 0; i < 2 * PI; i += PI / 2) {
		result->push_back(xLoc + sqrt(2) * SIZE * sin(i - PI / 4 - orientation) / 2);
	}

	return (*result);
}

vector<float>& Entity::getBoundariesY() {
	vector<float> * result = new vector<float>();//({ yLoc + SIZE / 2, yLoc + SIZE / 2, yLoc - SIZE / 2, yLoc - SIZE / 2});
	
	for (float i = 0; i < 2 * PI; i += PI / 2) {
		result->push_back(yLoc + sqrt(2) * SIZE * cos(i - PI / 4 - orientation) / 2);
	}

	return (*result);
}

bool Entity::checkWallBoundaries(vector<float>& x, vector<float>& y, float deltaX, float deltaY) {
	for (int i = 0; i < x.size(); i++) {	
		if (x[i] + deltaX < 0 || x[i] + deltaX > ofGetScreenWidth()) return false;
	}
	
	for (int i = 0; i < y.size(); i++) {
		if (y[i] + deltaY < 0 || y[i] + deltaY > ofGetScreenHeight()) return false;
	}

	return true;
}
