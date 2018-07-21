#include "Gun.h"

Gun::Gun()
{
	fireTimer = Stopwatch();
}


Gun::~Gun()
{
}

void Gun::update() {

	for (int i = bullets.size() - 1; i >= 0; i--) {
		if (bullets[i].hasExpired()) {
			bullets[i] = bullets.back();
			bullets.pop_back();
			i--;
		}
	}

	for (int i = 0; i < bullets.size(); i++) {
		bullets[i].update();
	}
}

void Gun::draw() const {
	for (int i = 0; i < bullets.size(); i++) {
		bullets[i].draw();
	}

}

void Gun::shoot(float x, float y, float o) {
	if (fireTimer.read() > fireGap) {
		bullets.push_back(Bullet(x, y, o, 4));
		fireTimer.reset();
	}
}

vector<Bullet>& Gun::getBullets() {
	return bullets;
}