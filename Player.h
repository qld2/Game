#pragma once
#include "Entity.h"
class Player :
	public Entity	
{
public:
	Player(float x, float y, float o);
	Player();
	~Player();

	void update() override;

private:
	vector<float>& getBoundariesX();
	vector<float>& getBoundariesY();
	bool checkWallBoundaries(vector<float>& x, vector<float>& y, float newX, float newY);
	bool checkWallBoundaries(float deltaO);
	void reachBoundary(vector<float>& x, vector<float>& y, float deltaX, float deltaY);
};

