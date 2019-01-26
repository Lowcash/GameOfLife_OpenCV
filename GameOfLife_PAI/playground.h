#ifndef PLAYGROUND_
#define PLAYGROUND_

#include "cell.h"

class Playground {
public:
	Playground(int pWidth, int pHeight, int pMinPlaygroundSize, int pMaxPlaygroundSize);
	~Playground();

	int getWidth();
	int getHeight();

	void initCells(int pWidth, int pHeight);
	void resetPlayground();

	std::vector<Cell> playgroundCells;
private:
	int _width, _height;
};

class PlaygroundHelper {
public:
	static enum NeighborOnDirection { NORTH, EAST, SOUTH, WEST, NORTH_WEST, NORTH_EAST, SOUTH_WEST, SOUTH_EAST };

	static Cell *getCellFromPlayground(Playground &pPlayground, int pPosition, int pPositionY);
	static Cell *getCellNeighborOnDirectionFromPlayground(Playground &pPlayground, Cell pCell, NeighborOnDirection pNeighborOnDirection);
};

#endif // PLAYGROUND_H