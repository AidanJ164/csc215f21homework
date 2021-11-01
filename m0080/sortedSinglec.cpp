#include "sortedSingle.h"

bool sortedSingle::remove(int item)
{
    node* curr = headptr;
    node* prev = headptr;

    if (empty())
    {
        return false;
    }

    if (headptr->theItem == item)
    {
        headptr = headptr->next;
        delete curr;
        return true;
    }

    while ((curr != nullptr) && (curr->theItem != item))
    {
        prev = curr;
        curr = curr->next;
    }

    if (curr == nullptr)
    {
        return false;
    }

    prev->next = curr->next;
    delete curr;

    return true;
}

void sortedSingle::clear()
{
    node* temp;

    while (headptr != nullptr)
    {
        temp = headptr;
        headptr = headptr->next;
        delete temp;
    }
}
