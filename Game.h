#pragma once
#include "Entity_headers\Player.h"
#include "Entity_headers\Enemy.h"
#include "Roundcontroller.h"
#include "Stopwatch.h"

class Game : public ofBaseApp
{
	ofTrueTypeFont scifibit35;
	ofTrueTypeFont scifibit25;
	ofTrueTypeFont scifibit15;
	ofColor const hovered = ofColor(255, 0, 0);
	ofColor const idle = ofColor(255);
	const ofColor* currentPlay = &idle;
	const ofColor* currentGuide = &idle;

	int gamestate;

	int* loadout = new int[3];
	bool chosen = true;

	Player player;
	Roundcontroller roundcontrol;

public:
	void setup();
	void update(); 
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mousePressed(int x, int y, int button);

private:
	void drawStartScreen() const;
	void drawGame() const;
	void drawGameOver() const;
	void drawGUI() const;
	void drawLoadout() const;
	void drawGuide() const;

	void updateStartScreen();
	void updateGame();
	void updateGameOver();

	bool onStart(int x, int y);
	bool onGuide(int x, int y);
};