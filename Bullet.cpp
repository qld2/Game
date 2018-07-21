#include "Bullet.h"

Bullet::Bullet(float x, float y, float theta, int d) : xLoc(x), yLoc(y), orientation(theta), damage(d) {
	distanceTraveled = 0;
	speed = 8;
	range = 1000;
}

Bullet::~Bullet() {

}

//---------------------------------------------------------------------------


void Bullet::update() {
	float deltaX = speed * cos(orientation);
	float deltaY = speed * sin(orientation);

	xLoc += deltaX;
	yLoc += deltaY;
	distanceTraveled += sqrt(pow(deltaX, 2) + pow(deltaY, 2));
}

void Bullet::draw() const {
	ofSetColor(250, 0, 0);
	ofDrawRectangle(xLoc, yLoc, 20, 20);
}

//---------------------------------------------------------------------------


float Bullet::getX() const {
	return xLoc;
}

float Bullet::getY() const {
	return yLoc;
}

int Bullet::getDamage() const {
	return damage;
}

bool Bullet::hasExpired() const {
	if (distanceTraveled > range) {
		return true;
	}

	return false;
}