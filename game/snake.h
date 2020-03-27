#ifndef __SNAKE_H__
#define __SNAKE_H__

#include "constants.h"

class Snake 
{
public:
	Snake();
	~Snake();
	int init(int, int);
	void addPartition();
	int move(int);
private:
	struct partition{
		int x;
		int y;
		partition* next;
		partition* prev;
	};
	partition* head = nullptr;
	partition* tail = nullptr;
	int curLen = 0;

	int cellCheck(int x, int y){
		if (x == 0 || y == 0 || x == WIDTH || y == HEIGHT)
			return -1;
		partition* curPart = head;
		for(int i = 0; i < curLen; i++){
			if (curPart->x == x && curPart->y == y)
				return -1;
			curPart = curPart->next;
		}
		return 1;
	}
};



#endif