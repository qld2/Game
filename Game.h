#pragma once
#include "Player.h"
#include "Enemy.h"

extern int screenWidth, screenHeight;

class Game : public ofBaseApp
{
	Player* player = new Player(70, 70, 0);
	Enemy* e = new Enemy(70, 70, 0);

public:

	void setup();
	void update(); 
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
};

