#include "pch.h"
#include "shapes.h"

void Shapes::setBlinkerTo(int pPositionX, int pPositionY, Playground &pPlayground) {
	if (pPlayground.getWidth() > pPositionX + 2 && pPlayground.getHeight() > pPositionY + 2)
	{
		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX, pPositionY + 0)->setLife();
		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX, pPositionY + 1)->setLife();
		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX, pPositionY + 2)->setLife();
	}
}

void Shapes::setGliderTo(int pPositionX, int pPositionY, Playground &pPlayground) {
	if (pPlayground.getWidth() > pPositionX + 2 && pPlayground.getHeight() > pPositionY + 2)
	{
		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX + 1, pPositionY + 0)->setLife();
		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX + 2, pPositionY + 1)->setLife();
		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX + 2, pPositionY + 1)->setLife();
		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX + 0, pPositionY + 2)->setLife();
	}
}

void Shapes::setBeaconTo(int pPositionX, int pPositionY, Playground &pPlayground) {
	if (pPlayground.getWidth() > pPositionX + 3 && pPlayground.getHeight() > pPositionY + 3)
	{
		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX + 0, pPositionY + 0)->setLife();
		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX + 0, pPositionY + 1)->setLife();
		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX + 1, pPositionY + 0)->setLife();
		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX + 1, pPositionY + 1)->setLife();
		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX + 2, pPositionY + 2)->setLife();
		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX + 2, pPositionY + 3)->setLife();
		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX + 3, pPositionY + 2)->setLife();
		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX + 3, pPositionY + 3)->setLife();
	}
}

void Shapes::setBeehiveTo(int pPositionX, int pPositionY, Playground &pPlayground) {
	if (pPlayground.getWidth() > pPositionX + 2 && pPlayground.getHeight() > pPositionY + 2)
	{
		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX + 1, pPositionY + 0)->setLife();
		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX + 2, pPositionY + 0)->setLife();
		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX + 0, pPositionY + 1)->setLife();
		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX + 3, pPositionY + 1)->setLife();
		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX + 1, pPositionY + 2)->setLife();
		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX + 2, pPositionY + 2)->setLife();
	}
}

void Shapes::setLoafTo(int pPositionX, int pPositionY, Playground &pPlayground) {
	if (pPlayground.getWidth() > pPositionX + 3 && pPlayground.getHeight() > pPositionY + 3)
	{
		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX + 1, pPositionY + 0)->setLife();
		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX + 2, pPositionY + 0)->setLife();
		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX + 3, pPositionY + 1)->setLife();
		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX + 3, pPositionY + 2)->setLife();
		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX + 0, pPositionY + 1)->setLife();
		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX + 1, pPositionY + 2)->setLife();
		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX + 2, pPositionY + 3)->setLife();
	}
}

void Shapes::setBoatTo(int pPositionX, int pPositionY, Playground &pPlayground) {
	if (pPlayground.getWidth() > pPositionX + 2 && pPlayground.getHeight() > pPositionY + 2)
	{
		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX + 0, pPositionY + 0)->setLife();
		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX + 0, pPositionY + 1)->setLife();
		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX + 1, pPositionY + 0)->setLife();
		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX + 2, pPositionY + 1)->setLife();
		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX + 1, pPositionY + 2)->setLife();
	}
}

void Shapes::setBlockTo(int pPositionX, int pPositionY, Playground &pPlayground) {
	if (pPlayground.getWidth() > pPositionX + 4 && pPlayground.getHeight() > pPositionY + 4)
	{
		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX + 0, pPositionY + 0)->setLife();
		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX + 0, pPositionY + 1)->setLife();
		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX + 1, pPositionY + 0)->setLife();
		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX + 1, pPositionY + 1)->setLife();

		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX + 3, pPositionY + 0)->setLife();
		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX + 3, pPositionY + 1)->setLife();
		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX + 4, pPositionY + 0)->setLife();
		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX + 4, pPositionY + 1)->setLife();
	}
}

void Shapes::setPulsar(int pPositionX, int pPositionY, Playground &pPlayground) {
	if (pPlayground.getWidth() > pPositionX + 12 && pPlayground.getHeight() > pPositionY + 12)
	{
		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX +  2, pPositionY +  0)->setLife();
		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX +  3, pPositionY +  0)->setLife();
		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX +  4, pPositionY +  0)->setLife();
																		   				    
		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX +  8, pPositionY +  0)->setLife();
		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX +  9, pPositionY +  0)->setLife();
		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX + 10, pPositionY +  0)->setLife();

		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX +  2, pPositionY + 12)->setLife();
		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX +  3, pPositionY + 12)->setLife();
		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX +  4, pPositionY + 12)->setLife();
																		   
		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX +  8, pPositionY + 12)->setLife();
		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX +  9, pPositionY + 12)->setLife();
		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX + 10, pPositionY + 12)->setLife();

		//--------------------------------------------------------------------------------------------//

		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX +  0, pPositionY +  2)->setLife();
		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX +  0, pPositionY +  3)->setLife();
		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX +  0, pPositionY +  4)->setLife();
																		   				    
		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX +  0, pPositionY +  8)->setLife();
		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX +  0, pPositionY +  9)->setLife();
		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX +  0, pPositionY + 10)->setLife();

		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX + 12, pPositionY +  2)->setLife();
		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX + 12, pPositionY +  3)->setLife();
		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX + 12, pPositionY +  4)->setLife();
																						    
		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX + 12, pPositionY +  8)->setLife();
		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX + 12, pPositionY +  9)->setLife();
		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX + 12, pPositionY + 10)->setLife();

		//--------------------------------------------------------------------------------------------//

		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX +  2, pPositionY + 5)->setLife();
		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX +  3, pPositionY + 5)->setLife();
		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX +  4, pPositionY + 5)->setLife();
		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX +  8, pPositionY + 5)->setLife();
		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX +  9, pPositionY + 5)->setLife();
		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX + 10, pPositionY + 5)->setLife();

		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX +  2, pPositionY + 7)->setLife();
		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX +  3, pPositionY + 7)->setLife();
		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX +  4, pPositionY + 7)->setLife();
		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX +  8, pPositionY + 7)->setLife();
		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX +  9, pPositionY + 7)->setLife();
		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX + 10, pPositionY + 7)->setLife();

		//--------------------------------------------------------------------------------------------//

		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX + 5, pPositionY +  2)->setLife();
		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX + 5, pPositionY +  3)->setLife();
		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX + 5, pPositionY +  4)->setLife();
		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX + 5, pPositionY +  8)->setLife();
		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX + 5, pPositionY +  9)->setLife();
		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX + 5, pPositionY + 10)->setLife();

		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX + 7, pPositionY +  2)->setLife();
		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX + 7, pPositionY +  3)->setLife();
		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX + 7, pPositionY +  4)->setLife();
		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX + 7, pPositionY +  8)->setLife();
		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX + 7, pPositionY +  9)->setLife();
		PlaygroundHelper::getCellFromPlayground(pPlayground, pPositionX + 7, pPositionY + 10)->setLife();
	}
}