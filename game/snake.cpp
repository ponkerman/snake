#include "snake.h"

Snake::Snake()
{
	snake_coord = new list<coord*>(START_LEN);
}

Snake::~Snake()
{
	delete[] snake_coord;
}


int Snake::init(int x, int y){
	
	if (x == -1) x = WIDTH/2;
	if (y == -1) y = HEIGHT/2;
	
	if (WIDTH - x < START_LEN || x < START_LEN ||
		HEIGHT - y < START_LEN || y < START_LEN){
		return -1;
	}
	snake_coord->push_back(new coord{x,y});
	for(int i = 1; i < START_LEN; i++){
		addPartition();
	}
	return 1;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////
void Snake::addPartition(){
bool flag;
snake_coord->push_back(new coord{-1,-1});
/*
x-1 |	y
x   |	y-1
x   |	y+1
x+1 |	y
*/

int X = (snake_coord->back()-1)->x;
int Y = (snake_coord->back()-1)->y;

--X;
Y;
flag = true;
if (X == 0 || Y == 0 || X == WIDTH || Y == HEIGHT) { 
	for_each(snake_coord->begin, snake_coord->end-1, [&flag, X, Y](coord* it){if (it->x == X && it->y == Y) flag = false;}); 
}
if(flag) {snake_coord->back()->x = X; snake_coord->back()->y = Y;} else {
	flag = true;
	++X;
	--Y;
	if (X == 0 || Y == 0 || X == WIDTH || Y == HEIGHT) { 
		for_each(snake_coord->begin, snake_coord->end-1, [&flag, X, Y](coord* it){if (it->x == X && it->y == Y) flag = false;}); 
	}
	if(flag) {snake_coord->back()->x = X; snake_coord->back()->y = Y;} else {
		flag = true;
		X;
		Y+=2;
		if (X == 0 || Y == 0 || X == WIDTH || Y == HEIGHT) { 
			for_each(snake_coord->begin, snake_coord->end-1, [&flag, X, Y](coord* it){if (it->x == X && it->y == Y) flag = false;}); 
		}
		if(flag) {snake_coord->back()->x = X; snake_coord->back()->y = Y;} else {
			flag = true;
			++X;
			--Y;
			if (X == 0 || Y == 0 || X == WIDTH || Y == HEIGHT) { 
				for_each(snake_coord->begin, snake_coord->end-1, [&flag, X, Y](coord* it){if (it->x == X && it->y == Y) flag = false;}); 
			}
			if(flag) {snake_coord->back()->x = X; snake_coord->back()->y = Y;}
		}
	}
}

if(snake_coord->back()->x == -1 || snake_coord->back()->y == -1) cerr << "error: unable to add new part!";
else curLen += 1;
}


/*
/////////////////////////////////////////////////////////////////////////////////////////////////////
int Snake::move(int dir){
	partition *tmp = new partition;
	tmp = tail;
	do{
		tmp->x = tmp->prev->x;
		tmp->y = tmp->prev->y;
		tmp = tmp->prev;
	} while (tmp != head);

	switch (dir){
		case UP:
			head->y += 1;
			break;
		case DOWN:
			head->y -= 1;
			break;
		case LEFT:
			head->x -= 1;
			break;
		case RIGHT:
			head->x += 1;
			break;
		default:
			return -1;
			break;
	}
	return 1;
}


*/
int Snake::getLen(){
	return curLen;
}

list<coord*>* Snake::getCoordList(){
	return snake_coord;
}