#pragma once
#include "ofMain.h"
#include "Entity_headers\Enemy.h"
#include "Entity_headers\Player.h"

class Roundcontroller {
	Player* player;

	Stopwatch c1;
	float spawnTimeGap, roundTimeGap;

	int round;
	int enemiesRemaining, enemiesPerRound;
	int MAX_ENEMIES = 100;

	vector<ofVec2f> spawnPoints;
	vector<Enemy> enemies;

public:
	Roundcontroller(Player* player);
	Roundcontroller();
	~Roundcontroller();

	void update();
	void updateRound();
	void draw() const;

private:
	void spawnEnemy();
	void moveSpawns();
	void endRound();
};