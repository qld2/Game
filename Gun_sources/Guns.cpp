#include "..\Gun_headers\Guns.h"

P90::P90() : Gun() {
	name = "P90";

	damage = 60;
	range = 10;
	speed = 7;

	fireGap = .5;
	reloadTime = 2;

	clipSize = 12;
	bulletsOnPlayer = 100;
	bulletsInClip = clipSize;

	bulletRandomness = PI / 100;
}

Revolver::Revolver() : Gun() {
	name = "REVOLVER";

	damage = 80;
	range = 800;
	speed = 15;

	fireGap = .7;
	reloadTime = 2;

	clipSize = 6;
	bulletsOnPlayer = 150;
	bulletsInClip = clipSize;

	bulletRandomness = PI / 150;
}

Assault::Assault() : Gun() {
	name = "ASSAULT";

	damage = 35;
	range = 550;
	speed = 12;

	fireGap = .3;
	reloadTime = 4;

	clipSize = 30;
	bulletsOnPlayer = 250;
	bulletsInClip = clipSize;

	bulletRandomness = PI / 75;
}

LMG::LMG() : Gun() {
	name = "LMG";

	damage = 30;
	range = 1000;
	speed = 10;

	fireGap = .25;
	reloadTime = 6;

	clipSize = 185;
	bulletsOnPlayer = 700;
	bulletsInClip = clipSize;

	bulletRandomness = PI / 75;
}

SMG::SMG() : Gun() {
	name = "LMG";

	damage = 25;
	range = 425;
	speed = 25;

	fireGap = .08;
	reloadTime = 4;

	clipSize = 185;
	bulletsOnPlayer = 700;
	bulletsInClip = clipSize;

	bulletRandomness = PI / 75;
}

RandomCanon::RandomCanon() : Gun() {
	name = "Random Canon";

	damage = 100;
	range = 500;
	speed = 8;

	fireGap = .08;
	reloadTime = 7;

	clipSize = 60;
	bulletsOnPlayer = 360;
	bulletsInClip = clipSize;

	bulletRandomness = PI;
}


Flamethrower::Flamethrower() : Gun() {
	name = "FLAMETHROWER";

	damage = 10;
	range = 350;
	speed = 3.5;

	fireGap = .01;
	reloadTime = 10;

	clipSize = 100;
	bulletsOnPlayer = 1000;
	bulletsInClip = clipSize;

	bulletRandomness = PI / 25;
}