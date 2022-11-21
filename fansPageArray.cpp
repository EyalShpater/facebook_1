#include "fansPageArray.h"
#include "fansPage.h"

const int DEFAULT_PHYS_SIZE = 2;
const int DEFAULT_LOG_SIZE = 0;
const int NOT_FOUND = -1;
const int EQUAL = 0;

FansPageArray::FansPageArray()
{
    physSize = DEFAULT_PHYS_SIZE;
    logSize = DEFAULT_LOG_SIZE;
    theFansPageArray = new const FansPage* [physSize];
}

FansPageArray::~FansPageArray()
{
    delete[]theFansPageArray;
}

void FansPageArray::push(const FansPage& newFansPage)
{
    reserve();
    theFansPageArray[logSize] = &newFansPage;
    logSize++;
}

void FansPageArray::pop(const char* name)
{
    int index = findPage(name);

    if (index != NOT_FOUND)
        theFansPageArray[index] = theFansPageArray[logSize - 1];

    --logSize;
}

int FansPageArray::findPage(const char* name)
{
    int index = NOT_FOUND;

    for (int i = 0; i < logSize; i++)
        if (strcmp(theFansPageArray[i]->getName(), name) == EQUAL)
            index = i;

    return index;
}


void FansPageArray::reserve()
{
    if (logSize == physSize)
    {
        physSize *= 2;
        myRealoc(physSize);
    }
}

void FansPageArray::myRealoc(int newSize)
{
    const FansPage** temp = new const FansPage*[newSize];

    for (int i = 0; i < logSize; i++) // assumption: logSize < newSize
        temp[i] = theFansPageArray[i];

    delete[]theFansPageArray;

    theFansPageArray = temp;
}