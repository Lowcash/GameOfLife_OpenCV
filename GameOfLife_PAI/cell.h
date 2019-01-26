#ifndef CELL
#define CELL

class Cell {
public:
	Cell();
	Cell(int pPositionX, int pPositionY);

	~Cell();

	bool isLife();

	int getPositionX();
	int getPositionY();

private:
	bool _islife;

	int _positionX, _positionY;
};

#endif CELL_H