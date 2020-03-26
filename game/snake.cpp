#include "snake.h"

Snake::Snake()
{

}

Snake::~Snake()
{
}

void Snake::init(int x = 7, int y = 7, char fill_char = '#')
{
	coord.push_back(make_pair(x, y));
	for (int i = 0; i < START_LEN; i++) {
		//coord.push_back(make_pair(coord.end));
	}
}
