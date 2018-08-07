#pragma once
#include "Roundcontroller.h"
#include "ofMain.h"

class GUI {
	Roundcontroller* roundController;
	int roundNumber;

public:
	GUI(Roundcontroller* roundController);
	GUI();

	void update();
	void draw() const;
private:

};