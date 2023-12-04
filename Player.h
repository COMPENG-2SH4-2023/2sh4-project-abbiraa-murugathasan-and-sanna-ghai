#ifndef PLAYER_H
#define PLAYER_H


#include "objPos.h"
#include "objPosArrayList.h"

class GameMechs;

enum Dir { UP, DOWN, LEFT, RIGHT, STOP };

class Player {
    public:
        //enum Dir {UP, DOWN, LEFT, RIGHT, STOP};  // This is the direction state

        Player(GameMechs* thisGMRef);
        ~Player();

        objPosArrayList* getPlayerPos(); // Upgrade this in iteration 3.
        void updatePlayerDir();
        void movePlayer();
        //needs more action here, after moving the player 
        int getSnakeLength() const;
        


    private:
        objPosArrayList *playerPosList;   // Upgrade this in iteration 3.       
        enum Dir myDir;
        bool exitFlag;

        // Need a reference to the Main Game Mechanisms
        GameMechs* mainGameMechsRef;
        
};

#endif