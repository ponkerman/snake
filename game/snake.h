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
	void init(int, int, char);
private:
	vector<pair<int, int>> coord;
};



#endif