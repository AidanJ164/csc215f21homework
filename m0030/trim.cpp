#include "trim.h"

void cTrim(char *cString, trimType method)
{
    int i = 0;
    long long j;

    if (strcmp(cString, "") == 0)
    {
        return;
    }

    if ((method == FRONT) || (method == BOTH))
    {
        while ((isspace(cString[i]) != 0) && (i < strlen(cString)) )
        {
            i++;
        }
        strcpy(cString, &cString[i]);
    }

    if ((method == END) || (method == BOTH))
    {
        j = strlen(cString) - 1;

        while ((j >= 0) && (isspace(cString[j]) != 0))
        {
            j--;
        }
        cString[j + 1] = '\0';
    }
}


void sTrim(string& cplusString, trimType method)
{
    string::iterator it;

    if ( cplusString.empty() )
    {
        return;
    }
    
    if ((method == FRONT) || (method == BOTH))
    {
        it = cplusString.begin();

        while ((it != cplusString.end()) && (isspace(*it) != 0))
        {
            it++;
        }
        cplusString.erase(cplusString.begin(), it);
    }


    if ((method == END) || (method == BOTH))
    {
        it = cplusString.end();

        while (it != cplusString.begin())
        {
            it--;
            if (isspace(*it) != 0)
            {
                cplusString.erase(it);
            }
            else
            {
                return;
            }
        }
    }
}