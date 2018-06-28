#pragma once
#include "Entity.h"
class Enemy :
	public Entity
{
public:
	Enemy(float x, float y, float o);
	Enemy();
	~Enemy();

	void update();
};

