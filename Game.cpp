#include "Game.h"

void Game::setup() {
	ofBackground(0);
	ofSetRectMode(OF_RECTMODE_CENTER);
	ofSetFrameRate(60);

	int screenWidth = ofGetScreenWidth();
	int screenHeight = ofGetScreenHeight();

	cout << screenWidth;
}

//--------------------------------------------------------------
void Game::update() {

}

//--------------------------------------------------------------
void Game::draw() {
	player->update();
}

//--------------------------------------------------------------
void Game::keyPressed(int key) {

}

void Game::keyReleased(int key) {

}