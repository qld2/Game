#pragma once
#include "ofMain.h"
#include "Entity_headers\Enemy.h"
#include "Entity_headers\Player.h"
#include "SpawnController.h"

class Roundcontroller {
	Player* player;

	Stopwatch c1;
	float spawnTimeGap, roundTimeGap;

	int round;
	int enemiesRemaining, enemiesPerRound;
	int MAX_ENEMIES = 100;

	SpawnController spawnController;
	int spawnPointCount = 4;
	ofVec2f* spawnPoints;
	vector<Enemy> enemies;
	

public:
	Roundcontroller(Player* player);
	Roundcontroller();
	~Roundcontroller();

	void update();
	void updateRound();
	void draw() const;

	int getRound();

private:
	void spawnEnemy();
	void moveSpawns();
	void endRound();
};