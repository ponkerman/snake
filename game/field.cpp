#include "field.h"
#include "constants.h"

Field::Field()
{
    snake = new Snake;
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
    myType a;
    snake->init();
    list<coord*>* snakeCoord = snake->getCoordList();
    for_each(snakeCoord->begin(), snakeCoord->end(), [&screen = screen, fill_char](coord* it){screen[it->x][it->y] = fill_char;});


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

void Field::update(){
    
}


Field::~Field()
{
}