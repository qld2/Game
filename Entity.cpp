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
	ofVec2f p1(10, 0);
	ofVec2f p2(0, -15);
	ofVec2f p3(-10, 0);

	
	ofTranslate(xLoc, yLoc);
	ofRotate(orientation);

	ofSetColor(0, 100, 255);
	ofDrawRectangle(0, 0, SIZE, SIZE);

	ofTranslate(0, SIZE * -1);
	ofSetColor(255, 50);
	ofDrawTriangle(p1, p2, p3);

}

void Entity::update()
{
	vector<float>& boundariesX = getBoundariesX();
	vector<float>& boundariesY = getBoundariesY();

	if (ofGetKeyPressed('j') && ofGetKeyPressed('l')) {

	} else if (ofGetKeyPressed('j')) {
		
		if (checkWallBoundaries(-1 * ROTATIONAL_SPEED)) {
			orientation -= ROTATIONAL_SPEED;
		}
	}else if (ofGetKeyPressed('l')) {
		
		if (checkWallBoundaries(ROTATIONAL_SPEED)) {
			orientation += ROTATIONAL_SPEED;
		}

	}

	if (ofGetKeyPressed('w') && ofGetKeyPressed('d')) {
		float deltaX = TRANSLATIONAL_SPEED * (sin(ofDegToRad(orientation)) + sin(PI / 2 - ofDegToRad(orientation))) / sqrt(2);
		float deltaY = TRANSLATIONAL_SPEED * (cos(PI / 2 - ofDegToRad(orientation)) - cos(ofDegToRad(orientation))) / sqrt(2);

		if (checkWallBoundaries(boundariesX, boundariesY, deltaX, deltaY)) {
			xLoc += deltaX;
			yLoc += deltaY;
		} else {
			reachBoundary(boundariesX, boundariesY, deltaX, deltaY);
		}

	} else if (ofGetKeyPressed('w') && ofGetKeyPressed('a')) {
		float deltaX = TRANSLATIONAL_SPEED * (sin(ofDegToRad(orientation)) - sin(PI / 2 - ofDegToRad(orientation))) / sqrt(2);
		float deltaY = -1 * TRANSLATIONAL_SPEED * (cos(PI / 2 - ofDegToRad(orientation)) + cos(ofDegToRad(orientation))) / sqrt(2);

		if (checkWallBoundaries(boundariesX, boundariesY, deltaX, deltaY)) {
			xLoc += deltaX;
			yLoc += deltaY;
		} else {
			reachBoundary(boundariesX, boundariesY, deltaX, deltaY);
		}

	} else if (ofGetKeyPressed('w') && ofGetKeyPressed('s')){
		
	} else if (ofGetKeyPressed('s') && ofGetKeyPressed('d')) {
		float deltaX = TRANSLATIONAL_SPEED * (sin(PI / 2 - ofDegToRad(orientation)) - sin(ofDegToRad(orientation))) / sqrt(2);
		float deltaY = TRANSLATIONAL_SPEED * (cos(ofDegToRad(orientation)) + cos(PI / 2 - ofDegToRad(orientation))) / sqrt(2);

		if (checkWallBoundaries(boundariesX, boundariesY, deltaX, deltaY)) {
			xLoc += deltaX;
			yLoc += deltaY;
		} else {
			reachBoundary(boundariesX, boundariesY, deltaX, deltaY);
		}

	} else if (ofGetKeyPressed('s') && ofGetKeyPressed('a')) {
		float deltaX = -1 * TRANSLATIONAL_SPEED * (sin(ofDegToRad(orientation)) + sin(PI / 2 - ofDegToRad(orientation))) / sqrt(2);
		float deltaY = TRANSLATIONAL_SPEED * (cos(ofDegToRad(orientation)) - cos(PI / 2 - ofDegToRad(orientation))) / sqrt(2);

		if (checkWallBoundaries(boundariesX, boundariesY, deltaX, deltaY)) {
			xLoc += deltaX;
			yLoc += deltaY;
		} else {
			reachBoundary(boundariesX, boundariesY, deltaX, deltaY);
		}

	} else if (ofGetKeyPressed('a') && ofGetKeyPressed('d')) {

	} else if (ofGetKeyPressed('w')) {
		float deltaX = TRANSLATIONAL_SPEED * sin(ofDegToRad(orientation));
		float deltaY = -1 * TRANSLATIONAL_SPEED * cos(ofDegToRad(orientation));

		if (checkWallBoundaries(boundariesX, boundariesY, deltaX, deltaY)) {
			xLoc += deltaX;
			yLoc += deltaY;
		} else {
			reachBoundary(boundariesX, boundariesY, deltaX, deltaY);
		}

	}else if (ofGetKeyPressed('d')) {
		float deltaX = TRANSLATIONAL_SPEED * sin(PI / 2 - ofDegToRad(orientation));
		float deltaY = TRANSLATIONAL_SPEED * cos(PI / 2 - ofDegToRad(orientation));

		if (checkWallBoundaries(boundariesX, boundariesY, deltaX, deltaY)) {
			xLoc += deltaX;
			yLoc += deltaY;
		} else {
			reachBoundary(boundariesX, boundariesY, deltaX, deltaY);
		}

	}else if (ofGetKeyPressed('s')) {
		float deltaX = -1 * TRANSLATIONAL_SPEED * sin(ofDegToRad(orientation));
		float deltaY = TRANSLATIONAL_SPEED * cos(ofDegToRad(orientation));

		if (checkWallBoundaries(boundariesX, boundariesY, deltaX, deltaY)) {
			xLoc += deltaX;
			yLoc += deltaY;
		} else {
			reachBoundary(boundariesX, boundariesY, deltaX, deltaY);
		}

	}else if (ofGetKeyPressed('a')) {
		float deltaX = -1 * TRANSLATIONAL_SPEED * sin(PI / 2 - ofDegToRad(orientation));
		float deltaY = -1 * TRANSLATIONAL_SPEED * cos(PI / 2 - ofDegToRad(orientation));

		if (checkWallBoundaries(boundariesX, boundariesY, deltaX, deltaY)) {
			xLoc += deltaX;
			yLoc += deltaY;
		} else {
			reachBoundary(boundariesX, boundariesY, deltaX, deltaY);
		}
	}

	draw();

	delete &boundariesX;
	delete &boundariesY;
}

vector<float>& Entity::getBoundariesX() {
	vector<float> * result = new vector<float>();
	
	for (float i = 0; i < 2 * PI; i += PI / 2) {
		result->push_back(xLoc + sqrt(2) * SIZE * sin(i - PI / 4 - ofDegToRad(orientation)) / 2);
	}

	return (*result);
}

vector<float>& Entity::getBoundariesY() {
	vector<float> * result = new vector<float>();

	for (float i = 0; i < 2 * PI; i += PI / 2) {
		result->push_back(yLoc + sqrt(2) * SIZE * cos(i - PI / 4 - ofDegToRad(orientation)) / 2);
	}

	return (*result);
}

bool Entity::checkWallBoundaries(vector<float>& x, vector<float>& y, float deltaX, float deltaY) {
	
	for (int i = 0; i < x.size(); i++) {
		if (x[i] + deltaX <= 0 || x[i] + deltaX >= ofGetScreenWidth()) return false;
	}
	
	for (int i = 0; i < y.size(); i++) {
		if (y[i] + deltaY <= 0 || y[i] + deltaY >= ofGetScreenHeight()) return false;
	}

	return true;
}

bool Entity::checkWallBoundaries(float deltaO) {

	for (float i = 0; i < 2 * PI; i += PI / 2) {
		float newX = xLoc + sqrt(2) * SIZE * sin(i - PI / 4 - ofDegToRad(orientation + deltaO)) / 2;
		float newY = yLoc + sqrt(2) * SIZE * cos(i - PI / 4 - ofDegToRad(orientation + deltaO)) / 2;
			
		if (newX <= 0 || newX >= ofGetScreenWidth()) return false;		
		if (newY <= 0 || newY >= ofGetScreenHeight()) return false;
	}

	return true;
}

void Entity::reachBoundary(vector<float>& x, vector<float>& y, float deltaX, float deltaY) {
	for (float i = .95; i > .1; i -= .05) {
		if (checkWallBoundaries(x, y, i * deltaX, i * deltaY)) {
			xLoc += i * deltaX;
			yLoc += i * deltaY;
			return;
		}
	}
}
