#include "Stopwatch.h"

Stopwatch::Stopwatch() {
	//start = std::chrono::high_resolution_clock::now();
	start = ofGetElapsedTimef();
}

Stopwatch::~Stopwatch() {}

void Stopwatch::reset() {
	//start = std::chrono::high_resolution_clock::now();
	start = ofGetElapsedTimef();
}

float Stopwatch::read() {
	//return (std::chrono::high_resolution_clock::now() - start).count();
	return ofGetElapsedTimef() - start;
}