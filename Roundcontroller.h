#pragma once
#include "ofMain.h"
#include "Entity_headers\Enemy.h"
#include "Entity_headers\Player.h"

class Roundcontroller {
	int enemiesRemaining;
	int MAX_ENEMIES = 100;

	Stopwatch c1;
	ofVec3f a, b, c;

	Player* player;
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

};