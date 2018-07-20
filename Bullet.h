#include "ofMain.h"
#include "Stopwatch.h"

class Bullet {
	float xLoc, yLoc, orientation, distanceTraveled;
	float speed, range;
	int damage;
public:
	Bullet(float x, float y, float theta, int damage);
	~Bullet();

	void update();
	void draw() const;

	bool hasExpired();

	float getX();
	float getY();
	int getDamage();
};