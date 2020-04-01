#include <iostream>
#include <conio.h>

#include "field.h"
#include "snake.h"
#include "bonus.h"
#include "constants.h"

using namespace std;

int main(int argc, char *argv[])
{
    Field field;
 
    field.init();
    int i = clock()/CLK_TCK;
    while(60){               //кол-во циклов в секунде
        if ((clock()/CLK_TCK)%1==0){
            if(i!=(clock()/CLK_TCK)){
                ////////////////////////////////////////////////
                system("cls");
                field.output();
                if(kbhit()) // слушатель нажатия на клаву
                {
                    switch(getch()) // ждёт нажатия на клаву без Enter после этого
                        {
                            case 72: //вверх
                                field.update(UP);
                                break;
                            case 80: //вниз
                                field.update(DOWN);
                                break;
                            case 75: //влево 
                                field.update(LEFT);
                                break;
                            case 77: //вправо
                                field.update(RIGHT);
                                break;
                            case 27:
                                return 0;
                        }
                }
                ////////////////////////////////////////////////
                i = clock()/CLK_TCK;
            }
        }
    }

    
    return 0;
}