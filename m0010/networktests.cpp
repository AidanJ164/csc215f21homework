#include "..\\catch.hpp"
#include "network.h"

TEST_CASE( "compressOctets - testing a class A ip address" )
{
    octet oct1 = 64,
          oct2 = 129,
          oct3 = 12,
          oct4 = 4;
    
    ip resultIP = compressOctets(oct1, oct2, oct3, oct4);

    REQUIRE(1082199044 == resultIP);
}

TEST_CASE("compressOctets - testing the in class example")
{
    octet oct1 = 151,
          oct2 = 159,
          oct3 = 15,
          oct4 = 20;

    ip resultIP = compressOctets(oct1, oct2, oct3, oct4);

    REQUIRE( 2543783700 == resultIP);
}

TEST_CASE("compressOctets - testing a class B ip address")
{
    octet oct1 = 187,
          oct2 = 2,
          oct3 = 206,
          oct4 = 97;

    ip resultIP = compressOctets(oct1, oct2, oct3, oct4);

    REQUIRE(3137523297 == resultIP);
}

TEST_CASE("compressOctets - testing a class C ip address")
{
    octet oct1 = 201,
          oct2 = 255,
          oct3 = 109,
          oct4 = 0;

    ip resultIP = compressOctets(oct1, oct2, oct3, oct4);

    REQUIRE( 3388960000 == resultIP);
}

TEST_CASE("compressOctets - testing a class D ip address")
{
    octet oct1 = 230,
          oct2 = 1,
          oct3 = 244,
          oct4 = 198;

    ip resultIP = compressOctets(oct1, oct2, oct3, oct4);

    REQUIRE(3858887878 == resultIP);
}

TEST_CASE("compressOctets - testing a class E ip address")
{
    octet oct1 = 255,
          oct2 = 255,
          oct3 = 255,
          oct4 = 255;

    ip resultIP = compressOctets(oct1, oct2, oct3, oct4);

    REQUIRE(4294967295 == resultIP);
}

