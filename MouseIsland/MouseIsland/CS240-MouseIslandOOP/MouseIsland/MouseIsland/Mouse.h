#ifndef MOUSE_H
#define MOUSE_H

class Mouse
{
public:
    Mouse();
    ~Mouse();
    bool doneWithMap(int Collision);//returns true if the game is done, false if not
                                    //called when mouse makes contact with something
    //get functions
    int getEaten();
    int getEscape();
    int getStarve();
    int getDrown();

    int x, y; //x and y coordinates
    int turn; //turn in the game
private:
    int escapes, eaten, starve, drown;

};

#endif
