#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "GameMechs.h"
#include "Player.h"


using namespace std;

#define DELAY_CONST 100000


GameMechs* myGM;
Player* player;


objPos myPos;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(!myGM->getExitFlagStatus())  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();

    }

    CleanUp();
    return 0;

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();


    myGM  = new GameMechs(26,13);
    player = new Player(myGM);

    // think about when to generate food

    // think about whether you want to set up a debug key to call the food generation routine for verification

    // generateFood() requires player reference, need to provide it after player object is instantiated 

    //exitFlag =false;
    objPos tempPos{-1,-1,'o'};
    //player -> getPlayerPos(tempPos);
    myGM -> generateFood(tempPos);

    
}

void GetInput(void)
{
        // if (MacUILib_hasChar()) {
        //     char input = MacUILib_getChar();
        //     mainGameMechsRef ->setInput(input);}
        myGM->getInput();
    
   // char input = MacUILib_getChar();
    
}

void RunLogic(void)
{
   player ->updatePlayerDir();
   player ->movePlayer();

   myGM ->clearInput();
}

void DrawScreen(void)
{
    MacUILib_clearScreen();

    bool drawn; 

    objPosArrayList* playerBody = player->getPlayerPos();
    objPos tempBody;

    objPos tempFoodPos;
    myGM -> getFoodPos(tempFoodPos);

    for (int y = 0; y < myGM->getBoardSizeY(); ++y)
    {
        for (int x = 0; x < myGM ->getBoardSizeX(); ++x)
        {
            drawn = false;
            for(int z = 0; z < playerBody->getSize(); z++)
            {
                playerBody->getElement(tempBody,z);
                if(tempBody.x == x && tempBody.y == y)
                {
                    MacUILib_printf("%c", tempBody.symbol);
                    drawn = true;
                    break;
                }
            }

            if(drawn) 
            continue;//if player body drawn, don't draw anything below

            if (y == 0 || y == myGM->getBoardSizeY() - 1 || x == 0 || x == myGM->getBoardSizeX() - 1)
            {
                // Draw borders
                MacUILib_printf("%c", '#');
            }
           
            else if (x == tempFoodPos.x && y == tempFoodPos.y){
                MacUILib_printf("%c", tempFoodPos.symbol);
            }
            else
                MacUILib_printf("%c", ' ');
 
        }
        MacUILib_printf("\n");
     
    }
    //MacUILib_printf("Score: %d\n", player->getScore());
    objPos tempPos;
    playerBody->getHeadElement(tempBody);
    MacUILib_printf("Score: %d\n", myGM->getScore());
    
    MacUILib_printf("Food Pos: <%d, %d\n", tempFoodPos.x, tempFoodPos.y);

  
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
  
    MacUILib_uninit();

    //delete myGM;
    //delete player;
}
