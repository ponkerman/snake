#ifndef __SNAKE_H__
#define __SNAKE_H__

#define START_LEN 4

#include <vector>
#include <utility>

using namespace std;

class Snake
{
public:
	Snake();
	~Snake();
	int init(int, int, int, int);
private:
	vector<pair<int, int>> coord;
};



#endif