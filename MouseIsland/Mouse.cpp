#include "Mouse.h"

Mouse::Mouse()
{
    escapes = 0;
    eaten = 0;
    starve = 0;
    drown = 0;

    onTopOf = 1;
}

Mouse::~Mouse(){}

bool Mouse::doneWithMap(int Collision, bool& catAndHole)
{
    turn++;

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
        if (!catAndHole)
        {
            eaten++;
            return true;
        }
        else
        {
            catAndHole = false;
            return false;
        }
    case 4: //mouse food
        turn = 0;
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

int Mouse::getEaten()
{
    return eaten;
}

int Mouse::getEscape()
{
    return escapes;
}

int Mouse::getStarve()
{
    return starve;
}

int Mouse::getDrown()
{
    return drown;
}
