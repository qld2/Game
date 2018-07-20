#pragma once
#include <chrono>
#include "ofMain.h"

class Stopwatch
{
	//std::chrono::time_point<std::chrono::steady_clock> start;
	float start;
public:
	Stopwatch();
	~Stopwatch();

	void reset();
	float read();
};