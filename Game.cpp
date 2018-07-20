#include "Game.h"


void Game::setup() {
	gamestate = 0;

	a = ofVec3f(300, 300, 0);
	b = ofVec3f(300, 800, 0);
	c = ofVec3f(1600, 900, 0);

	ofBackground(0);
	ofSetRectMode(OF_RECTMODE_CENTER);
	ofSetFrameRate(60);

	player = Player(400, 400, 0);
	c1 = Stopwatch();
	
	enemiesRemaining = 10;

}

void Game::update() {

	if (gamestate == 0) {

	}
	else if (gamestate == 1) {

		if (player.getHealth() <= 0) {
			gamestate = 2;
		}

		updateRound();

		updateGame();
	}
	else if (gamestate == 2) {

	}

	
}

void Game::draw(){

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
	if (gamestate != 1) gamestate = 1;
}

void Game::keyReleased(int key) {

}

void Game::updateRound() {
	float t = c1.read();
	if (t > 1.5 && enemiesRemaining > 0) {
		spawnEnemy();
		c1.reset();
		enemiesRemaining--;
	}
	
	if (enemiesRemaining == 0 && enemies.size() == 0) {
		enemiesRemaining = 10;
	}
}

void Game::spawnEnemy() {
	if (enemies.size() < MAX_ENEMIES) {
		if (ofRandomf() < -.3) {
			enemies.push_back(new Enemy(a.x, a.y, 0, &player));
		} else if (ofRandomf() > -.3 && ofRandomf() < .3) {
			enemies.push_back(new Enemy(b.x, b.y, 0, &player));
		} else 	if (ofRandomf() > .3) {
			enemies.push_back(new Enemy(c.x, c.y, 0, &player));
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

	player.update();
}

void Game::updateGameOver() {

}

//--------------------------------------------------------------------
void Game::drawStartScreen() const {
	ofClear(0);
	ofDrawBitmapString("Press any key to begin", 100, 100);
}

void Game::drawGame() const {
	player.draw();

	ofSetColor(0, 128, 128);
	ofDrawRectangle(a.x, a.y, 25, 25);
	ofDrawRectangle(b.x, b.y, 25, 25);
	ofDrawRectangle(c.x, c.y, 25, 25);

	for (int i = 0; i < enemies.size(); i++) {
		enemies[i]->draw();
	}

	player.drawHealthBar();
}

void Game::drawGameOver() const {
	ofClear(0);
	ofDrawBitmapString("Game Over", 100, 100);
}



