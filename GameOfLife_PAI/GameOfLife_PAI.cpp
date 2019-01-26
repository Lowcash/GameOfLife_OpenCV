#include "pch.h"
#include "playground.h"
#include "shapes.h"

const int maxPlaygroundSize = 463;
const int minPlaygroundSize = 10;
const cv::Vec3f liveCellColor = cv::Vec3f(1, 1, 1);
const cv::Vec3f deadCellColor = cv::Vec3f(0, 0, 0);

Playground *mainPlayground = nullptr;
Playground *temporaryPlayground = nullptr;

cv::Mat mainPlaygroundImgSource;

bool isSingleThreadRun = false;
bool isParallelThreadRun = false;

bool isGameRun = false;

int numOfThreads = 1;

int numOfCols = 200;
int numOfRows = 200;

int generationProbability = 1;

std::string game = "GameOfLife";

void initGame(std::string nameOfGame);
void createNewGame();
Playground *getPlayground(int pWidth, int pHeight);
cv::Mat getPlaygroundImgSource(int pWidth, int pHeight);
void generatePlayground(Playground &pPlayground);
void playgroundToBitmap(Playground pPlayground, cv::Mat &pImgSource);
cv::Vec3f getCellColor(Cell *pCell);
void redraw(std::string nameOfWindow);
void runGame();
int getNumCellNeighbors(Cell *pCell);
void swapAndClearPlayground(Playground &pPlayground, Playground &pPlaygroundToSwap);

int main()
{
	initGame(game);

	createNewGame();

	redraw(game);

	while (true) {
		runGame();
	}

	system("PAUSE");

	mainPlayground = NULL;
	temporaryPlayground = NULL;

	delete mainPlayground;
	delete temporaryPlayground;
}

void initGame(std::string nameOfGame) { 
	cv::namedWindow(nameOfGame);
}

void createNewGame() {
	mainPlayground = getPlayground(numOfCols, numOfRows);
	temporaryPlayground = getPlayground(numOfCols, numOfRows);

	mainPlaygroundImgSource = getPlaygroundImgSource(numOfCols, numOfRows);

	generatePlayground(*mainPlayground);
	playgroundToBitmap(*mainPlayground, mainPlaygroundImgSource);
}

Playground *getPlayground(int pWidth, int pHeight) {
	return new Playground(pWidth, pHeight, minPlaygroundSize, maxPlaygroundSize);
}

cv::Mat getPlaygroundImgSource(int pWidth, int pHeight) {
	return cv::Mat(cv::Size(pWidth, pHeight), CV_32FC3);
}

void generatePlayground(Playground &pPlayground) {
	pPlayground.resetPlayground();
	
	for (int i = 0; i < pPlayground.playgroundCells.size(); i++) {
		if ((rand() % 100) < generationProbability) {
			Cell cell = pPlayground.playgroundCells[i];

			switch (rand() % Shapes::NUM_OF_SHAPES) {
			case (int)Shapes::BEACON: Shapes::setBeaconTo(cell.getPositionX(), cell.getPositionY(), pPlayground); break;
			case (int)Shapes::BEEHIVE: Shapes::setBeehiveTo(cell.getPositionX(), cell.getPositionY(), pPlayground); break;
			case (int)Shapes::BLINKER: Shapes::setBlinkerTo(cell.getPositionX(), cell.getPositionY(), pPlayground); break;
			case (int)Shapes::BLOCK: Shapes::setBlockTo(cell.getPositionX(), cell.getPositionY(), pPlayground); break;
			case (int)Shapes::BOAT: Shapes::setBoatTo(cell.getPositionX(), cell.getPositionY(), pPlayground); break;
			case (int)Shapes::GLIDER: Shapes::setGliderTo(cell.getPositionX(), cell.getPositionY(), pPlayground); break;
			case (int)Shapes::LOAF: Shapes::setLoafTo(cell.getPositionX(), cell.getPositionY(), pPlayground); break;
			case (int)Shapes::PULSAR: Shapes::setPulsar(cell.getPositionX(), cell.getPositionY(), pPlayground); break;
			}
		}
	}
}

void playgroundToBitmap(Playground pPlayground, cv::Mat &pImgSource) {
	for (int x = 0; x < pPlayground.getWidth(); x++) {
		for (int y = 0; y < pPlayground.getHeight(); y++) {
			pImgSource.at<cv::Vec3f>(x, y) = getCellColor(PlaygroundHelper::getCellFromPlayground(pPlayground, x, y));
		}
	}
}

cv::Vec3f getCellColor(Cell *pCell) {
	return pCell->isLife() ? liveCellColor : deadCellColor;
}

void redraw(std::string nameOfWindow) {
	cv::Mat result;
	cv::resize(mainPlaygroundImgSource, result, cv::Size(maxPlaygroundSize, maxPlaygroundSize));

	cv::imshow(nameOfWindow, result);

	cv::waitKey(0);
}

void runGame() {
	for (int i = 0; i < mainPlayground->playgroundCells.size(); i++) {
		Cell cell = mainPlayground->playgroundCells[i];

		int numCellNeigbors = getNumCellNeighbors(&cell);

		if (cell.isLife()) {
			temporaryPlayground->playgroundCells[i].setLife();

			if (numCellNeigbors < 2 || numCellNeigbors > 3) {
				temporaryPlayground->playgroundCells[i].setDead();
			}
		}
		else {
			temporaryPlayground->playgroundCells[i].setDead();

			if (numCellNeigbors == 3) {
				temporaryPlayground->playgroundCells[i].setLife();
			}
		}
	}

	swapAndClearPlayground(*mainPlayground, *temporaryPlayground);
	playgroundToBitmap(*mainPlayground, mainPlaygroundImgSource);

	redraw(game);
}

int getNumCellNeighbors(Cell *pCell) {
	int counter = 0;

	if ((pCell->getPositionX() < mainPlayground->getWidth() - 1) && PlaygroundHelper::getCellNeighborOnDirectionFromPlayground(*mainPlayground, *pCell, PlaygroundHelper::NeighborOnDirection::EAST)->isLife()) counter++;
	if ((pCell->getPositionY() < mainPlayground->getHeight() - 1) && PlaygroundHelper::getCellNeighborOnDirectionFromPlayground(*mainPlayground, *pCell, PlaygroundHelper::NeighborOnDirection::SOUTH)->isLife()) counter++;
	if ((pCell->getPositionY() > 0) && PlaygroundHelper::getCellNeighborOnDirectionFromPlayground(*mainPlayground, *pCell, PlaygroundHelper::NeighborOnDirection::NORTH)->isLife()) counter++;
	if ((pCell->getPositionX() > 0) && PlaygroundHelper::getCellNeighborOnDirectionFromPlayground(*mainPlayground, *pCell, PlaygroundHelper::NeighborOnDirection::WEST)->isLife()) counter++;
	if ((pCell->getPositionY() > 0 && pCell->getPositionX() < mainPlayground->getWidth() - 1) && PlaygroundHelper::getCellNeighborOnDirectionFromPlayground(*mainPlayground, *pCell, PlaygroundHelper::NeighborOnDirection::NORTH_EAST)->isLife())
		counter++;
	if ((pCell->getPositionY() > 0 && pCell->getPositionX() > 0) && PlaygroundHelper::getCellNeighborOnDirectionFromPlayground(*mainPlayground, *pCell, PlaygroundHelper::NeighborOnDirection::NORTH_WEST)->isLife())
		counter++;
	if ((pCell->getPositionY() < mainPlayground->getHeight() - 1 && pCell->getPositionX() < mainPlayground->getWidth() - 1) && PlaygroundHelper::getCellNeighborOnDirectionFromPlayground(*mainPlayground, *pCell, PlaygroundHelper::NeighborOnDirection::SOUTH_EAST)->isLife())
		counter++;
	if ((pCell->getPositionY() < mainPlayground->getHeight() - 1 && pCell->getPositionX() > 0) && PlaygroundHelper::getCellNeighborOnDirectionFromPlayground(*mainPlayground, *pCell, PlaygroundHelper::NeighborOnDirection::SOUTH_WEST)->isLife())
		counter++;

	return counter;
}

void swapAndClearPlayground(Playground &pPlaygroundResult, Playground &pPlaygroundToSwap) {
	for (int i = 0; i < pPlaygroundResult.playgroundCells.size(); i++) {
		Cell *cell = &pPlaygroundResult.playgroundCells[i];

		if (pPlaygroundToSwap.playgroundCells[i].isLife()) {
			cell->setLife();
		}
		else {
			cell->setDead();
		}

		pPlaygroundToSwap.playgroundCells[i].setDead();
	}
}
