#include "ofMain.h"
#include "Stopwatch.h"

class Bullet {
	Stopwatch * deathClock;
	float xLoc, yLoc, orientation;
	float speed;
	int damage;
public:
	Bullet(float x, float y, float theta);
	~Bullet();

	void update();
	void draw();

	bool hasDied();
};