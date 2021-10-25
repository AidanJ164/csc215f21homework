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
