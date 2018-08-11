#include "..\Entity_headers\Player.h"


Player::Player(float x, float y, float o) : Entity(x, y, o)
{
	currentGun = 0;

	health = 3;
	maxHealth = 3;
	translationalSpeed = 15;

	color = ofColor(0, 100, 255);
	healthTimer = Stopwatch();

}

Player::Player() : Entity(0, 0, 0)
{
	health = 3;
	maxHealth = 3;
	translationalSpeed = 15;

	color = ofColor(0, 100, 255);
	healthTimer = Stopwatch();
}

Player::~Player()
{
}

void Player::update()
{
	
	float* boundariesX = getBoundariesX();
	float* boundariesY = getBoundariesY();
	
	if (ofGetKeyPressed('j')) {

		if (checkWallBoundariesO(-1 * rotationalSpeed)) {
			orientation -= rotationalSpeed;
		}
	}
	else if (ofGetKeyPressed('l')) {

		if (checkWallBoundariesO(rotationalSpeed)) {
			orientation += rotationalSpeed;
		}

	}

	if (ofGetKeyPressed('w')) {
		float deltaX = translationalSpeed * cos(orientation);
		float deltaY = translationalSpeed * sin(orientation);

		if (checkWallBoundariesX(boundariesX, deltaX)) {
			xLoc += deltaX;
		}
		if (checkWallBoundariesY(boundariesY, deltaY)) {
			yLoc += deltaY;

			if (ofGetKeyPressed('i')) shoot();
		}
		else {
			reachBoundary(boundariesX, boundariesY, deltaX, deltaY);
		}
	} else if (ofGetKeyPressed('s')) {
		float deltaX = -translationalSpeed * cos(orientation);
		float deltaY = -translationalSpeed * sin(orientation);

		if (checkWallBoundariesX(boundariesX, deltaX)) {
			xLoc += deltaX;
		}
		if (checkWallBoundariesY(boundariesY, deltaY)) {
			yLoc += deltaY;
		
			
		}
		else {
			reachBoundary(boundariesX, boundariesY, deltaX, deltaY);
		}
	} else if (ofGetKeyPressed('i')) shoot();
	
	for (int i = 0; i < 3; i++) {
		if (guns[i].getBullets().size() > 0 && i != currentGun) {
			guns[i].update();
		}
	}
	guns[currentGun].update();
}

void Player::updateHealth() {
	health -= 1;
}

void Player::draw() const {
	for (int i = 0; i < 3; i++) {
		if (guns[i].getBullets().size() > 0 && i != currentGun) {
			guns[i].draw();
		}
	}
	guns[currentGun].draw();

	Entity::draw();
}

void Player::drawGUI() const {
	drawHealthBar();
	guns[currentGun].drawGUI();
}

void Player::drawHealthBar() const {
	float fullLength = 500;
	float length = health * fullLength / maxHealth;
	ofSetColor(250, 250, 250, 100);
	ofDrawRectangle(300, 50, fullLength, 50);
	ofSetColor(250, 0, 0);
	ofDrawRectangle(50 + length / 2, 50, length, 50);
}


bool Player::checkWallBoundariesX(float* x, float deltaX) {

	for (int i = 0; i < boundaryCount; i++) {
		if (x[i] + deltaX <= 0 || x[i] + deltaX >= ofGetScreenWidth()) return false;
	}
	
	return true;
}

bool Player::checkWallBoundariesY(float* y, float deltaY) {

	for (int i = 0; i < boundaryCount; i++) {
		if (y[i] + deltaY <= 0 || y[i] + deltaY >= ofGetScreenHeight()) return false;
	}
	
	return true;
}

bool Player::checkWallBoundariesO(float deltaO) {

	for (float i = 0; i < 2 * PI; i += PI / 2) {
		float newX = xLoc + sqrt(2) * size * sin(i - PI / 4 - orientation - deltaO) / 2;
		float newY = yLoc + sqrt(2) * size * cos(i - PI / 4 - orientation - deltaO) / 2;

		if (newX <= 0 || newX >= ofGetScreenWidth()) return false;
		if (newY <= 0 || newY >= ofGetScreenHeight()) return false;
	}

	return true;
}

void Player::reachBoundary(float* x, float* y, float deltaX, float deltaY) {
	for (float i = .95; i > .1; i -= .05) {
		if (checkWallBoundariesX(x, i * deltaX)) {
			xLoc += i * deltaX;
			return;
		}
		if (checkWallBoundariesY(y, i * deltaY)) {
			yLoc += i * deltaY;
			return;
		}
	}
}

void Player::shoot() {
	guns[currentGun].shoot(xLoc, yLoc, orientation);
}

vector<Bullet>& Player::getBullets() {
	return guns[currentGun].getBullets();
}

int Player::getHealth() const {
	return health;
}

void Player::configureLoadout(int * loadout) {
	if (loadout[0] == 1) {
		guns[0] = P90();
	}
	if (loadout[0] == 2) {
		guns[0] = Revolver();
	}
	if (loadout[1] == 1) {
		guns[1] = Assault();
	}
	if (loadout[1] == 2) {
		guns[1] = LMG();
	}
	if (loadout[1] == 3) {
		guns[1] = SMG();
	}
	if (loadout[2] == 1) {
		guns[2] = RandomCanon();
	}
	if (loadout[2] == 2) {
		guns[2] = Flamethrower();
	}
}

void Player::changeGun() {
	currentGun++;
	if (currentGun == 3)
		currentGun = 0;
}