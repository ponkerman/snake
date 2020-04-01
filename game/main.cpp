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
    
    field.output();
    
    field.update(RIGHT);
    
    cout << endl;

    field.output();

    return 0;
}