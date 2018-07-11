#include "..\Entity_headers\Player.h"

Player::Player(float x, float y, float o) : Entity(x, y, o)
{
	xLoc = x;
	yLoc = y;
	orientation = o;
	health = 10;

	color = new ofColor(0, 100, 255);

}

Player::Player()
{
	xLoc = 50;
	yLoc = 50;
	orientation = 0;
}


Player::~Player()
{
}

void Player::update()
{
	
	float* boundariesX = getBoundariesX();
	float* boundariesY = getBoundariesY();
	/*
	if (ofGetKeyPressed('j') && ofGetKeyPressed('l')) {

	}
	else if (ofGetKeyPressed('j')) {

		if (checkWallBoundaries(-1 * rotationalSpeed)) {
			orientation -= rotationalSpeed;
		}
	}
	else if (ofGetKeyPressed('l')) {

		if (checkWallBoundaries(rotationalSpeed)) {
			orientation += rotationalSpeed;
		}

	}

	if (ofGetKeyPressed('w') && ofGetKeyPressed('d')) {
		float deltaX = translationalSpeed * (sin(orientation) + sin(PI / 2 - orientation)) / sqrt(2);
		float deltaY = translationalSpeed * (cos(PI / 2 - orientation) - cos(orientation)) / sqrt(2);

		if (checkWallBoundaries(boundariesX, boundariesY, deltaX, deltaY)) {
			xLoc += deltaX;
			yLoc += deltaY;
		}
		else {
			reachBoundary(boundariesX, boundariesY, deltaX, deltaY);
		}

	}
	else if (ofGetKeyPressed('w') && ofGetKeyPressed('a')) {
		float deltaX = translationalSpeed * (sin(orientation) - sin(PI / 2 - orientation)) / sqrt(2);
		float deltaY = -1 * translationalSpeed * (cos(PI / 2 - orientation) + cos(orientation)) / sqrt(2);

		if (checkWallBoundaries(boundariesX, boundariesY, deltaX, deltaY)) {
			xLoc += deltaX;
			yLoc += deltaY;
		}
		else {
			reachBoundary(boundariesX, boundariesY, deltaX, deltaY);
		}

	}
	else if (ofGetKeyPressed('w') && ofGetKeyPressed('s')) {

	}
	else if (ofGetKeyPressed('s') && ofGetKeyPressed('d')) {
		float deltaX = translationalSpeed * (sin(PI / 2 - orientation) - sin(orientation)) / sqrt(2);
		float deltaY = translationalSpeed * (cos(orientation) + cos(PI / 2 - orientation)) / sqrt(2);

		if (checkWallBoundaries(boundariesX, boundariesY, deltaX, deltaY)) {
			xLoc += deltaX;
			yLoc += deltaY;
		}
		else {
			reachBoundary(boundariesX, boundariesY, deltaX, deltaY);
		}

	}
	else if (ofGetKeyPressed('s') && ofGetKeyPressed('a')) {
		float deltaX = -1 * translationalSpeed * (sin(orientation) + sin(PI / 2 - orientation)) / sqrt(2);
		float deltaY = translationalSpeed * (cos(orientation) - cos(PI / 2 - orientation)) / sqrt(2);

		if (checkWallBoundaries(boundariesX, boundariesY, deltaX, deltaY)) {
			xLoc += deltaX;
			yLoc += deltaY;
		}
		else {
			reachBoundary(boundariesX, boundariesY, deltaX, deltaY);
		}

	}
	else if (ofGetKeyPressed('a') && ofGetKeyPressed('d')) { 

	}
	else if (ofGetKeyPressed('w')) {
		float deltaX = translationalSpeed * sin(orientation);
		float deltaY = -1 * translationalSpeed * cos(orientation);

		if (checkWallBoundaries(boundariesX, boundariesY, deltaX, deltaY)) {
			xLoc += deltaX;
			yLoc += deltaY;
		}
		else {
			reachBoundary(boundariesX, boundariesY, deltaX, deltaY);
		}

	}
	else if (ofGetKeyPressed('d')) {
		float deltaX = translationalSpeed * sin(PI / 2 - orientation);
		float deltaY = translationalSpeed * cos(PI / 2 - orientation);

		if (checkWallBoundaries(boundariesX, boundariesY, deltaX, deltaY)) {
			xLoc += deltaX;
			yLoc += deltaY;
		}
		else {
			reachBoundary(boundariesX, boundariesY, deltaX, deltaY);
		}

	}
	else if (ofGetKeyPressed('s')) {
		float deltaX = -1 * translationalSpeed * sin(orientation);
		float deltaY = translationalSpeed * cos(orientation);

		if (checkWallBoundaries(boundariesX, boundariesY, deltaX, deltaY)) {
			xLoc += deltaX;
			yLoc += deltaY;
		}
		else {
			reachBoundary(boundariesX, boundariesY, deltaX, deltaY);
		}

	}
	else if (ofGetKeyPressed('a')) {
		float deltaX = -1 * translationalSpeed * sin(PI / 2 - orientation);
		float deltaY = -1 * translationalSpeed * cos(PI / 2 - orientation);

		if (checkWallBoundaries(boundariesX, boundariesY, deltaX, deltaY)) {
			xLoc += deltaX;
			yLoc += deltaY;
		}
		else {
			reachBoundary(boundariesX, boundariesY, deltaX, deltaY);
		}
	}

	if (orientation >= 360) orientation -= 360;

	draw();

	delete &boundariesX;
	delete &boundariesY;
	*/

	if (ofGetKeyPressed('j')) {

		if (checkWallBoundariesO(-1 * rotationalSpeed)) {
			orientation -= rotationalSpeed;
		}
	}
	else if (ofGetKeyPressed('l')) {

		if (checkWallBoundariesO(rotationalSpeed)) {
			orientation += rotationalSpeed;
		}

	}

	if (ofGetKeyPressed('w')) {
		float deltaX = translationalSpeed * cos(orientation);
		float deltaY = translationalSpeed * sin(orientation);

		if (checkWallBoundariesX(boundariesX, deltaX)) {
			xLoc += deltaX;
		}
		if (checkWallBoundariesY(boundariesY, deltaY)) {
			yLoc += deltaY;
		}
		else {
			reachBoundary(boundariesX, boundariesY, deltaX, deltaY);
		}
	} else if (ofGetKeyPressed('s')) {
		float deltaX = -translationalSpeed * cos(orientation);
		float deltaY = -translationalSpeed * sin(orientation);

		if (checkWallBoundariesX(boundariesX, deltaX)) {
			xLoc += deltaX;
		}
		if (checkWallBoundariesY(boundariesY, deltaY)) {
			yLoc += deltaY;
		}
		else {
			reachBoundary(boundariesX, boundariesY, deltaX, deltaY);
		}
	}
	updateHealth();
}


bool Player::checkWallBoundariesX(float* x, float deltaX) {

	for (int i = 0; i < boundaryCount; i++) {
		if (x[i] + deltaX <= 0 || x[i] + deltaX >= ofGetScreenWidth()) return false;
	}
	
	return true;
}

bool Player::checkWallBoundariesY(float* y, float deltaY) {

	for (int i = 0; i < boundaryCount; i++) {
		if (y[i] + deltaY <= 0 || y[i] + deltaY >= ofGetScreenHeight()) return false;
	}
	
	return true;
}

bool Player::checkWallBoundariesO(float deltaO) {

	for (float i = 0; i < 2 * PI; i += PI / 2) {
		float newX = xLoc + sqrt(2) * SIZE * sin(i - PI / 4 - orientation - deltaO) / 2;
		float newY = yLoc + sqrt(2) * SIZE * cos(i - PI / 4 - orientation - deltaO) / 2;

		if (newX <= 0 || newX >= ofGetScreenWidth()) return false;
		if (newY <= 0 || newY >= ofGetScreenHeight()) return false;
	}

	return true;
}

void Player::reachBoundary(float* x, float* y, float deltaX, float deltaY) {
	for (float i = .95; i > .1; i -= .05) {
		if (checkWallBoundariesX(x, i * deltaX)) {
			xLoc += i * deltaX;
			return;
		}
		if (checkWallBoundariesY(y, i * deltaY)) {
			yLoc += i * deltaY;
			return;
		}
	}
}

void Player::updateHealth() {
	
}

void Player::drawHealthBar() {
	ofSetColor(250, 0, 0);
	float unit = 50;
	int length = health * unit;
	ofDrawRectangle(175, 100, length, 65);
}
