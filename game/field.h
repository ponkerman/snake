#ifndef __FIELD_H__
#define __FIELD_H__

#include "constants.h"
#include "snake.h"

class Field
{
private:
    char screen[HEIGHT][WIDTH];
    Snake *snake;
    char fill_char;
public:
    Field();
    ~Field();
    void init(char fill_char = FIELD_CHAR);
    void output();
    void update(int);
};

#endif
