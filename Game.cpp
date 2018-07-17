#include "Game.h"


void Game::setup() {
	gamestate = 0;

	ofBackground(0);
	ofSetRectMode(OF_RECTMODE_CENTER);
	ofSetFrameRate(60);

	int screenWidth = ofGetScreenWidth();
	int screenHeight = ofGetScreenHeight();

	player = new Player(400, 400, 0);
	c1 = new Stopwatch();
	
	
	enemiesExisting = 0;
	enemies = new Enemy*[MAX_ENEMIES];
	enemiesRemaining = 10;

}

//--------------------------------------------------------------
void Game::update() {

	if (gamestate == 0) {

	}
	else if (gamestate == 1) {

		if (player->getHealth() <= 0) {
			gamestate = 2;
		}

		updateRound();

		for (int i = enemiesExisting - 1; i >= 0; i--) {
			if (enemies[i]->hasDied()) {
				delete enemies[i];

				if (i + 1 < enemiesExisting) {
					for (int j = i; j < enemiesExisting - 1; j++)
						enemies[j] = enemies[j + 1];
					i--;
				}

				enemiesExisting--;
			}
		}

		for (int i = 0; i < enemiesExisting; i++) {
			enemies[i]->update();
		}

		player->update();
	}
	else if (gamestate == 2) {

	}

	
}

//--------------------------------------------------------------
void Game::draw() {
	
	if (gamestate == 0) {

	}
	else if (gamestate == 1) {
		player->draw();

		for (int i = 0; i < enemiesExisting; i++) {
			enemies[i]->draw();
		}

		player->drawHealthBar();

	}
	else if (gamestate == 2) {

	}
}

//--------------------------------------------------------------
void Game::keyPressed(int key) {
	if (key == 'p') gamestate = 1;
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
	
	if (enemiesRemaining == 0 && enemiesExisting == 0) {
		enemiesRemaining = 10;
	}
}

void Game::spawnEnemy() {
	if (enemiesExisting < MAX_ENEMIES) {
		enemies[enemiesExisting] = new Enemy(300, 300, 0, player);
		enemiesExisting++;
	}
}

