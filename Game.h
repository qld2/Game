#pragma once
#include "Entity_headers\Player.h"
#include "Entity_headers\Enemy.h"
#include "Stopwatch.h"

extern int screenWidth, screenHeight;

class Game : public ofBaseApp
{
int gamestate;

	Player* player;
	Enemy** enemies;
	Stopwatch* c1;
	int enemiesRemaining;
	int enemiesExisting;
	const int MAX_ENEMIES = 30;
public:
	void setup();
	void update(); 
	void draw();

	void updateRound();
	void spawnEnemy();

	void keyPressed(int key);
	void keyReleased(int key);
};