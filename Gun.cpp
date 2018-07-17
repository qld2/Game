#include "Gun.h"

Gun::Gun()
{
	fireTimer = new Stopwatch();
}


Gun::~Gun()
{
}

void Gun::update() {

	for (int i = bullets.size() - 1; i >= 0; i--) {
		if (bullets[i]->hasExpired()) {
			bullets[i] = bullets.back();
			bullets.pop_back();
			i--;
		}
	}

	for (int i = 0; i < bullets.size(); i++) {
		bullets[i]->update();
	}
}

void Gun::draw() {
	for (int i = 0; i < bullets.size(); i++) {
		bullets[i]->draw();
	}

}

void Gun::shoot(float x, float y, float o) {
	if (fireTimer->read() > fireGap) {
		bullets.push_back(new Bullet(x, y, o, 2));
		fireTimer->reset();
	}
}

vector<Bullet*>& Gun::getBullets() {
	return bullets;
}