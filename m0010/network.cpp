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
    
}


networkType getNetworkType(ip theIP)
{
    return INVALID;
}
