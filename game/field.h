#ifndef __FIELD_H__
#define __FIELD_H__

#include "constants.h"

class Field
{
private:
    char screen[HEIGHT][WIDTH];
public:
    Field();
    ~Field();
    void init(char fill_char = 'O');
    void output();
};

#endif
