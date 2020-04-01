#ifndef __CONSTANTS_H__
#define __CONSTANTS_H__

#define HEIGHT 10
#define WIDTH 10
#define START_LEN 4

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

#include <list>
#include <iostream>
#include <conio.h>
#include <vector>
#include <utility>
#include <algorithm>
#include <iterator>

using namespace std;

struct coord{
	coord(int X, int Y){this->x = X; this->y = Y;}
	int x;
	int y;
};


#endif