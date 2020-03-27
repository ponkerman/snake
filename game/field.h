#ifndef __FIELD_H__
#define __FIELD_H__

#include "constants.h"
#include "snake.h"

class Field
{
private:
    char screen[HEIGHT][WIDTH];
    Snake *snake;
public:
    Field();
    ~Field();
    void init(char fill_char = 'O');
    void output();
    void update();
};

#endif
