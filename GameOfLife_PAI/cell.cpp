#include "cell.h"

Cell::Cell() { }

Cell::Cell(int pPositionX, int pPositionY) {
	this->_positionX = pPositionX;
	this->_positionY = pPositionY;
}

Cell::~Cell() {}

bool Cell::isLife() {
	return this->isLife;
}

int Cell::getPositionX() {
	return this->_positionX;
}

int Cell::getPositionY() {
	return this->getPositionY;
}