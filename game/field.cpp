#include "field.h"

Field::Field()
{
}
void Field::init(char fill_char)
{
    for(int i = 0; i < HEIGHT; i++)
        for(int j = 0; j < WIDTH; j++)
            screen[i][j] = fill_char;
    for(int i = 0; i < WIDTH; i++)
        screen[0][i] = '#';
    for(int i = 0; i < WIDTH; i++)
        screen[HEIGHT-1][i] = '#';
    for(int i = 0; i < HEIGHT; i++)
        screen[i][0] = '#';
    for(int i = 0; i < HEIGHT; i++)
        screen[i][WIDTH-1] = '#';
}

void Field::output(){
    
    for(int i = 0; i < HEIGHT; i++){
        for(int j = 0; j < WIDTH; j++){
            cout.width(3);
            std::cout << screen[i][j];
        }
        cout << endl;
    }
}

Field::~Field()
{
}