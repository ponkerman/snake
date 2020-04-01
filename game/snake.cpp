#include "snake.h"

Snake::Snake()
{
	snake_coord = new vector<coord>;
}

Snake::~Snake()
{
	delete[] snake_coord;
}


int Snake::init(int x, int y){
	snake_coord->clear();
	//snake_coord->resize(START_LEN);

	if (x == -1) x = WIDTH/2;
	if (y == -1) y = HEIGHT/2;
	
	if (WIDTH - x < START_LEN || x < START_LEN ||
		HEIGHT - y < START_LEN || y < START_LEN){
		return -1;
	}

	snake_coord->push_back(coord(x,y));
	
	for(int i = 1; i < START_LEN; i++){
		addPartition();
	}

	return 1;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
void Snake::addPartition(){

int X = snake_coord->back().x; 
int Y = snake_coord->back().y; 
snake_coord->push_back(coord(-1, -1));

/*
x-1 |	y
x   |	y-1
x   |	y+1
x+1 |	y
*/
int aaaa = snake_coord->capacity();

--X;    Y;
if(check_coord(X, Y)) {snake_coord->back().x = X; snake_coord->back().y = Y; return;}
++X;    --Y;
if(check_coord(X, Y)) {snake_coord->back().x = X; snake_coord->back().y = Y;  return;}
X;      Y+=2;
if(check_coord(X, Y)) {snake_coord->back().x = X; snake_coord->back().y = Y; return;}
++X;    --Y;
if(check_coord(X, Y)) {snake_coord->back().x = X; snake_coord->back().y = Y; return;}

cerr << "error: unable to add new part!\n";

}



/////////////////////////////////////////////////////////////////////////////////////////////////////
int Snake::move(int dir){
	coord prev = *(snake_coord->begin());
	for_each(std::next(snake_coord->begin()), snake_coord->end(), [&prev](coord it){
		it.x = prev.x;
		it.y = prev.y;
		prev = it;
	});

	switch(dir){
		case UP:
			//head.y += 1;
			//snake_coord->at(0).y += 1;
			snake_coord->at(0).x -= 1;
			break;
		case DOWN:
			//head.y -= 1;
			snake_coord->at(0).x += 1;
			break;
		case LEFT:
			//head.x -= 1;
			snake_coord->at(0).y -= 1;
			break;
		case RIGHT:
			//head.x += 1;
			snake_coord->at(0).y += 1;
			break;
		default:
			return -1;
			break;
	}
	return 1;
}



int Snake::getLen(){
	return snake_coord->capacity();
}

vector<coord> Snake::getCoordList(){
	return *snake_coord;
}

bool Snake::check_coord(int x, int y){
	bool flag = true;
	for_each(snake_coord->begin(), snake_coord->end(), [x,y, &flag](coord it){ if (it.x == x && it.y == y) flag = false;});
	if (x == 0 || y == 0 || x == WIDTH || y == HEIGHT) return false;
	if(!flag) return false;
	return true;
}