#pragma once
#include <chrono>

class Stopwatch
{
	std::chrono::time_point<std::chrono::steady_clock> start;
public:
	Stopwatch();
	~Stopwatch();

	void reset();
	float read();
};