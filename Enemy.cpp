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
	if (orientation >= 2 * PI) orientation -= 2 * PI;
	if (orientation < 0) orientation += 2 * PI;
	
	float x = p->getX() - xLoc;
	float y = p->getY() - yLoc;
	float newO = PI / 2 + atan2(y, x);

	if (newO >= 2 * PI) newO -= 2 * PI;
	if (newO < 0) newO += 2 * PI;

	float n = cos(-orientation) * sin(newO) + sin(-orientation) * cos(newO);

	if (n < 0) {
		orientation -= rotationalSpeed;
	}
	else if (n > 0) {
		orientation += rotationalSpeed;
	}
	

	cout << n << " " << newO << endl;
	
	xLoc += translationalSpeed * sin(orientation);
	yLoc += -1 * translationalSpeed * cos(orientation);

	draw();
}
