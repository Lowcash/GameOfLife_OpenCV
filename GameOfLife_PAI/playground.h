#ifndef PLAYGROUND_
#define PLAYGROUND_

#include "pch.h"

class Playground {
public:
	Playground();
	~Playground();

	int getWidth();
	int getHeight();
private:
	int _minPlaygroundSize, _maxPlaygroundSize;

	int _width, _height;
	
	std::vector<int> vektor;
};

#endif // PLAYGROUND_H