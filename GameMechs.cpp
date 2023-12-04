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
GameMechs::~GameMechs() {
    // Destructor implementation
    // Add code to release any allocated resources
}

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


void GameMechs::generateFood(objPosArrayList *blockOff) {
    srand(time(NULL));

    foodPos.x = (rand() % (boardSizeX-2))+1;
    foodPos.y = (rand() % (boardSizeY-2))+1;

    objPos tempPos;
    for (int i = 0; i < blockOff->getSize(); i++){
        blockOff ->getElement(tempPos, i);
        while(foodPos.isPosEqual(&tempPos)){
            foodPos.x = (rand() % (boardSizeX-2))+1;
            foodPos.y = (rand() % (boardSizeY-2))+1;
        }
    }
}



void GameMechs::getFoodPos(objPos &returnFood) {
    // Implementation of getFoodPos
    // Retrieve the food position and store it in returnPos
    returnFood.setObjPos(foodPos.x, foodPos.y, foodPos.symbol);
}
