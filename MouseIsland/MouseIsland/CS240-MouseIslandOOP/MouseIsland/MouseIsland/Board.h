#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

//Board is not just the Board, it also acts as the control for the program

using namespace std;

class Board
{
public:
    Board();
    ~Board();
    void readFile();
    void writeFile();
    void RunTurn(); //run one turn of the game
    int CheckMouseCollision(); //return the number the mouse collides with
    void BuildMap(int mapArray[20][20]); //build the map array
    void getMove(int& xCoord, int& yCoord); //adjust x & y for a random move (up, down, left, right)
    void resetEVERYTHING(); //reset variables for new game
protected:
    void findNextLine(ifstream& file, string& currentLine); //skip comments and get next good input
private:
    string mapName;
    vector <int> ends;
    int mapArray[20][20]; //the map
    int outMap[20][20]; //the output map
    int length, width; //length and width of the map
    int mouseHoles; //how many mouseHoles are there?
    int mouseFood; //how many mouseFood pieces are there?
    int games; //how many turns to run the game
    int seed; //the seed of the random
};

#endif
