#include "sortedSingle.h"

bool sortedSingle::insert(int item)
{
    node* temp = nullptr;
    node* curr = headptr;
    node* prev = headptr;

    temp = new (nothrow) node;
    if (temp == nullptr)
    {
        return false;
    }

    temp->theItem = item;

    if (headptr == nullptr)
    {
        headptr = temp;
        temp->next = nullptr;

        return true;
    }

    if (headptr->theItem > temp->theItem)
    {
        temp->next = headptr;
        headptr = temp;

        return true;
    }

    while ((curr != nullptr) && (curr->theItem <= temp->theItem))
    {
        prev = curr;
        curr = curr->next;
    }

    prev->next = temp;
    temp->next = curr;

    return true;
}

void sortedSingle::print(ostream& out, string seperator)
{
    node* temp = headptr;

    while (temp != nullptr)
    {
        out << temp->theItem;
        temp = temp->next;
        
        if (temp != nullptr)
        {
            out << seperator;
        }
    }
}