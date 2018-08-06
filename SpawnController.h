#pragma once
#include "Stopwatch.h"
#include <vector>

class SpawnController {
	int spawnConfigNum = 0;
	int spawnPointCount;
	ofVec2f * spawnPoints;

	void(SpawnController::*currentConfiguration)() = NULL;
	void(SpawnController::*spawnConfigurations[8])() = {&SpawnController::spawnConfigI,
		&SpawnController::spawnConfigII, &SpawnController::spawnConfigIII, &SpawnController::spawnConfigIV, 
		&SpawnController::spawnConfigV, &SpawnController::spawnConfigVI, &SpawnController::spawnConfigVII, 
		&SpawnController::spawnConfigVIII};

public:
	SpawnController(int spawnPointCount, ofVec2f * spawnPoints);
	
	void setConfiguration(int roundNumber);
	void moveSpawns();

private:
	void spawnConfigI();
	void spawnConfigII();
	void spawnConfigIII();
	void spawnConfigIV();
	void spawnConfigV();
	void spawnConfigVI();
	void spawnConfigVII();
	void spawnConfigVIII();
};