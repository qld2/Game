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
	if (orientation >= 360) orientation -= 360;
	if (orientation < 0) orientation += 360;
	
	float x = p->getX() - xLoc;
	float y = p->getY() - yLoc;
	float newO = 90 + ofRadToDeg(atan2(y, x));

	if (newO >= 360) newO -= 360;
	if (newO < 0) newO += 360;

	float n = cos(ofDegToRad(-orientation)) * sin(ofDegToRad(newO)) + sin(ofDegToRad(-orientation)) * cos(ofDegToRad(newO));

	if (n < 0) {
		orientation -= rotationalSpeed;
	}
	else if (n > 0) {
		orientation += rotationalSpeed;
	}
	

	cout << n << " " << newO << endl;
	
	xLoc += translationalSpeed * sin(ofDegToRad(orientation));
	yLoc += -1 * translationalSpeed * cos(ofDegToRad(orientation));

	draw();
}
