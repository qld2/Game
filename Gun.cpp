#include "Gun.h"

Gun::Gun()
{
	fireTimer = Stopwatch();
	reloadTimer = Stopwatch();
	gunGUI.load("scifibit.ttf", 40, true, true);
}


Gun::~Gun()
{
}

void Gun::update() {

	if (bulletsInClip == 0) {
		reload();
	}

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

void Gun::drawGUI() const {
	stringstream ss1;
	ss1 << bulletsInClip << " : " << bulletsOnPlayer;
	
	gunGUI.drawString(ss1.str(), ofGetScreenWidth() - 200, ofGetScreenHeight() - 100);
}

void Gun::shoot(float x, float y, float o) {
	if (fireTimer.read() > fireGap && bulletsInClip > 0) {
		bullets.push_back(Bullet(x, y, o, 4));
		fireTimer.reset();
		bulletsInClip--;
	}
}

void Gun::reload() {
	static Stopwatch reloadTimer2 = Stopwatch();
	static bool reloading = false;

	if (!reloading) {
		reloadTimer2.reset();
		reloading = true;
	}

	if (reloadTimer2.read() > reloadTime) {
		if (bulletsOnPlayer < clipSize) {
			bulletsInClip = bulletsOnPlayer;
			bulletsOnPlayer = 0;
		}
		else {
			bulletsInClip = clipSize;
			bulletsOnPlayer -= clipSize;
		}
		reloading = false;
	}

}

vector<Bullet>& Gun::getBullets() {
	return bullets;
}