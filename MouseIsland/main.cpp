#include <iostream>
#include <stdlib.h>
#include <ctime>

#include "Board.h"

using namespace std;

int intCheck (string statement);

int main()
{
    int seed = 0;

    seed = intCheck ("Enter a seed for the map...");
    srand(seed);

    Board MouseIsland;

    MouseIsland.readFile();
    MouseIsland.RunGame();
    MouseIsland.writeFile(seed);
}

int intCheck (string statement)
{
    int input = 0;
    bool goodcin = false;
    //make sure the user is doing correct input
    while (goodcin != true)
    {
        cout << statement << endl;
        cin >> input;

        if (!cin)
        {
            cout << "ERROR: USER CANNOT READ" << endl;
            cin.clear();
            cin.ignore (200, '\n');
            continue;
            goodcin = false;
        }
        else
            goodcin = true;
    }
    //return good input
    return input;
}
