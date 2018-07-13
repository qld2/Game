#include "Bullet.h"

Bullet::Bullet(float x, float y, float theta) {
	xLoc = x;
	yLoc = y;
	orientation = theta;
	speed = 8;

	deathClock = new Stopwatch();
}

Bullet::~Bullet() {

}

void Bullet::update() {
	xLoc += speed * cos(orientation);
	yLoc += speed * sin(orientation);
}

void Bullet::draw() {
	cout << xLoc << ", " << yLoc << endl;
	ofSetColor(250, 0, 0);
	ofDrawRectangle(xLoc, yLoc, 20, 20);
}

bool Bullet::hasDied() {
	if (deathClock->read() > 1e9) {
		return true;
	}

	return false;
}