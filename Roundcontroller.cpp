#include "Roundcontroller.h"

Roundcontroller::Roundcontroller(Player& player) : player(player) {
	enemiesRemaining = 45;

	c1 = Stopwatch();
	
	a = ofVec3f(300, 300, 0);
	b = ofVec3f(300, 800, 0);
	c = ofVec3f(1600, 900, 0);

}

Roundcontroller::~Roundcontroller() {

}

void Roundcontroller::update() {
	for (int i = enemies.size() - 1; i >= 0; i--) {
		if (enemies[i].hasDied()) {
			enemies[i] = Enemy(100,100,1,player);
			enemies.pop_back();
			i--;
		}
	}

	for (int i = 0; i < enemies.size(); i++) {
		enemies[i].update();
	}
}


void Roundcontroller::draw() const {
	ofSetColor(0, 128, 128);
	ofDrawRectangle(a.x, a.y, 25, 25);
	ofDrawRectangle(b.x, b.y, 25, 25);
	ofDrawRectangle(c.x, c.y, 25, 25);

	for (int i = 0; i < enemies.size(); i++) {
		enemies[i].draw();
	}
}

void Roundcontroller::updateRound() {
	float t = c1.read();
	if (t > .5 && enemiesRemaining > 0) {
		spawnEnemy();
		c1.reset();
		enemiesRemaining--;
	}

	if (enemiesRemaining == 0 && enemies.size() == 0) {
		enemiesRemaining = 10;
	}
}

void Roundcontroller::spawnEnemy() {
	if (enemies.size() < MAX_ENEMIES) {
		float random = ofRandomf();
		if (random < -.3) {
			enemies.push_back(Enemy(a.x, a.y, 0, player));
		}
		else if (random > -.3 && random < .3) {
			enemies.push_back(Enemy(b.x, b.y, 0, player));
		}
		else 	if (random > .3) {
			enemies.push_back(Enemy(c.x, c.y, 0, player));
		}
	}
}