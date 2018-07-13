#include "..\Entity_headers\Enemy.h"
#include "..\Entity_headers\Player.h"

Enemy::Enemy(float x, float y, float o, Player * p) : Entity(x, y, o)
{
	xLoc = x;
	yLoc = y;
	orientation = o;
	player = p;
	health = 2;
	maxHealth = 3;
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

	if (checkForCollision()) {
		player->updateHealth();
	}
	
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

void Enemy::draw() {
	if (health < maxHealth) {
		drawHealthBar();
	}
	
	Entity::draw();
}

void Enemy::drawHealthBar() {
	float fullLength = 50;
	float length = health * fullLength / maxHealth;
	ofTranslate(xLoc, yLoc);
	ofSetColor(250, 250, 250, 100);
	ofDrawRectangle(0, -40, fullLength, 10);
	ofSetColor(250, 0, 0);
	ofDrawRectangle((length - fullLength) / 2, -40, length, 10);
	ofTranslate(-xLoc,-yLoc);
}

bool Enemy::checkForCollision() {

	if (distanceTo(player) <= sqrt(2) * SIZE && (player->healthTimer->read() > 2e9)) {
		if (hasCollided(player) || player->hasCollided(this)) {
		player->healthTimer->reset();
			return true;
		}
	}

	return false;
	
}