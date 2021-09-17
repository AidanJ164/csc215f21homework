#include "..\\catch.hpp"
#include "trim.h"

TEST_CASE("cTrim - Testing C strings with no ws on either end")
{
    char theString[100] = "Catch with Sections!";
    char theAnswer[100] = "Catch with Sections!";
    CHECK(strcmp(theString, theAnswer) == 0);

    SECTION("Front - Just a phrase")
    {
        cTrim(theString, FRONT);
        CHECK(strcmp(theAnswer, theString) == 0);
    }

    SECTION("End - Just a phrase")
    {
        cTrim(theString, END);
        CHECK(strcmp(theAnswer, theString) == 0);
    }

    SECTION("BOTH - Just a phrase")
    {
        cTrim(theString, BOTH);
        CHECK(strcmp(theAnswer, theString) == 0);
    }
}

TEST_CASE("strim - Testing strings with no ws on either end")
{
    string theString = "Catch with Sections!";
    string theAnswer = "Catch with Sections!";
    REQUIRE(theString == theAnswer);

    SECTION("Front - Just a phrase")
    {
        sTrim(theString, FRONT);
        REQUIRE(theAnswer == theString);
    }

    SECTION("End - Just a phrase")
    {
        sTrim(theString, END);
        REQUIRE(theAnswer == theString);
    }

    SECTION("BOTH - Just a phrase")
    {
        sTrim(theString, BOTH);
        REQUIRE(theAnswer == theString);
    }
}

TEST_CASE("cTrim - Testing c strings with ws at the end")
{
    char theString[100] = "There is no ws.    ";
    char theAnswer[100] = "There is no ws.";

    SECTION("END - ws at end")
    {
        cTrim(theString, END);
        REQUIRE(strcmp(theString, theAnswer) == 0);
    }

    SECTION("FRONT - ws at end")
    {
        cTrim(theString, FRONT);
        REQUIRE(strcmp(theString, "There is no ws.    ") == 0);
    }

    SECTION("BOTH - ws at end")
    {
        cTrim(theString, BOTH);
        REQUIRE(strcmp(theString, theAnswer) == 0);
    }
}

TEST_CASE("cTrim - Testing c strings with ws at the start")
{
    char theString[100] = "            There should not be white space up front.";
    char theAnswer[100] = "There should not be white space up front.";

    SECTION("FRONT - ws up front")
    {
        cTrim(theString, FRONT);
        REQUIRE(strcmp(theString, theAnswer) == 0);
    }

    SECTION("END - ws up front")
    {
        cTrim(theString, END);
        REQUIRE(strcmp(theString, "            There should not be white space up front.") == 0);
    }

    SECTION("BOTH - ws up front")
    {
        cTrim(theString, BOTH);
        REQUIRE(strcmp(theString, theAnswer) == 0);
    }
}

TEST_CASE("cTrim - Testing c strings with ws at both ends")
{
    char theString[100] = "            There should not be white space anywhere.            ";
    char theAnswer[100] = "There should not be white space anywhere.";

    SECTION("BOTH - ws at both ends")
    {
        cTrim(theString, BOTH);
        REQUIRE(strcmp(theString, theAnswer) == 0);
    }

    SECTION("FRONT - ws at both ends")
    {
        cTrim(theString, FRONT);
        REQUIRE(strcmp(theString, "There should not be white space anywhere.            ") == 0);
    }

    SECTION("END - ws at both ends")
    {
        cTrim(theString, END);
        REQUIRE(strcmp(theString, "            There should not be white space anywhere.") == 0);
    }
}

TEST_CASE("cTrim - testing string with all whitespace")
{
    char theString[100] = "               ";
    char theAnswer[100] = "";

    SECTION("FRONT - all ws")
    {
        cTrim(theString, FRONT);
        REQUIRE(strcmp(theString, theAnswer) == 0);
    }

    SECTION("END - all ws")
    {
        cTrim(theString, END);
        REQUIRE(strcmp(theString, theAnswer) == 0);
    }

    SECTION("BOTH - all ws")
    {
        cTrim(theString, BOTH);
        REQUIRE(strcmp(theString, theAnswer) == 0);
    }
}