#include "Roundcontroller.h"

Roundcontroller::Roundcontroller(Player* player) : player(player), spawnController(SpawnController(0, spawnPoints)) {
	c1 = Stopwatch();
	spawnTimeGap = 2;
	roundTimeGap = 5;

	round = 1;
	enemiesPerRound = 4;
	enemiesRemaining = enemiesPerRound;
	
	spawnPointCount = 4;
	spawnPoints = new ofVec2f[spawnPointCount];
	spawnController = SpawnController(spawnPointCount, spawnPoints);

	for (int i = 0; i < spawnPointCount; i++) {
		spawnPoints[i] = ofVec2f(ofGetScreenWidth() / 2, ofGetScreenHeight() / 2);
	}

	spawnController.setConfiguration(1);
}

Roundcontroller::Roundcontroller() : player(new Player(100, 100, 0)), spawnController(SpawnController(0, spawnPoints)) {
	c1 = Stopwatch();
	spawnTimeGap = 2;
	roundTimeGap = 5;

	round = 1;
	enemiesPerRound = 10;
	enemiesRemaining = enemiesPerRound;

	spawnPointCount = 0;
	spawnPoints = new ofVec2f[spawnPointCount];
	spawnController = SpawnController(spawnPointCount, spawnPoints);

	for (int i = 0; i < spawnPointCount; i++) {
		spawnPoints[i] = ofVec2f(ofGetScreenWidth() / 2, ofGetScreenHeight() / 2);
	}
}

Roundcontroller::~Roundcontroller() {

}

void Roundcontroller::update() {
	for (int i = enemies.size() - 1; i >= 0; i--) {
		if (enemies[i].hasDied()) {
			enemies[i] = enemies.back();
			enemies.pop_back();
			i--;
		}
	}

	moveSpawns();

	for (int i = 0; i < enemies.size(); i++) {
		enemies[i].update();
	}
}


void Roundcontroller::draw() const {
	ofSetColor(0, 128, 128);

	for (int i = 0; i < spawnPointCount; i++) {
		ofDrawRectangle(spawnPoints[i].x, spawnPoints[i].y, 25, 25);
	}

	for (int i = 0; i < enemies.size(); i++) {
		enemies[i].draw();
	}
}

void Roundcontroller::updateRound() {
	float t = c1.read();
	if (t > spawnTimeGap && enemiesRemaining > 0) {
		spawnEnemy();
		c1.reset();
		enemiesRemaining--;
	}

	if (enemiesRemaining == 0 && enemies.size() == 0) {
		endRound();
	}
}

void Roundcontroller::spawnEnemy() {
	
	if (enemies.size() == 0) {
		enemies.push_back(Enemy(spawnPoints[0].x, spawnPoints[0].y, 0, player));
		return;
	}

	if (enemies.size() < MAX_ENEMIES) {
		float random = abs(ofRandomf());

		for (float i = 0; i < spawnPointCount; i++) {

			if (random > i / spawnPointCount && random <= (i + 1) / spawnPointCount) {
				enemies.push_back(Enemy(spawnPoints[(int) i].x, spawnPoints[(int) i].y, 0, player));
			}

		}
	}
}

void Roundcontroller::moveSpawns() {
	cout << spawnPointCount << " " << endl;
	spawnController.moveSpawns();
}

void Roundcontroller::endRound() {
	round++;

	if (round <= 5) {
		enemiesPerRound += 4;
	}
	else if (round <= 10) {
		enemiesPerRound += 3;
	}
	else if (round <= 20) {
		enemiesPerRound += 2;
	}
	else {
		enemiesPerRound += 1;
	}

	enemiesRemaining = enemiesPerRound;

	spawnController.setConfiguration(round);
}