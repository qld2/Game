#pragma once
#include "Entity_headers\Player.h"
#include "Entity_headers\Enemy.h"

extern int screenWidth, screenHeight;

class Clock;

class Game : public ofBaseApp
{
	Player* player;
	vector<Enemy*> enemies;
	Clock* c1;
	int enemiesRemaining;

public:

	void setup();
	void update(); 
	void draw();

	void updateRound();
	void spawnEnemy();

	void keyPressed(int key);
	void keyReleased(int key);
};

class Clock {
	std::chrono::time_point<std::chrono::steady_clock> start;

public:
	Clock();
	~Clock();

	void reset();
	float read();
};