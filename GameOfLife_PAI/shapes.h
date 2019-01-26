#ifndef SHAPES
#define SHAPES

#include "playground.h"

class Shapes {
public:
	enum ShapesType { BLINKER, GLIDER, BEACON, BEEHIVE, LOAF, BOAT, BLOCK, PULSAR, NUM_OF_SHAPES };

	static void setBlinkerTo(int pPositionX, int pPositionY, Playground pPlayground);
	static void setGliderTo(int pPositionX, int pPositionY, Playground pPlayground);
	static void setBeaconTo(int pPositionX, int pPositionY, Playground pPlayground);
	static void setBeehiveTo(int pPositionX, int pPositionY, Playground pPlayground);
	static void setLoafTo(int pPositionX, int pPositionY, Playground pPlayground);
	static void setBoatTo(int pPositionX, int pPositionY, Playground pPlayground);
	static void setBlockTo(int pPositionX, int pPositionY, Playground pPlayground);
	static void setPulsar(int pPositionX, int pPositionY, Playground pPlayground);
};

#endif // !SHAPES_H
