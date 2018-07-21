#pragma once
#include "Entity_headers\Player.h"
#include "Entity_headers\Enemy.h"
#include "Stopwatch.h"

class Game : public ofBaseApp
{
int gamestate;

	Player player;
	Stopwatch c1;

	ofVec3f a, b, c;

	int enemiesRemaining;
	const int MAX_ENEMIES = 100;
	vector<Enemy*> enemies;

public:
	void setup();
	void update(); 
	void draw();

	void updateRound();
	void spawnEnemy();

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