#include "sortedSingle.h"

sortedSingle::sortedSingle()
{
    headptr = nullptr;
}

sortedSingle::~sortedSingle()
{
    node* temp;

    while (headptr != nullptr)
    {
        temp = headptr;
        headptr = headptr->next;
        delete temp;
    }
}

bool sortedSingle::empty()
{
    if (headptr == nullptr)
    {
        return true;
    }

    return false;
}

int sortedSingle::size()
{
    int count = 0;
    node* temp = headptr;

    while(temp != nullptr)
    {
        count++;
        temp = temp->next;
    }
    
    return count;
}

bool sortedSingle::find(int item)
{
    node* temp = headptr;

    while (temp != nullptr)
    {
        if (temp->theItem == item)
        {
            return true;
        }
        temp = temp->next;
    }

    return false;
}

int sortedSingle::retrievePosition(int item)
{
    node* temp = headptr;
    int index = 1;

    while (temp != nullptr)
    {
        if (temp->theItem == item)
        {
            return index;
        }
        index++;
        temp = temp->next;
    }

    return 0;
}