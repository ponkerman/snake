#include "snake.h"

Snake::Snake()
{
	
}

Snake::~Snake()
{
    while(head != tail){
		auto tmp = tail;
		delete tail;
		tail = tmp->prev;
	}
	delete head;
}


int Snake::init(int x = -1, int y = -1){
	if (x == -1) x = WIDTH/2;
	if (y == -1) y = HEIGHT/2;
	
	if (WIDTH - x < START_LEN || x < START_LEN ||
		HEIGHT - y < START_LEN || y < START_LEN){
		return -1;
	}

	partition *node = new partition;
	head = node;
	tail = node;
	node->next=node; 
	node->prev=node;
	curLen = 1;

	node->x = x;
	node->y = y;

	return 1;
}

void Snake::addPartition(){
bool flag = 0;

//new node
partition *tmp = new partition;

//fill data
for(int xx = -1; xx < 2; xx += 2){
	if (flag) break;
	for (int yy = -1; yy < 2; yy += 2){
		if (cellCheck(tmp->prev->x + xx, tmp->prev->y + yy) == 1){
			tmp->x = tmp->prev->x + xx;
			tmp->y = tmp->prev->y + yy;
			flag = 1;
			break;
		} 
	}
}

//new node init
tail = tmp;
tmp->prev->next = tmp;

curLen += 1;
}