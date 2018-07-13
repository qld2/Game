#include "Game.h"


void Game::setup() {
	ofBackground(0);
	ofSetRectMode(OF_RECTMODE_CENTER);
	ofSetFrameRate(60);

	int screenWidth = ofGetScreenWidth();
	int screenHeight = ofGetScreenHeight();

	player = new Player(400, 400, 0);
	c1 = new Stopwatch();
	
	MAX_ENEMIES = 30;
	enemiesExisting = 0;
	enemies = new Enemy*[MAX_ENEMIES];
	enemiesRemaining = 9;

}

//--------------------------------------------------------------
void Game::update() {
	updateRound();

	for (int i = 0; i < enemiesExisting; i++) {
		enemies[i]->update();
	}

	player->update();
}

//--------------------------------------------------------------
void Game::draw() {
	player->draw();

	for (int i = 0; i < enemiesExisting; i++) {
		enemies[i]->draw();
	}

	player->drawHealthBar();
}

//--------------------------------------------------------------
void Game::keyPressed(int key) {
	if (key == 'i') {
		player->shoot();
	}
}

void Game::keyReleased(int key) {

}

void Game::updateRound() {
	float t = c1->read();
	if (t > 1e9 && enemiesRemaining > 0) {
		spawnEnemy();
		c1->reset();
		enemiesRemaining--;
	}
}

void Game::spawnEnemy() {
	if (enemiesExisting < MAX_ENEMIES) {
		enemies[enemiesExisting] = new Enemy(300, 300, 0, player);
		enemiesExisting++;
	}
}

