#include <iostream>
#include "Food.h"
#include <cstdlib>
#include <ctime>

Food::Food(GameMechs* thisGMRef)
{
    srand(time(nullptr));
    int initialX = thisGMRef->getBoardSizeX()/2;
    int initialY = thisGMRef->getBoardSizeY()/2;
    foodPos.setObjPos(initialX, initialY, 'o');
}

Food::~Food()
{
    void Food::generateFood(objPosArrayList* playerPosList)
    {
        srand(time(nullptr));
        bool playerOverlap;
        do{
            foodPos.x = (rand() % 20) + 1;
            foodPos.y = (rand() % 10) + 1;

            playerOverlap = false;
            objPos playerPos;
            for(int i = 0; i < playerPosList->getSize(); ++i)
            {
                playerPosList->getElement(playerPos, i);
                if(foodPos.isPosEqual(&playerPos))
                {
                    playerOverlap = true;
                    break;
                }
            }
        }while(playerOverlap);
        foodPos.symbol = 'o';
    }
}

void Food::getFoodPos(objPos &returnPos)
{
    foodPos.x = rand() % getBoardSizeX();
    foodPos.y = rand() % getBoardSizeY();
    foodPos.symbol = 'o';
    //returnPos = foodPos;
}