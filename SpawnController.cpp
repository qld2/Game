#include "SpawnController.h"

SpawnController::SpawnController(int spawnPointCount, ofVec2f* spawnPoints) : spawnPointCount(spawnPointCount),
	spawnPoints(spawnPoints) {}


void SpawnController::moveSpawns() {
	(this->*currentConfiguration)();
}

void SpawnController::setConfiguration(int roundNumber) {
	int random = floor(ofRandom(roundNumber));
	currentConfiguration = spawnConfigurations[7];
}



//--------------------------------------------------------------------------------------------------

void SpawnController::spawnConfigI() {
	static Stopwatch watch = Stopwatch();
	float t = watch.read();

}

void SpawnController::spawnConfigII() {
	static Stopwatch watch = Stopwatch();
	float t = watch.read();
	
	for (int i = 0; i < spawnPointCount; i++) {
		spawnPoints[i].x = ofGetScreenWidth() / 2 - 100 * i * cos(t);
		spawnPoints[i].y = ofGetScreenHeight() / 2 + 250 * i * sin(t);
	}
}

void SpawnController::spawnConfigIII() {
	static Stopwatch watch = Stopwatch();
	float t = watch.read();

	for (int i = 0; i < spawnPointCount; i++) {
		spawnPoints[i].x = ofGetScreenWidth() / 2 + 250 * i * cos(t);
		spawnPoints[i].y = ofGetScreenHeight() / 2 + 100 * i * sin(t);
	}
}

void SpawnController::spawnConfigIV() {
	static Stopwatch watch = Stopwatch();
	float t = watch.read();

	for (int i = 0; i < spawnPointCount; i++) {
		spawnPoints[i].x = ofGetScreenWidth() / 2 - 100 * i * cos(t);
		spawnPoints[i].y = ofGetScreenHeight() / 2 + 250 * i * sin(t);
	}
}

void SpawnController::spawnConfigV() {
	static Stopwatch watch = Stopwatch();
	float t = watch.read();

	for (int i = 0; i < spawnPointCount; i++) {
		spawnPoints[i].x = ofGetScreenWidth() / 2 + 250 * i * cos(t);
		spawnPoints[i].y = ofGetScreenHeight() / 2 + 100 * i * sin(t);
	}
}

void SpawnController::spawnConfigVI() {
	static Stopwatch watch = Stopwatch();
	float t = watch.read();


}

void SpawnController::spawnConfigVII() {
	static Stopwatch watch = Stopwatch();
	float t = watch.read();

	for (int i = 0; i < spawnPointCount; i++) {
		spawnPoints[i].x = ofGetScreenWidth() / 2 + 250 * i * cos(t);
		spawnPoints[i].y = ofGetScreenHeight() / 2 + 100 * i * sin(t);
	}
}

void SpawnController::spawnConfigVIII() {
	int stepSize = ofRandom(10);

	for (int i = 0; i < spawnPointCount; i++) {
	
		if (ofRandomf() > 0) {
			if (spawnPoints[i].y > stepSize) {
				spawnPoints[i].y -= stepSize;
			}
			else {
				spawnPoints[i].y += stepSize;
			}
		}
		else {
			if (spawnPoints[i].y < ofGetScreenHeight() - stepSize) {
				spawnPoints[i].y += stepSize;
			}
			else {
				spawnPoints[i].y -= stepSize;
			}
		}

		if (ofRandomf() > 0) {
			if (spawnPoints[i].x > stepSize) {
				spawnPoints[i].x -= stepSize;
			}
			else {
				spawnPoints[i].x += stepSize;
			}
		}
		else {
			if (spawnPoints[i].x < ofGetScreenWidth() - stepSize) {
				spawnPoints[i].x += stepSize;
			}
			else {
				spawnPoints[i].x -= stepSize;
			}
		}
	}
}