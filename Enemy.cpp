#include "Enemy.h"
#include "Player.h"

Enemy::Enemy(float x, float y, float o) : Entity(x, y, o)
{
	xLoc = x;
	yLoc = y;
	orientation = o;

	translationalSpeed = 2;

	color = new ofColor(255, 100, 0);
}

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

void Enemy::update() {
	float newO;
	float x = p->getX() - xLoc;
	float y = yLoc - p->getY();

	if (x > 0 && y > 0) {
		cout << "q1" << endl;
		newO = 90 - ofRadToDeg(atan2(yLoc - p->getY(), p->getX() - xLoc));
	}
	else if (x > 0 && y < 0) {
		cout << "q4" << endl;
		newO = ofRadToDeg(atan2(p->getY() - yLoc, p->getX() - xLoc));
	}
	else if (x < 0 && y > 0) {
		cout << "q2" << endl;
		newO = ofRadToDeg(atan2(yLoc - p->getY(), xLoc - p->getX())) + 270;
	}
	else {
		cout << "q3" << endl;
		newO = 90 - ofRadToDeg(atan2(p->getY() - yLoc, p->getX() - xLoc)) + 180;
	}

	if (newO > orientation) {
		orientation -= rotationalSpeed;
	}
	else if (newO < orientation) {
		orientation += rotationalSpeed;
	}
	
	//xLoc -= translationalSpeed * sin(ofDegToRad(orientation));
	//yLoc -= -1 * translationalSpeed * cos(ofDegToRad(orientation));

	draw();
}
