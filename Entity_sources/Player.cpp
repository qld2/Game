#include "..\Entity_headers\Player.h"


Player::Player(float x, float y, float o) : Entity(x, y, o)
{
	xLoc = x;
	yLoc = y;
	orientation = o;
	health = 3;
	maxHealth = 3;

	color = new ofColor(0, 100, 255);
	gun = new Gun();
	healthTimer = new Stopwatch();
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

	gun->update();
}

void Player::updateHealth() {
	health -= 1;
}

void Player::draw() {
	gun->draw();

	Entity::draw();
}

void Player::drawHealthBar() {
	float fullLength = 500;
	float length = health * fullLength / maxHealth;
	ofSetColor(250, 250, 250, 100);
	ofDrawRectangle(300, 50, fullLength, 50);
	ofSetColor(250, 0, 0);
	ofDrawRectangle(50 + length / 2, 50, length, 50);
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

void Player::shoot() {
	gun->shoot(xLoc, yLoc, orientation);
}
