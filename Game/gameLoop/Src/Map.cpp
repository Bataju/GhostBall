#include "Map.h"
#include "Game.h"
#include <fstream>

Map::Map()
{
}
Map::~Map()
{
}

//coordinate system
void Map::LoadMap(std::string path, int sizeX, int sizeY, int loop)
{
	/*char c;
	std::fstream mapFile;
	int xij, yij = 0;

	mapFile.open(path);
	int srcX, srcY;
	for (int y = 0; y < sizeY; y++)
	{
		for (int x = 0; x < sizeX; x++)
		{
			xij = sizeX * loop + x;
			mapFile.get(c);
			srcY = atoi(&c) * 32;
			mapFile.get(c);
			srcX = atoi(&c) * 32;
			Game::addTile(srcX, srcY, xij * 64, y * 64);  //Tile size
			mapFile.ignore();
		}
	}
	mapFile.close();*/
	char c;
	std::fstream mapFile;
	int xij, yij = 0;

	static int prevSize = 0;
	mapFile.open(path);
	int srcX, srcY;

	for (int y = 0; y < sizeY; y++)
	{
		for (int x = 0; x < sizeX; x++)
		{
			if (loop < 2)
				xij = prevSize * loop + x;
			else
				xij = prevSize * loop + x - 20;

			mapFile.get(c);
			srcY = atoi(&c) * 64;
			mapFile.get(c);
			srcX = atoi(&c) * 64;
			Game::addTile(srcX, srcY, xij * 64, y * 64);  //Tile size
			mapFile.ignore();
		}
	}
	mapFile.close();
	prevSize = sizeX;
}

//single tile system
//void Map::LoadMap(std::string path, int sizeX, int sizeY)
//{
//	char tile;
//	std::fstream mapFile;
//	mapFile.open(path);
//
//	for (int row = 0;row < sizeY; row++)
//	{
//		for (int x = 0; x < sizeX; x++)
//		{
//			mapFile.get(tile);
//			Game::addTile(atoi(&tile), x * 64, row * 64);  //Tile size
//			mapFile.ignore();
//		}
//	}
//
//	mapFile.close();
//}



