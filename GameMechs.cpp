#include "GameMechs.h"
#include "MacUILib.h"
GameMechs::GameMechs()
{
    input = 0;
    score = 0;
    exitFlag = false;
    loseFlag = false;
    boardSizeX = 20;
    boardSizeY = 10;
}

GameMechs::GameMechs(int boardX, int boardY)
{
    input = 0;
    score = 0;
    exitFlag = false;
    loseFlag = false;
    boardSizeX = boardX;    boardSizeY = boardY;

}// do you need a destructor?

bool GameMechs::getExitFlagStatus(){
    return exitFlag;
}
void GameMechs::setExitTrue(){
    exitFlag = true;
}
bool GameMechs::getLoseFlagStatus(){
    return loseFlag;
}
void GameMechs::setLoseFlag(){
    loseFlag = true;
}
int GameMechs::getScore(){
    return score;
}

void GameMechs::incrementScore()
{
    int n = 1;
    score += n;
}

char GameMechs::getInput()
{
    if(MacUILib_hasChar())
    {
        input = MacUILib_getChar();
    }

    return input;
}

int GameMechs::getBoardSizeX()
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY()
{
    return boardSizeY;
}


void GameMechs::setInput(char this_input)
{
    input = this_input;
}

void GameMechs::clearInput()
{
    input = '\0';
}


void GameMechs::generateFood(objPos blockOff) {
    
}



void GameMechs::getFoodPos(objPos &returnPos) {
    // Implementation of getFoodPos
    // Retrieve the food position and store it in returnPos
}
