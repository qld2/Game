#include "Game.h"


void Game::setup() {

	ofTrueTypeFont::setGlobalDpi(72);

	scifibit35.load("scifibit.ttf", 35, true, true);
	scifibit35.setLineHeight(18.0f);
	scifibit35.setLetterSpacing(1.037);

	ofBackground(0);
	ofSetRectMode(OF_RECTMODE_CENTER);
	ofSetFrameRate(60);

	gamestate = 0;

	player = Player(400, 400, 0);
	roundcontrol = Roundcontroller(&player);
}

void Game::update() {

	if (gamestate == 0) {

	}
	else if (gamestate == 1) {

		if (player.getHealth() <= 0) {
			gamestate = 2;
		}

		roundcontrol.updateRound();
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
		drawGUI();
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

//-----------------------------------------------------------------------
void Game::updateStartScreen() {

}

void Game::updateGame() {

	roundcontrol.update();
	player.update();
}

void Game::updateGameOver() {

}

//--------------------------------------------------------------------
void Game::drawStartScreen() const {
	scifibit35.drawString("Press any key to begin", 100, 100);
}

void Game::drawGame() const {
	player.draw();

	roundcontrol.draw();

	player.drawHealthBar();
}

void Game::drawGameOver() const {
	ofClear(0);
	scifibit35.drawString("Game Over", 100, 100);
}

void Game::drawGUI() const {
	roundcontrol.drawGUI();
	
}

