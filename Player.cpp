#include "Player.h"
#include "GameMechs.h"


Player::Player(GameMechs* thisGMRef)
//: playerPos(5, 5, '@'), myDir(STOP), mainGameMechsRef(thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    objPos tempPos;
    tempPos.setObjPos(mainGameMechsRef->getBoardSizeX()/2, mainGameMechsRef->getBoardSizeY()/2,'@');

    playerPosList = new objPosArrayList();
    playerPosList->insertHead(tempPos);
    playerPosList->insertHead(tempPos);
    playerPosList->insertHead(tempPos);
    playerPosList->insertHead(tempPos);
    playerPosList->insertHead(tempPos);
    

}
Player::~Player()
{
    // delete any heap members here
    delete playerPosList;
}

//void objPosArrayList* 
objPosArrayList* Player::getPlayerPos()
{
     return playerPosList;
}

void Player::updatePlayerDir()
{
    char input = mainGameMechsRef->getInput();
   
    switch (input)
    {
         case ' ':  // exit
                exitFlag = 1;
                break;
    case 'w':
        if (myDir != UP && myDir != DOWN)
            myDir = UP;
        break;
    case 's':
        if (myDir != UP && myDir != DOWN)
            myDir = DOWN;
        break;
    case 'a':
        if (myDir != LEFT && myDir != RIGHT)
            myDir = LEFT;
        break;
    case 'd':
        if (myDir != LEFT && myDir != RIGHT)
            myDir = RIGHT;
        break;
    default:
        // Handle other cases or do nothing for unrecognized input
        break;
    }


    // Clear the input buffer
    mainGameMechsRef->clearInput();
    // PPA3 input processing logic        
}

void Player::movePlayer()
{
    objPos currentHead;
    playerPosList->getHeadElement(currentHead);

    switch (myDir)
    {
    case UP:
        currentHead.y--;
        if(currentHead.y <= 0)
        currentHead.y = mainGameMechsRef -> getBoardSizeY() -2;
        break;
    case DOWN:
        currentHead.y++;
        if(currentHead.y >= mainGameMechsRef->getBoardSizeY())
        currentHead.y = 1;
        break;
    case LEFT:
        currentHead.x--;
        if(currentHead.x <= 0)
        currentHead.x = mainGameMechsRef->getBoardSizeX() -2;
        break;
    case RIGHT:
        currentHead.x++;
        if(currentHead.x >= mainGameMechsRef->getBoardSizeX())
        currentHead.x = 1;
        break;

    case STOP:
    default:
        // Handle other cases or do nothing for unrecognized direction
        break;
    }

    playerPosList->insertHead(currentHead);

    playerPosList->removeTail();

    // objPos foodPos;
    // mainGameMechsRef->getFoodPos(foodPos);

    // if (playerPos.x == foodPos.x && playerPos.y == foodPos.y) {
    //     // Increase score and respawn food
    //     score++;
    //     mainGameMechsRef->respawnFood();
    // }
    // PPA3 Finite State Machine logic
}



