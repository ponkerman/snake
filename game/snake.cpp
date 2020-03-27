#include "snake.h"

Snake::Snake()
{

}

Snake::~Snake()
{
}

int Snake::init(int x = 7, int y = 7, int fHeight, int fWidth)
{
	coord.push_back(make_pair(x, y));
	if( fWidth - x < START_LEN && 
		x - fWidth < START_LEN &&
		fHeight - y < START_LEN &&
		y - fHeight < START_LEN
		)
	for (int i = 1; i < START_LEN; i++) {
		coord.push_back(make_pair(coord.back().first - 1, coord.back().second - 1));
	}
}
