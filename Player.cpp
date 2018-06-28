#include "Player.h"

Player* Player::p = nullptr;

Player::Player(float x, float y, float o) : Entity(x, y, o)
{
	xLoc = x;
	yLoc = y;
	orientation = o;

	color = new ofColor(0, 100, 255);

	p = this;
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
	vector<float>& boundariesX = getBoundariesX();
	vector<float>& boundariesY = getBoundariesY();

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
}

vector<float>& Player::getBoundariesX() {
	vector<float> * result = new vector<float>();

	for (float i = 0; i < 2 * PI; i += PI / 2) {
		result->push_back(xLoc + sqrt(2) * SIZE * sin(i - PI / 4 - orientation) / 2);
	}

	return (*result);
}

vector<float>& Player::getBoundariesY() {
	vector<float> * result = new vector<float>();

	for (float i = 0; i < 2 * PI; i += PI / 2) {
		result->push_back(yLoc + sqrt(2) * SIZE * cos(i - PI / 4 - orientation) / 2);
	}

	return (*result);
}

bool Player::checkWallBoundaries(vector<float>& x, vector<float>& y, float deltaX, float deltaY) {

	for (int i = 0; i < x.size(); i++) {
		if (x[i] + deltaX <= 0 || x[i] + deltaX >= ofGetScreenWidth()) return false;
	}

	for (int i = 0; i < y.size(); i++) {
		if (y[i] + deltaY <= 0 || y[i] + deltaY >= ofGetScreenHeight()) return false;
	}

	return true;
}

bool Player::checkWallBoundaries(float deltaO) {

	for (float i = 0; i < 2 * PI; i += PI / 2) {
		float newX = xLoc + sqrt(2) * SIZE * sin(i - PI / 4 - orientation - deltaO) / 2;
		float newY = yLoc + sqrt(2) * SIZE * cos(i - PI / 4 - orientation - deltaO) / 2;

		if (newX <= 0 || newX >= ofGetScreenWidth()) return false;
		if (newY <= 0 || newY >= ofGetScreenHeight()) return false;
	}

	return true;
}

void Player::reachBoundary(vector<float>& x, vector<float>& y, float deltaX, float deltaY) {
	for (float i = .95; i > .1; i -= .05) {
		if (checkWallBoundaries(x, y, i * deltaX, i * deltaY)) {
			xLoc += i * deltaX;
			yLoc += i * deltaY;
			return;
		}
	}
}
