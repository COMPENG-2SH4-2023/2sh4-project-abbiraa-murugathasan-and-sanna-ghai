#ifndef FOOD_H
#define FOOD_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"

class Food //initialize class
{
private:    
     objPos foodPos; 
public:     
    Food(GameMechs* thisGMRef);   
    ~Food();     
    void generateFood(objPosArrayList* playerPosList);     
    void getFoodPos(objPos &returnPos); 
}; 

#endif // FOOD_H
