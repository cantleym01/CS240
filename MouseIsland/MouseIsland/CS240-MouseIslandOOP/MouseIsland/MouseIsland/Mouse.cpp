#include "Mouse.h"

Mouse::Mouse()
{
    escapes = 0;
    eaten = 0;
    starve = 0;
    drown = 0;
}

Mouse::~Mouse(){}

bool Mouse::doneWithMap(int Collision)
{
    if (turn == 100)
    {
        starve++;
        return true;
    }

    switch(Collision)
    {
    case 0: //mouse drowned
        drown++;
        return true;
    case 1: //open space, good move
        return false;
    case 3: //eaten by cat
        eaten++;
        return true;
    case 4: //mouse food
        return false;
    case 5: //mouse hole
        return false;
    case 6: //bridge
        escapes++;
        return true;
    default: //error
        return false; //if some error return false
    }
}

int getEaten()
{
    return eaten;
}

int getEscape()
{
    return escapes;
}

int getStarve()
{
    return starve;
}

int getDrown()
{
    return drown;
}
