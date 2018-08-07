#include "GUI.h"

GUI::GUI(Roundcontroller* roundController) : roundController(roundController) {
	roundNumber = roundController->getRound();
}

GUI::GUI() : roundController(new Roundcontroller()) {}

void GUI::update() {
	roundNumber = roundController->getRound();
}

void GUI::draw() const {

	stringstream ss;
	ss << roundNumber;
	string round = ss.str();
}