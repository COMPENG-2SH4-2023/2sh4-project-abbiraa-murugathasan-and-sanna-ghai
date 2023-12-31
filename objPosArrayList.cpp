#include "objPosArrayList.h"

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()
{
    aList = new objPos[ARRAY_MAX_CAP]; 
    sizeArray = ARRAY_MAX_CAP;
    sizeList = 0;
}

objPosArrayList::~objPosArrayList()
{
    delete[] aList; //square bracket needed
}

int objPosArrayList::getSize()
{
    return sizeList;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    // check if sizelist is equal to arraycapacity, if yest dont insert.

    if (sizeList == sizeArray) { //error check
        return;
    }

    for(int i = sizeList; i > 0; i--) 
    {
        aList[i].setObjPos(aList[i - 1]);
    }

    aList[0].setObjPos(thisPos);
    sizeList++;
}

void objPosArrayList::insertTail(objPos thisPos)
{
    if (sizeList == sizeArray) {
        return; // array is full, do not insert
    }

    aList[sizeList].setObjPos(thisPos);
    sizeList++;

}

void objPosArrayList::removeHead()
{
    if (sizeList > 0) {
        for (int i = 0; i < sizeList - 1; i++) {
            aList[i].setObjPos(aList[i + 1]);
        }
        sizeList--;
    }
    
}

void objPosArrayList::removeTail()
{
    if (sizeList > 0) {
        sizeList--;
    }

}

void objPosArrayList::getHeadElement(objPos &returnPos)
{
    returnPos.setObjPos(aList[0]);
}

void objPosArrayList::getTailElement(objPos &returnPos)
{
    returnPos.setObjPos(aList[sizeList - 1]);
}

void objPosArrayList::getElement(objPos &returnPos, int index)
{
    if (index >= 0 && index < sizeList) {
        returnPos.setObjPos(aList[index]);
    }

}