#include "Bullet.h"

Bullet::Bullet(float x, float y, float theta, int d) {
	xLoc = x;
	yLoc = y;
	orientation = theta;
	distanceTraveled = 0;
	damage = d;

	speed = 8;
	range = 400;
}

Bullet::~Bullet() {

}

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

bool Bullet::hasExpired() {
	if (distanceTraveled > range) {
		return true;
	}

	return false;
}

float Bullet::getX() {
	return xLoc;
}

float Bullet::getY() {
	return yLoc;
}

int Bullet::getDamage() {
	return damage;
}