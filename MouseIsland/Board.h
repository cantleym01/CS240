#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

#include "Mouse.h"
#include "Cat.h"

//Board is not just the Board, it also acts as the control for the program

using namespace std;

class Board
{
public:
    Board();
    ~Board();
    void readFile();
    void writeFile(int seed);
    void RunGame(); //run the game
    int CheckMouseCollision(); //return the number the mouse collides with
    void getMove(int& x, int& y); //adjust x & y for a random move (up, down, left, right)
    void resetEVERYTHING(Mouse&, Cat&); //reset variables for new game
    void displayMap();
protected:
    void findNextLine(ifstream& file, string& currentLine); //skip comments and get next good input
private:
    string mapName, fileName;
    int ends[4];

    int mapArray[20][20]; //the map
    int outMap[20][20]; //the output map

    int length, width; //length and width of the map
    int games; //how many turns to run the game
    int seed; //the seed of the random

    bool fileNameGot; //has the filename already been entered?

    //"players"
    Mouse mouse;
    Cat cat;
};

#endif
