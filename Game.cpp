#include "Game.h"


void Game::setup() {

	ofTrueTypeFont::setGlobalDpi(72);

	scifibit35.load("scifibit.ttf", 35, true, true);
	scifibit35.setLineHeight(18.0f);
	scifibit35.setLetterSpacing(1.037);

	scifibit25.load("scifibit.ttf", 25, true, true);
	scifibit25.setLineHeight(18.0f);
	scifibit25.setLetterSpacing(1.037);

	scifibit15.load("scifibit.ttf", 15, true, true);
	scifibit15.setLineHeight(18.0f);
	scifibit15.setLetterSpacing(1.037);

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

	}
	else if (gamestate == 2){
	
	}
	else if (gamestate == 3) {

		if (player.getHealth() <= 0) {
			gamestate = 2;
		}

		roundcontrol.updateRound();
		updateGame();
	}
	else if (gamestate == 4) {

	}	
}

void Game::draw(){
	if (gamestate == 0) {
		drawStartScreen();
	}
	else if (gamestate == 1) {
		drawLoadout();
	}
	else if (gamestate == 2) {
		drawGuide();
	}
	else if (gamestate == 3) {
		drawGame();
		drawGUI();
	}
	else if (gamestate == 4) {
		drawGame();
		drawGameOver();
	}
}

//--------------------------------------------------------------
void Game::keyPressed(int key) {

}

void Game::keyReleased(int key) {

}

void Game::mouseMoved(int x, int y) {
	if (onStart(x, y)) {
			currentPlay = &hovered;
	}
	else {
		currentPlay = &idle;
	}

	if (onGuide(x, y)) {
		currentGuide = &hovered;
	}
	else {
		currentGuide = &idle;
	}
	
}

void Game::mousePressed(int x, int y, int button) {
	cout << x << " " << y << endl;
	if (gamestate == 0) {
		if (onStart(x, y)) {
			gamestate = 1;
		}

		if (onGuide(x, y)) {
			gamestate = 3;
		}
	}
	
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
	ofSetColor(100, 255, 0);
	scifibit35.drawString("BLOCK OPS ZOMBIES", 100, 100);

	ofSetColor(*currentPlay);
	scifibit35.drawString("PLAY", ofGetScreenWidth() / 2 - scifibit35.stringWidth("PLAY") / 2,
		ofGetScreenHeight() / 3);

	ofSetColor(*currentGuide);
	scifibit35.drawString("GUIDE", ofGetScreenWidth() / 2 - scifibit35.stringWidth("GUIDE") / 2,
		2 * ofGetScreenHeight() / 3);

}

void Game::drawGame() const {
	player.draw();

	roundcontrol.draw();
}

void Game::drawGameOver() const {
	ofClear(0);
	scifibit35.drawString("Game Over", 100, 100);
}

void Game::drawGUI() const {
	roundcontrol.drawGUI();
	player.drawGUI();
}

void Game::drawLoadout() const {
	ofSetColor(100, 255, 0);
	scifibit35.drawString("CHOOSE YOUR LOADOUT", 100, 100);
	scifibit35.drawString("SIDEARM", ofGetScreenWidth() / 4 - scifibit35.stringWidth("SIDEARM") / 2, ofGetScreenHeight() / 3);
	scifibit35.drawString("PRIMARY", ofGetScreenWidth() / 2 - scifibit35.stringWidth("PRIMARY") / 2, ofGetScreenHeight() / 3);
	scifibit35.drawString("SPECIAL", 3 * ofGetScreenWidth() / 4 - scifibit35.stringWidth("SPECIAL") / 2, ofGetScreenHeight() / 3);

	ofSetColor(100);
	ofDrawRectangle(ofGetScreenWidth() / 4, 2 * ofGetScreenHeight() / 5, 200, 100);
	ofDrawRectangle(ofGetScreenWidth() / 4, 3 * ofGetScreenHeight() / 5, 200, 100);
	ofDrawRectangle(ofGetScreenWidth() / 2, 2 * ofGetScreenHeight() / 5, 200, 100);
	ofDrawRectangle(ofGetScreenWidth() / 2, 3 * ofGetScreenHeight() / 5, 200, 100);
	ofDrawRectangle(ofGetScreenWidth() / 2, 4 * ofGetScreenHeight() / 5, 200, 100);
	ofDrawRectangle(3 * ofGetScreenWidth() / 4, 2 * ofGetScreenHeight() / 5, 200, 100);
	ofDrawRectangle(3 * ofGetScreenWidth() / 4, 3 * ofGetScreenHeight() / 5, 200, 100);

	ofSetColor(100, 255, 0);
	scifibit35.drawString("P90", ofGetScreenWidth() / 4 - scifibit35.stringWidth("P90") / 2, 2 * ofGetScreenHeight() / 5 + scifibit35.stringHeight("P90") / 2);
	scifibit25.drawString("REVOLVER", ofGetScreenWidth() / 4 - scifibit25.stringWidth("REVOLVER") / 2, 3 * ofGetScreenHeight() / 5 + scifibit25.stringHeight("REVOLVER") / 2);
	scifibit25.drawString("ASSAULT", ofGetScreenWidth() / 2 - scifibit25.stringWidth("ASSAULT") / 2, 2 * ofGetScreenHeight() / 5 + scifibit25.stringHeight("ASSAULT") / 2);
	scifibit35.drawString("LMG", ofGetScreenWidth() / 2 - scifibit35.stringWidth("LMG") / 2, 3 * ofGetScreenHeight() / 5 + scifibit35.stringHeight("LMG") / 2);
	scifibit35.drawString("SMG", ofGetScreenWidth() / 2 - scifibit35.stringWidth("SMG") / 2, 4 * ofGetScreenHeight() / 5 + scifibit35.stringHeight("LMG") / 2);
	scifibit15.drawString("RANDOM CANON", 3 * ofGetScreenWidth() / 4 - scifibit15.stringWidth("RANDOM CANON") / 2, 2 * ofGetScreenHeight() / 5 + scifibit15.stringHeight("RANDOM /n CANON") / 2);
	scifibit15.drawString("FLAMETHROWER", 3 * ofGetScreenWidth() / 4 - scifibit15.stringWidth("FLAMETHROWER") / 2, 3 * ofGetScreenHeight() / 5 + scifibit15.stringHeight("FLAMETHROWER") / 2);
}

void Game::drawGuide() const {

}

bool Game::onStart(int x, int y) {
	return x > ofGetScreenWidth() / 2 - scifibit35.stringWidth("PLAY") / 2 - 20 && x < ofGetScreenWidth() / 2 + scifibit35.stringWidth("PLAY") / 2 + 20
		&& y > ofGetScreenHeight() / 3 - scifibit35.stringHeight("PLAY") - 15 && y < ofGetScreenHeight() / 3 + 15;
}

bool Game::onGuide(int x, int y) {
	return x > ofGetScreenWidth() / 2 - scifibit35.stringWidth("GUIDE") / 2 - 20 && x < ofGetScreenWidth() / 2 + scifibit35.stringWidth("GUIDE") / 2 + 20
		&& y > 2 * ofGetScreenHeight() / 3 - scifibit35.stringHeight("PLAY") - 15 && y < 2 * ofGetScreenHeight() / 3 + 15;
}
