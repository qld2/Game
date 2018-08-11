#include "..\Gun_headers\Bullet.h"

Bullet::Bullet(float x, float y, float theta, int d, float range, float speed) : xLoc(x), yLoc(y), orientation(theta), 
		damage(d), range(range), speed(speed) {
	distanceTraveled = 0;
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