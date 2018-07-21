#include "ofMain.h"
#include "Stopwatch.h"

class Bullet {
	float xLoc, yLoc, orientation;
	int damage;
	float distanceTraveled, speed, range;
	
public:
	Bullet(float x, float y, float theta, int damage);
	~Bullet();

	void update();

	void draw() const;

	float getX() const;
	float getY() const;
	int getDamage() const;

	bool hasExpired() const;
};