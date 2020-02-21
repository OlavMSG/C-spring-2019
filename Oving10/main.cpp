#include "MinesweeperWindow.h"

int main()
{

	Fl::background(200, 200, 200);
	constexpr int width = 10;
	constexpr int height = 10;
	constexpr int mines = 3;

	Point startPoint{ 200,300 };
	srand(static_cast<unsigned int>(time(nullptr)));
	MinesweeperWindow mw{ startPoint, width, height, mines, "Minesweeper" };
	return gui_main();

}
 