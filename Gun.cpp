#include "Gun.h"

Gun::Gun()
{
}


Gun::~Gun()
{
}

void Gun::update() {

	for (int i = 0; i < bulletsExisting; i++) {
		if (bullets[i]->hasDied()) {
			delete bullets[i];
			bulletsExisting--;
		}
	}

	for (int i = 0; i < bulletsExisting; i++) {
		bullets[i]->update();
	}
}

void Gun::draw() {
	for (int i = 0; i < bulletsExisting; i++) {
		bullets[i]->draw();
	}

}

void Gun::shoot(float x, float y, float o) {
	bullets[bulletsExisting] = new Bullet(x, y, o);
	bulletsExisting++;
}