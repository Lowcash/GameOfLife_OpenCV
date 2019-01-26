#include "pch.h"
#include "playground.h"

Playground::Playground(int pWidth, int pHeight, int pMinPlaygroundSize, int pMaxPlaygroundSize) {
	this->_width = pWidth < pMinPlaygroundSize ? pMinPlaygroundSize : pWidth;
	this->_width = pWidth > pMaxPlaygroundSize ? pMaxPlaygroundSize : pWidth;
	this->_height = pHeight < pMinPlaygroundSize ? pMinPlaygroundSize : pHeight;
	this->_height = pHeight > pMaxPlaygroundSize ? pMaxPlaygroundSize : pHeight;

	this->initCells(pWidth, pHeight);
}

Playground::~Playground() {}

int Playground::getWidth() {
	return this->_width;
}

int Playground::getHeight() {
	return this->_height;
}

void Playground::initCells(int pWidth, int pHeight) {
	resetPlayground();

	for (int y = 0; y < pHeight; y++) {
		for (int x = 0; x < pWidth; x++) {
			playgroundCells.push_back(Cell(x, y));
		}
	}
}

void Playground::resetPlayground() {
	for (int i = 0; i < playgroundCells.size(); i++) {
		playgroundCells[i].setDead();
	}
}

Cell *PlaygroundHelper::getCellFromPlayground(Playground &pPlayground, int pPositionX, int pPositionY) {
	return &pPlayground.playgroundCells[(pPlayground.getWidth() * pPositionY) + pPositionX];
}

Cell *PlaygroundHelper::getCellNeighborOnDirectionFromPlayground(Playground &pPlayground, Cell pCell, NeighborOnDirection pNeighborOnDirection) {
	switch (pNeighborOnDirection)
	{
	case NeighborOnDirection::NORTH:
		return getCellFromPlayground(pPlayground, pCell.getPositionX(), pCell.getPositionY() - 1);
	case NeighborOnDirection::EAST:
		return getCellFromPlayground(pPlayground, pCell.getPositionX() + 1, pCell.getPositionY());
	case NeighborOnDirection::SOUTH:
		return getCellFromPlayground(pPlayground, pCell.getPositionX(), pCell.getPositionY() + 1);
	case NeighborOnDirection::WEST:
		return getCellFromPlayground(pPlayground, pCell.getPositionX() - 1, pCell.getPositionY());
	case NeighborOnDirection::NORTH_WEST:
		return getCellFromPlayground(pPlayground, pCell.getPositionX() - 1, pCell.getPositionY() - 1);
	case NeighborOnDirection::NORTH_EAST:
		return getCellFromPlayground(pPlayground, pCell.getPositionX() + 1, pCell.getPositionY() - 1);
	case NeighborOnDirection::SOUTH_WEST:
		return getCellFromPlayground(pPlayground, pCell.getPositionX() - 1, pCell.getPositionY() + 1);
	case NeighborOnDirection::SOUTH_EAST:
		return getCellFromPlayground(pPlayground, pCell.getPositionX() + 1, pCell.getPositionY() + 1);
	}

	return getCellFromPlayground(pPlayground, pCell.getPositionX() + 1, pCell.getPositionY() + 1);
}