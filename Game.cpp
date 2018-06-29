#include "Game.h"

class Clock;

void Game::setup() {
	ofBackground(0);
	ofSetRectMode(OF_RECTMODE_CENTER);
	ofSetFrameRate(60);

	int screenWidth = ofGetScreenWidth();
	int screenHeight = ofGetScreenHeight();

	player = new Player(400, 400, 0);
	c1 = new Clock();
	enemiesRemaining = 10;

}

//--------------------------------------------------------------
void Game::update() {
	updateRound();

	for (int i = 0; i < enemies.size(); i++) {
		enemies[i]->update();
	}

	player->update();
}

//--------------------------------------------------------------
void Game::draw() {

	for (int i = 0; i < enemies.size(); i++) {
		enemies[i]->draw();
	}

	player->draw();
}

//--------------------------------------------------------------
void Game::keyPressed(int key) {

}

void Game::keyReleased(int key) {

}

void Game::updateRound() {
	float t = c1->read();
	cout << t << endl;
	if (t > 1e9 && enemiesRemaining > 0) {
		spawnEnemy();
		c1->reset();
		enemiesRemaining--;
	}
}

void Game::spawnEnemy() {
	enemies.push_back(new Enemy(300, 300, 0, player));
}


Clock::Clock() {
	start = std::chrono::high_resolution_clock::now();
}

Clock::~Clock() {}

void Clock::reset() {
	start = std::chrono::high_resolution_clock::now();
}

float Clock::read() {
	return (std::chrono::high_resolution_clock::now() - start).count();
}