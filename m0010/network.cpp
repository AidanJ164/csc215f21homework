#include "network.h"

ip compressOctets(octet oct1, octet oct2, octet oct3, octet oct4)
{
    ip theIP = 0;

    theIP |= oct1;
    theIP <<= 8;
    theIP |= oct2;
    theIP <<= 8;
    theIP |= oct3;
    theIP <<= 8;
    theIP |= oct4;

    return theIP;
}


void extractOctets(ip theIP, octet& oct1, octet& oct2, octet& oct3, octet& oct4)
{
    oct4 = theIP & 255;
    theIP >>= 8;
    oct3 = theIP & 255;
    theIP >>= 8;
    oct2 = theIP & 255;
    theIP >>= 8;
    oct1 = theIP & 255;
}


networkType getNetworkType(ip theIP)
{
    networkType netType = INVALID;
    octet oct1, oct2, oct3, oct4;

    extractOctets(theIP, oct1, oct2, oct3, oct4);

    if (oct1 == 0)
    {
        netType = INVALID;
    }
    else if (oct1 <= 127)
    {
        netType = CLASSA;
        if (oct1 == 10)
        {
            netType = APRIVATE;
        }
        if (oct1 == 127)
        {
            netType = LOCALHOST;
        }
    }
    else if (oct1 <= 191)
    {
        netType = CLASSB;
        if ((oct1 == 172) && (oct2 >= 16) && (oct2 <= 31))
        {
            netType = BPRIVATE;
        }
    }
    else if (oct1 <= 223)
    {
        netType = CLASSC;
        if ((oct1 == 192) && (oct2 == 168))
        {
            netType = CPRIVATE;
        }
    }
    else if (oct1 <= 239)
    {
        netType = CLASSD;
    }
    else if (oct1 <= 255)
    {
        netType = CLASSE;
    }
    return netType;
}
