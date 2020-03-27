#ifndef __SNAKE_H__
#define __SNAKE_H__

#include "constants.h"

class Snake 
{
public:
	Snake();
	~Snake();
	int init(int x = -1, int y = -1);
	int move(int);
	int getLen();
	list<coord*>* getCoordList();
private:
	list<coord*> *snake_coord;
	int curLen = 0;
	void addPartition();
};



#endif