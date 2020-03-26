#ifndef __FIELD_H__
#define __FIELD_H__

#define HEIGHT 18
#define WIDTH 18

#include <iostream>
#include <conio.h>

using namespace std;

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
