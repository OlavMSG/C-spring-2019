#include "MinesweeperWindow.h"

MinesweeperWindow::MinesweeperWindow(Point xy, int width, int height, int mines, const string& title) :
	Graph_lib::Window(xy, width * cellSize, height*cellSize, title), width(width), height(height), mines(mines), TilesLeft(height * width), VinnerText{Point{50, 50}, "Du har vunnet!"},
	TaperText{Point{50, 50}, "Du har Tapt!"}
	//Initialiser medlemsvariabler, bruker også konstruktøren til Windowsklassen
{
	// Legg til alle tiles på vinduet
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			int y = i* cellSize,
				x = j * cellSize;
			tiles.push_back(new Tile{ Point{x, y}, cellSize, cb_click });
			attach(tiles.back());
		}
	}
	
	//tekster
	VinnerText.set_font_size(20);
	TaperText.set_font_size(20);
	VinnerText.set_color(Color::red);
	TaperText.set_color(Color::red);

	//Legg til miner på tilfeldige posisjoner
	int MineCount = 0;
	while (true)
	{
		int tilfeldig_tall = rand() % (width * height);
		if (!tiles[tilfeldig_tall].isMine)
		{
			tiles[tilfeldig_tall].isMine = true;
			MineCount += 1;
		}
		if (MineCount == mines)
		{
			break;
		}
	}


	// Fjern window reskalering
	resizable(nullptr);
	size_range(x_max(), y_max(), x_max(), y_max());
}

int MinesweeperWindow::countMines(vector<Point> points) const {
	int MineCount = 0;
	for (Point point : points)
	{
		if (at(point).isMine)
		{
			MineCount += 1;
		}
	}
	return MineCount;
};

vector<Point> MinesweeperWindow::adjacentPoints(Point xy) const {
	vector<Point> points;
	for (int di = -1; di <= 1; ++di) {
		for (int dj = -1; dj <= 1; ++dj) {
			if (di == 0 && dj == 0) {
				continue;
			}

			Point neighbour{ xy.x + di * cellSize,xy.y + dj * cellSize };
			if (inRange(neighbour)) {
				points.push_back(neighbour);
			}
		}
	}

	return points;
}

void MinesweeperWindow::openTile(Point xy) {
	if (at(xy).state == Cell::closed)
	{
		at(xy).open();
		TilesLeft -= 1;
		if (!at(xy).isMine)
		{
			vector<Point> points = adjacentPoints(xy);
			int MineCount = countMines(points);
			if (MineCount != 0) 
			{
				at(xy).setAdjMines(MineCount);
			}
			else
			{
				for (Point point : points)
				{
					openTile(point);
				}
			}
			if (TilesLeft == mines)
			{
				//won
				for (Tile *tile : tiles)
				{
					if (tile->isMine)
					{
						tile->flag();
					}
				}
				attach(VinnerText);
				//hide();
			}
		}
		else
		{
			//tap
			for (Tile *tile : tiles)
			{
				if (tile->isMine)
				{
					tile->set_label("X");
					tile->set_label_color(Color::red);
				}
			}
			attach(TaperText);
			////hide();
		}
	}

}

void MinesweeperWindow::flagTile(Point xy) {
	if (at(xy).state != Cell::open)
	{
		at(xy).flag();
	}
}

//Kaller opentile ved venstreklikk og flagTile ved høyreklikk
void MinesweeperWindow::cb_click(Address, Address pw)
{
	Point xy{ Fl::event_x(),Fl::event_y() };
	MouseButton mb = static_cast<MouseButton>(Fl::event_button());
	auto& win = reference_to<MinesweeperWindow>(pw);

	if (!win.inRange(xy)) {
		return;
	}

	switch (mb) {
	case MouseButton::left:
		win.openTile(xy);
		break;
	case MouseButton::right:
		win.flagTile(xy);
		break;
	}
	win.flush();
}
