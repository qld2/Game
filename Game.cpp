#include "Game.h"

void Game::setup() {
	ofBackground(0);
	ofSetRectMode(OF_RECTMODE_CENTER);
	ofSetFrameRate(60);

	int screenWidth = ofGetScreenWidth();
	int screenHeight = ofGetScreenHeight();

}

//--------------------------------------------------------------
void Game::update() {

}

//--------------------------------------------------------------
void Game::draw() {

	e->update();
	player->update();
}

//--------------------------------------------------------------
void Game::keyPressed(int key) {

}

void Game::keyReleased(int key) {

}