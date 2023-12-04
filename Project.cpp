#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "GameMechs.h"
#include "Player.h"

using namespace std;

// Constants
#define DELAY_CONST 100000

// Global objects
GameMechs* myGM;
Player* player;

objPos myPos;

// Function declarations
void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);

int main(void)
{
    Initialize();

    while (!myGM->getExitFlagStatus())
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();
    return 0;
}

// Initialize game objects and set up initial conditions.
void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    myGM = new GameMechs(26, 13);
    player = new Player(myGM);

    // Generate initial food
    objPosArrayList tempPosList;
    myGM->generateFood(&tempPosList);
}

// Get user input for the game.
void GetInput(void)
{
    myGM->getInput();
}

// Execute game logic, including player movement, collision checks, and score updates.
void RunLogic(void)
{
    objPos tempFoodPos;
    objPos tempBody;
    objPosArrayList* playerBody = player->getPlayerPos();
    myGM->getFoodPos(tempFoodPos);

    player->updatePlayerDir();
    player->movePlayer();

    playerBody->getHeadElement(tempBody);
    if (tempBody.isPosEqual(&tempFoodPos))
    {
        myGM->incrementScore();
        playerBody->insertHead(tempFoodPos);  // Insert the food position as the new head
        myGM->generateFood(playerBody);
    }

    if (player->getPlayerPos()->getSize() > 1)
    {
        myGM->setLoseFlag();
    }

    myGM->clearInput();
}

// Draw the game screen, including borders, player, and food positions.
void DrawScreen(void)
{
    MacUILib_clearScreen();

    bool drawn;
    objPos tempBody;
    objPos tempFoodPos;

    objPosArrayList* playerBody = player->getPlayerPos();

    myGM->getFoodPos(tempFoodPos);
    MacUILib_printf("--------Snake Game--------\n");

    for (int y = 0; y < myGM->getBoardSizeY(); ++y)
    {
        for (int x = 0; x < myGM->getBoardSizeX(); ++x)
        {
            drawn = false;
            for (int z = 0; z < playerBody->getSize(); z++)
            {
                playerBody->getElement(tempBody, z);
                if (x == tempBody.x && y == tempBody.y)
                {
                    MacUILib_printf("%c", tempBody.symbol);
                    drawn = true;
                    break;
                }
            }

            if (drawn) continue; // If player body is drawn, don't draw anything below

            if (y == 0 || y == myGM->getBoardSizeY() - 1 || x == 0 || x == myGM->getBoardSizeX() - 1)
            {
                // Draw borders
                MacUILib_printf("%c", '#');
            }

            else if (x == tempFoodPos.x && y == tempFoodPos.y)
            {
                MacUILib_printf("%c", tempFoodPos.symbol);
            }
            else
                MacUILib_printf("%c", ' ');
        }
        MacUILib_printf("\n");
    }

    MacUILib_printf("Press WASD to start or press SPACE to exit\n");
    MacUILib_printf("Score: %d\n", myGM->getScore());

    if (myGM->getExitFlagStatus())
    {
        MacUILib_printf("\nEnd Game.");
    }

    if (myGM->getLoseFlagStatus())
    {
        MacUILib_printf("\nYou Lost.");
        myGM->setExitTrue();
    }

    MacUILib_printf("Food Pos: <%d, %d>\n", tempFoodPos.x, tempFoodPos.y);
}

// Introduce a delay to control the game loop speed.
void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}

// Clean up and release allocated memory before exiting the program.
void CleanUp(void)
{
    MacUILib_clearScreen();
    MacUILib_uninit();

    delete myGM;
    delete player;
}
