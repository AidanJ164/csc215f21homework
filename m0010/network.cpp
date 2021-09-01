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
    return INVALID;
}
