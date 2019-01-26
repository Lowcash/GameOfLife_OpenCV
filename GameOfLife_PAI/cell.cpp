#include "pch.h"
#include "cell.h"

Cell::Cell(int pPositionX, int pPositionY) {
	this->_positionX = pPositionX;
	this->_positionY = pPositionY;
}

Cell::~Cell() {}

bool Cell::isLife() {
	return this->_isLife;
}

int Cell::getPositionX() {
	return this->_positionX;
}

int Cell::getPositionY() {
	return this->_positionY;
}

void Cell::setLife() {
	this->_isLife = true;
}

void Cell::setDead() {
	this->_isLife = false;
}