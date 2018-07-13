#pragma once
#include "Entity_headers\Player.h"
#include "Entity_headers\Enemy.h"
#include "Stopwatch.h"

extern int screenWidth, screenHeight;

class Game : public ofBaseApp
{
	Player* player;
	Enemy** enemies;
	Stopwatch* c1;
	int enemiesRemaining;
	int enemiesExisting;
	int MAX_ENEMIES;
public:
	void setup();
	void update(); 
	void draw();

	void updateRound();
	void spawnEnemy();

	void keyPressed(int key);
	void keyReleased(int key);
};