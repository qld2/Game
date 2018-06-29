#include "..\Entity_headers\Enemy.h"
#include "..\Entity_headers\Player.h"

Enemy::Enemy(float x, float y, float o, Player * p) : Entity(x, y, o)
{
	xLoc = x;
	yLoc = y;
	orientation = o;
	player = p;
	health = 3;

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
	refreshOrientation();
	
	float x = player->getX() - xLoc;
	float y = player->getY() - yLoc;
	float newO = atan2(y, x);

	float n = sin(-orientation) * cos(newO) + cos(-orientation) * sin(newO);

	if (n < 0) {
		orientation -= rotationalSpeed;
	}
	else if (n > 0) {
		orientation += rotationalSpeed;
	}
	
	xLoc += translationalSpeed * cos(orientation);
	yLoc += translationalSpeed * sin(orientation);
}

void Enemy::drawHealthBar() {

}

bool Enemy::checkForCollision() {
	return true;
}