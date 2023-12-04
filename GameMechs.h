#ifndef GAMEMECHS_H
#define GAMEMECHS_H

#include <cstdlib>
#include <time.h>

#include "objPos.h"
#include "objPosArrayList.h"
//#include "Player.h"

using namespace std;

//class Player;

class GameMechs
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    private:
        char input;
        bool exitFlag;
        bool loseFlag;
        int score;
        int boardSizeX;
        int boardSizeY;
        
        objPos foodPos;
        
        

    public:
        GameMechs();
        GameMechs(int boardX, int boardY);
        ~GameMechs();
        
        bool getExitFlagStatus();
        void setExitTrue();

        bool getLoseFlagStatus();
        void setLoseFlag();

        int getScore();
        void incrementScore();

        char getInput();
        void setInput(char thisInput);
        void clearInput();

        int getBoardSizeX();
        int getBoardSizeY();

        void generateFood(objPos blockOff);
        //need to accept the player body array lidt
        // go through each aeeay list element to make sure they are all blocked from random food
        void getFoodPos(objPos &returnPos);
        
        
      


};

#endif