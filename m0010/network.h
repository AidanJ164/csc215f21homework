#ifndef _NETWORK_H_
#define _NETWORK_H_

enum networkType{INVALID,
                 CLASSA,
                 APRIVATE,
                 LOCALHOST,
                 CLASSB,
                 BPRIVATE,
                 CLASSC,
                 CPRIVATE,
                 CLASSD,
                 CLASSE };

typedef unsigned char octet;
typedef unsigned int ip;

ip compressOctets(octet oct1, octet oct2, octet oct3, octet oct4);
octet extractOctets(ip theIP, octet oct1, octet oct2, octet oct3, octet oct4);
networkType getNetworkType(ip theIP);

#endif