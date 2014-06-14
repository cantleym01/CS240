#include "Board.h"

Board::Board()
{
    fileNameGot = false;
}

Board::~Board(){}

void Board::readFile()
{
    string currentLine;
    ifstream reader;

    //keep asking for input while input is bad
    if (!fileNameGot)
    {
        bool goodcin = false;
        //make sure the user is doing correct input
        while (goodcin != true)
        {
            cout << "What is the file name of the Mouse Island game? (enter without extension)" << endl;
            cin >> fileName;

            fileName += ".txt";

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

        //initialize the outmap
        for (int i = 0; i < length; i++)
        {
            for (int j = 0; j < width; j++)
            {
               outMap[i][j] = 0;
            }
        }
    }

    reader.open(fileName.c_str());

    fileNameGot = true;

    findNextLine(reader, currentLine); //get next line of valid input

    mapName = currentLine; //map name is first input

    findNextLine(reader, currentLine); //get next line of valid input

    games = atoi(currentLine.c_str());

    findNextLine(reader, currentLine); //get next line of valid input

    length = atoi(currentLine.c_str());

    findNextLine(reader, currentLine); //get next line of valid input

    width = atoi(currentLine.c_str());

    findNextLine(reader, currentLine); //get next line of valid input

    //now at the first line of the map
    //build map until done
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < width; j++)
        {
            mapArray[i][j] = atoi(currentLine.substr(j, 1).c_str());

            //if mouse
            if (mapArray[i][j] == 2)
            {
                mouse.x = j;
                mouse.y = i;
            }

            //if cat
            if (mapArray[i][j] == 3)
            {
                cat.x = j;
                cat.y = i;
            }
        }
        findNextLine(reader, currentLine);
    }

    //now make the bridges a 6 for easy stuff
    for (int i = 0; i < length; i++) //row
    {
        for (int j = 0; j < width; j++) //column
        {
            if (mapArray[i][j] == 1)
            {
                bool p1 = (mapArray[i - 1][j] == 0); //left
                bool p2 = (mapArray[i + 1][j] == 0); //right
                bool p3 = (mapArray[i][j - 1] == 0); //up
                bool p4 = (mapArray[i][j + 1] == 0); //down

                //side bridges
                if (p1 && p2)
                {
                    mapArray[i][j] = 6;
                }
                //up/down bridges
                if (p3 && p4)
                {
                    mapArray[i][j] = 6;
                }
            }
        }
    }
    reader.close(); //close the file
}

void Board::writeFile(int seed)
{
    ofstream writer("MouseIslandOut.txt"); //open output file

    writer << "//Map name" << endl;
    writer << mapName << endl; //name

    writer << "//Times game ran" << endl;
    writer << games << endl; //times the game was ran

    writer << "//Seed of the game" << endl;
    writer << seed << endl; //times the game was ran

    writer << "//How did the game end?" << endl;
    writer << "Escapes: " << ends[0] << endl;
    writer << "Eaten: " << ends[1] << endl;
    writer << "Drowned: " << ends[2] << endl;
    writer << "Starved: " << ends[3] << endl;

    writer << "//Map of activity for the mouse" << endl;
    for (int i = 0; i < length; i++)
    {
        writer << endl;
        for (int j = 0; j < width; j++)
        {
            writer << outMap[i][j] << " ";
        }
    }
    writer.close(); //close the output file
}

void Board::RunGame() //run one run of the game, will return true when done
{
    bool catIgnore = false; //will cat ignore the mouse?
    bool catDone = false; //will the cat just leave?
    int oldX, oldY;

    //run the game however many times
    for (int runTimes = 0; runTimes < games; runTimes++)
    {
        //run this map until the mouse is done
        while (!mouse.doneWithMap(mouse.onTopOf, catIgnore))
        {
            //mouse turn
            oldX = mouse.x;
            oldY = mouse.y;
            getMove(mouse.x, mouse.y); //move the mouse to new coordinates

            mapArray[oldY][oldX] = mouse.onTopOf; //old position is what mouse was ontopof
            mouse.onTopOf = mapArray[mouse.y][mouse.x]; //ontopof is what mouse is moving onto
            mapArray[mouse.y][mouse.x] = 2; //move the mouse

            outMap[mouse.y][mouse.x]++; //increase the frequency on the outMap

            switch(mouse.onTopOf)
            {
            case 4:
                mouse.onTopOf = 1;
                break;
            case 5:
                catIgnore = true;
                break;
            }

            //cat turn
            if (!catDone)
            {
                oldX = cat.x;
                oldY = cat.y;
                getMove(cat.x, cat.y); //move the cat to new coordinates

                mapArray[oldY][oldX] = cat.onTopOf; //old position is what cat was ontopof
                cat.onTopOf = mapArray[cat.y][cat.x]; //ontopof is what cat is moving onto
                mapArray[cat.y][cat.x] = 3; //move the cat

                switch(cat.onTopOf)
                {
                case 0: //water, so cat drowns >:D
                    mapArray[cat.y][cat.x] = 0;
                    catDone = true;
                    break;
                case 6: //go away since all is good
                    mapArray[cat.y][cat.x] = 6;
                    catDone = true;
                    break;
                }
            }
            displayMap();
        }
        resetEVERYTHING(mouse, cat);
        catDone = false;
    }
    //ends
    ends[0] = mouse.getEscape();
    ends[1] = mouse.getEaten();
    ends[2] = mouse.getDrown();
    ends[3] = mouse.getStarve();
}

void Board::getMove(int& x, int& y) //adjust x & y for a random move (up, down, left, right)
{
    int moveChoice = rand() % 4; //0-3

    switch(moveChoice)
    {
    case 0: //up
        y--;
        break;
    case 1: //right
        x++;
        break;
    case 2: //down
        y++;
        break;
    case 3: //left
        x--;
        break;
    }
}

void Board::resetEVERYTHING(Mouse& mouse, Cat& cat) //reset variables for new game
{
    readFile();
    mouse.onTopOf = 1;
    cat.onTopOf = 1;

}

void Board::displayMap()
{
    //display the map to the command promt
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < width; j++)
        {
            cout << mapArray[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "----------------------------------------" << endl;
    cout << endl;

    cin.ignore();
}

void Board::findNextLine(ifstream& file, string& currentLine)
{
    getline (file, currentLine);

    while (currentLine.substr(0,1) == "*" || currentLine.substr(0,1) == "/" || currentLine.substr(0,1) == "")
    {
        getline (file,currentLine);
    }
}
