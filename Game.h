#pragma once
#include "Entity_headers\Player.h"
#include "Entity_headers\Enemy.h"
#include "Roundcontroller.h"
#include "Stopwatch.h"

class Game : public ofBaseApp
{
	int gamestate;

	Player player;
	Roundcontroller roundcontrol;

public:
	void setup();
	void update(); 
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);

private:
	void drawStartScreen() const;
	void drawGame() const;
	void drawGameOver() const;

	void updateStartScreen();
	void updateGame();
	void updateGameOver();
};