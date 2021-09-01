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
    octet oct1 = 184,
          oct2 = 2,
          oct3 = 206,
          oct4 = 97;

    ip resultIP = compressOctets(oct1, oct2, oct3, oct4);

    REQUIRE(3087191649 == resultIP);
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

TEST_CASE("extractOctets - testing the in class example")
{
    ip theIP = compressOctets( 151,159,15,20 );
    octet oct1, oct2, oct3, oct4;

    extractOctets(theIP, oct1, oct2, oct3, oct4);
    CHECK(151 == oct1);
    CHECK(159 == oct2);
    CHECK(15 == oct3);
    CHECK(20 == oct4);
}

TEST_CASE("extractOctets - testing a class A ip")
{
    ip theIP = compressOctets(20, 248, 84, 119);
    octet oct1, oct2, oct3, oct4;

    extractOctets(theIP, oct1, oct2, oct3, oct4);
    CHECK(20 == oct1);
    CHECK(248 == oct2);
    CHECK(84 == oct3);
    CHECK(119 == oct4);
}

TEST_CASE("extractOctets - testing a class B ip")
{
    ip theIP = compressOctets(130, 9, 198, 203);
    octet oct1, oct2, oct3, oct4;

    extractOctets(theIP, oct1, oct2, oct3, oct4);
    CHECK(130 == oct1);
    CHECK(9 == oct2);
    CHECK(198 == oct3);
    CHECK(203 == oct4);
}

TEST_CASE("extractOctets - testing a class C ip")
{
    ip theIP = compressOctets(219, 53, 234, 1);
    octet oct1, oct2, oct3, oct4;

    extractOctets(theIP, oct1, oct2, oct3, oct4);
    CHECK(219 == oct1);
    CHECK(53 == oct2);
    CHECK(234 == oct3);
    CHECK(1 == oct4);
}

TEST_CASE("extractOctets - testing a class D ip")
{
    ip theIP = compressOctets(231, 23, 0, 254);
    octet oct1, oct2, oct3, oct4;

    extractOctets(theIP, oct1, oct2, oct3, oct4);
    CHECK(231 == oct1);
    CHECK(23 == oct2);
    CHECK(0 == oct3);
    CHECK(254 == oct4);
}

TEST_CASE("extractOctets - testing a class E ip")
{
    ip theIP = compressOctets(130, 9, 198, 203);
    octet oct1, oct2, oct3, oct4;

    extractOctets(theIP, oct1, oct2, oct3, oct4);
    CHECK(130 == oct1);
    CHECK(9 == oct2);
    CHECK(198 == oct3);
    CHECK(203 == oct4);
}

TEST_CASE("extractOctets - manually testing a class E ip")
{
    ip theIP = 2181678795;
    octet oct1, oct2, oct3, oct4;

    extractOctets(theIP, oct1, oct2, oct3, oct4);
    CHECK(130 == oct1);
    CHECK(9 == oct2);
    CHECK(198 == oct3);
    CHECK(203 == oct4);
}