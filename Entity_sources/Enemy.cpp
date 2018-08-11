#include "..\Entity_headers\Enemy.h"
#include "..\Entity_headers\Player.h"

Enemy::Enemy(float x, float y, float o, Player* p) : Entity(x, y, o), player(p)
{

	translationalSpeed = 2;
	rotationalSpeed = PI / 100;

	maxHealth = 100;
	health = maxHealth;

	color = ofColor(255, 100, 0);
}

Enemy::Enemy() : Entity(100, 100, PI/4), player(new Player(100, 100, PI / 4))
{

	translationalSpeed = 2;
	rotationalSpeed = PI / 100;

	maxHealth = 10;
	health = maxHealth;

	color = ofColor(255, 100, 0);
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

	checkForBullets();
}

void Enemy::draw() const {
	if (health < maxHealth) {
		drawHealthBar();
	}
	
	Entity::draw();
}

void Enemy::drawHealthBar() const {
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

	if (distanceTo(*player) <= sqrt(2) * size && (player->healthTimer.read() > 2)) {
		if (hasCollided(*player) || player->hasCollided(*this)) {
			player->healthTimer.reset();
			return true;
		}
	}

	return false;
	
}

bool Enemy::checkForBullets() {
	vector<Bullet>& bullets = player->getBullets();

	for (int i = 0; i < bullets.size(); i++) {
		if (sqrt(pow(bullets[i].getX() - xLoc,2) + pow(bullets[i].getY() - yLoc,2)) < 25) {
			health -= bullets[i].getDamage();
			bullets[i] = bullets.back();
			bullets.pop_back();
			i--;
		}
	}

	return true;
}

bool Enemy::hasDied() const {
	if (health <= 0) return true;
	return false;
}

