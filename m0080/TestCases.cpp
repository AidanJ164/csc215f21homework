#include "sortedSingle.h"
#include "..\catch.hpp"
#include <sstream>
#include <iostream>

using namespace std;

TEST_CASE("constructor")
{
    sortedSingle list;

    REQUIRE(list.empty() == true);
    REQUIRE(list.size() == 0);
}

TEST_CASE("empty")
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

TEST_CASE("size")
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

TEST_CASE("find")
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

TEST_CASE("retrievePosition")
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
