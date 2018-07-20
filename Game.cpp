#include "Game.h"


void Game::setup() {
	gamestate = 0;

	a = new ofVec3f(300, 300, 0);
	b = new ofVec3f(300, 800, 0);
	c = new ofVec3f(1600, 500, 0);

	ofBackground(0);
	ofSetRectMode(OF_RECTMODE_CENTER);
	ofSetFrameRate(60);

	int screenWidth = ofGetScreenWidth();
	int screenHeight = ofGetScreenHeight();

	player = new Player(400, 400, 0);
	c1 = new Stopwatch();
	

	ofColor(32, 64, 32);
	ofDrawRectangle(a->x, a->y, a->z, 25);

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

		updateGame();
	}
	else if (gamestate == 2) {

	}

	
}

//--------------------------------------------------------------
void Game::draw() {

	if (gamestate == 0) {
		drawStartScreen();
	}
	else if (gamestate == 1) {
		drawGame();
	}
	else if (gamestate == 2) {
		drawGame();
		drawGameOver();
	}
}

//--------------------------------------------------------------
void Game::keyPressed(int key) {
	if (gamestate == 0) gamestate = 1;
}

void Game::keyReleased(int key) {

}

void Game::updateRound() {
	float t = c1->read();
	if (t > 1.5 && enemiesRemaining > 0) {
		spawnEnemy();
		c1->reset();
		enemiesRemaining--;
	}
	
	if (enemiesRemaining == 0 && enemies.size() == 0) {
		enemiesRemaining = 10;
	}
}

void Game::spawnEnemy() {
	if (enemies.size() < MAX_ENEMIES) {
		if (ofRandomf() < .3) {
			enemies.push_back(new Enemy(a->x, a->y, 0, player));
		} else if (ofRandomf() > .3 && ofRandomf() < .6) {
			enemies.push_back(new Enemy(b->x, b->y, 0, player));
		} else 	if (ofRandomf() < .3) {
			enemies.push_back(new Enemy(c->x, c->y, 0, player));
		}
	}
}

//-----------------------------------------------------------------------
void Game::updateStartScreen() {

}

void Game::updateGame() {

	for (int i = enemies.size() - 1; i >= 0; i--) {
		if (enemies[i]->hasDied()) {
			enemies[i] = enemies.back();
			enemies.pop_back();
			i--;
		}
	}

	for (int i = 0; i < enemies.size(); i++) {
		enemies[i]->update();
	}

	player->update();
}

void Game::updateGameOver() {

}

//--------------------------------------------------------------------
void Game::drawStartScreen() {
	ofClear(0);
	ofDrawBitmapString("Press any key to begin", 100, 100);
}

void Game::drawGame() {
	player->draw();

	for (int i = 0; i < enemies.size(); i++) {
		enemies[i]->draw();
	}

	player->drawHealthBar();
}

void Game::drawGameOver() {
	ofClear(0);
	ofDrawBitmapString("Game Over", 100, 100);
}



