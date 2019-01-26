#ifndef CELL
#define CELL

class Cell {
public:
	Cell(int pPositionX, int pPositionY);

	~Cell();

	bool isLife();

	int getPositionX();
	int getPositionY();

	void setLife();
	void setDead();
private:
	bool _isLife;

	int _positionX, _positionY;
};

#endif CELL_H