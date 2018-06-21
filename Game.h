#pragma once
#include "Entity.h"

extern int screenWidth, screenHeight;

class Game : public ofBaseApp
{
	Entity* player = new Entity(40, 40, 0);

public:

	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
};

