#ifndef PLAYER_H
#define PLAYER_H

#include "objPos.h"
#include "objPosArrayList.h"

// Forward declaration of GameMechs class
class GameMechs;

class Player {
public:
    // Enumeration for direction state
    enum Dir { UP, DOWN, LEFT, RIGHT, STOP };  

    Player(GameMechs* thisGMRef);
    ~Player();

    objPosArrayList* getPlayerPos();
    void updatePlayerDir();
    void movePlayer();
    int getSnakeLength() const;
    bool Collision();

private:
    objPosArrayList* playerPosList;
    enum Dir myDir;
    bool exitFlag;
    GameMechs* mainGameMechsRef;
};

#endif
