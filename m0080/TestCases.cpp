#include "sortedSingle.h"
#include "..\catch.hpp"
#include <sstream>
#include <iostream>

using namespace std;

TEST_CASE("sortedSingle - constructor")
{
    sortedSingle list;

    REQUIRE(list.empty() == true);
    REQUIRE(list.size() == 0);
}

TEST_CASE("sortedSingle - empty")
{
    sortedSingle list;

    SECTION("empty")
    {
        REQUIRE(list.empty() == true);
    }

    SECTION("not empty")
    {
        list.insert(4);
        list.insert(2);

        REQUIRE(list.empty() == false);
    }
}

TEST_CASE("sortedSingle - size")
{
    sortedSingle list;

    SECTION("empty")
    {
        CHECK(list.empty() == true);
        REQUIRE(list.size() == 0);
    }
    SECTION("1 item")
    {
        list.insert(4);

        REQUIRE(list.size() == 1);
    }
    SECTION("4 items")
    {
        list.insert(8);
        list.insert(3);
        list.insert(9);
        list.insert(1);

        REQUIRE(list.size() == 4);
    }
}

TEST_CASE("sortedSingle - find")
{
    sortedSingle list;
    
    SECTION("empty list")
    {
        CHECK(list.empty() == true);
        REQUIRE(list.find(4) == false);
    }

    list.insert(5);
    SECTION("1 item in list")
    {
        CHECK(list.size() == 1);
        REQUIRE(list.find(5) == true);
        REQUIRE(list.find(2) == false);
    }

    list.insert(4);
    list.insert(8);
    list.insert(1);

    SECTION("first")
    {
        REQUIRE(list.find(1) == true);
    }

    SECTION("middle")
    {
        REQUIRE(list.find(5) == true);
        REQUIRE(list.find(4) == true);
    }

    SECTION("end")
    {
        REQUIRE(list.find(8) == true);
    }

    SECTION("not in list")
    {
        REQUIRE(list.find(6) == false);
    }
}

TEST_CASE("sortedSingle - retrievePosition")
{
    sortedSingle list;

    SECTION("empty")
    {
        CHECK(list.empty() == true);
        REQUIRE(list.retrievePosition(4) == 0);
    }

    list.insert(4);

    SECTION("one item in list")
    {
        CHECK(list.size() == 1);
        REQUIRE(list.retrievePosition(4) == 1);
        REQUIRE(list.retrievePosition(5) == 0);
    }

    list.insert(5);
    list.insert(1);
    list.insert(11);

    SECTION("first")
    {
        CHECK(list.size() == 4);
        REQUIRE(list.retrievePosition(1) == 1);
    }

    SECTION("middle")
    {
        REQUIRE(list.retrievePosition(4) == 2);
        REQUIRE(list.retrievePosition(5) == 3);
    }

    SECTION("end")
    {
        REQUIRE(list.retrievePosition(11) == 4);
    }

    SECTION("not in list")
    {
        REQUIRE(list.retrievePosition(8) == 0);
        REQUIRE(list.retrievePosition(-4) == 0);
    }
}

TEST_CASE("sortedSingle - insert")
{
    sortedSingle list;
    ostringstream sout;

    SECTION("empty")
    {
        CHECK(list.insert(4));
        list.print(sout);
        REQUIRE(sout.str() == "4");
    }

    SECTION("front")
    {
        list.insert(5);
        CHECK(list.insert(4));

        list.print(sout);
        REQUIRE(sout.str() == "4, 5");
    }

    SECTION("middle")
    {
        list.insert(6);
        list.insert(5);
        list.insert(3);
        list.insert(2);
        CHECK(list.insert(4));

        list.print(sout);
        REQUIRE(sout.str() == "2, 3, 4, 5, 6");
    }

    SECTION("end")
    {
        list.insert(6);
        list.insert(5);
        list.insert(3);
        list.insert(2);
        list.insert(4);
        CHECK(list.insert(8));
        CHECK(list.insert(11));

        list.print(sout);
        REQUIRE(sout.str() == "2, 3, 4, 5, 6, 8, 11");
    }
}

TEST_CASE("sortedSingle - print")
{
    sortedSingle list;
    ostringstream sout;

    SECTION("empty")
    {
        list.print(sout);
        REQUIRE(sout.str() == "");
    }

    SECTION("one item")
    {
        list.insert(5);
        list.print(sout);
        REQUIRE(sout.str() == "5");
    }

    SECTION("two items")
    {
        list.insert(5);
        list.insert(10);

        list.print(sout);
        REQUIRE(sout.str() == "5, 10");
    }

    SECTION("five items")
    {
        list.insert(3);
        list.insert(6);
        list.insert(9);
        list.insert(12);
        list.insert(15);

        list.print(sout);
        REQUIRE(sout.str() == "3, 6, 9, 12, 15");
    }

    SECTION("different seperator")
    {
        list.insert(3);
        list.insert(6);
        list.insert(9);
        list.insert(12);
        list.insert(15);

        list.print(sout, "-");
        REQUIRE(sout.str() == "3-6-9-12-15");
    }
}