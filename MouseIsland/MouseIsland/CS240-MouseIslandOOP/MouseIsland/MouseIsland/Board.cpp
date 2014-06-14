#include "Board.h"

Board::Board(){}

Board::~Board(){}

void Board::readFile()
{
    string fileName, currentLine;
    ifstream reader;

    //keep asking for input while input is bad
    while(!reader)
    {
        //get the file name
        cout << "What is the file name of the Mouse Island game? (enter without extension)" << endl;
        cin >> fileName;

        fileName += ".txt";

        //open the file
        reader.open(fileName.c_str());

        //if input is bad, clear the cin
        if (!reader)
        {
            cout << "ERROR: USER CANNOT READ" << endl;
            cin.clear();
            cin.ignore (200, '\n');
            continue;
        }
    }

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
    while(!reader.eof())
    {
        int i = 0;

        for (int j = 0; j < width; j++) //count for the "rows"
        {
            mapArray[i][j] = atoi(currentLine.substr(j).c_str());
        }

        i++; //increment the "columns"
    }

    reader.close(); //close the file
}

void Board::writeFile()
{
    ofstream writer("MouseIslandOut.txt"); //open output file

    writer << "//Map name" << endl;
    writer << mapName << endl; //name
    writer << "//Times game ran" << endl;
    writer << games << endl; //times the game was ran
    writer << "//Seed of the game" << endl;
    writer << seed << endl; //times the game was ran
    writer << "//How did the game end?" << endl;
    writer << "Escapes: " << ends.at(0) << endl;
    writer << "Eaten: " << ends.at(1) << endl;
    writer << "Drowned: " << ends.at(2) << endl;
    writer << "Starved: " << ends.at(3) << endl;
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

void Board::RunTurn(); //run one turn of the game
int Board::CheckMouseCollision(); //return the number the mouse collides with
void Board::BuildMap(int mapArray[20][20]); //build the map array
void Board::getMove(int& xCoord, int& yCoord); //adjust x & y for a random move (up, down, left, right)
void Board::resetEVERYTHING(); //reset variables for new game

void Board::findNextLine(ifstream& file, string& currentLine)
{
    getline (file, currentLine);

    while (currentLine.substr(0,1) == "*" || currentLine.substr(0,1) == "/" || currentLine.substr(0,1) == "")
    {
        getline (file,currentLine);
    }
}
