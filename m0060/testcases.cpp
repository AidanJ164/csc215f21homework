#include "newton.h"
#include "..\catch.hpp"

double f(double x)
{
    return pow(x, 3) + 2;
}

double fP(double x)
{
    return 3 * pow(x, 2);
}

TEST_CASE("newtonApprox - x^3 + 2")
{
    double epsilon = .001;
    double n = 2;
    double ans;
    ans = newtonApprox(n, f, fP, epsilon);
        
    REQUIRE(fabs(f(ans)) <= epsilon);
}

double g(double x)
{
    return pow((x - 3), 3) + 2;
}

double gP(double x)
{
    return 3 * pow((x - 3), 2);
}

TEST_CASE("newtonApprox - (x - 3)^3 + 2")
{
    double epsilon = .001;
    double n = 2;
    double ans;
    ans = newtonApprox(n, g, gP, epsilon);

    REQUIRE(fabs(g(ans)) <= epsilon);
}

double h(double x)
{
    return pow( x, 2 ) - 5;
}

double hP(double x)
{
    return 2 * x;
}

TEST_CASE("newtonApprox - x^2 - 5")
{
    double epsilon = .0001;
    double n = 2.5;
    double ans;
    ans = newtonApprox(n, h, hP, epsilon);

    REQUIRE(fabs(h(ans)) <= epsilon);
}

double z(double x)
{
    return -pow((x + 3), 4) + 3;
}

double zP(double x)
{
    return -4 * pow((x + 3), 3);
}

TEST_CASE("newtonApprox - -(x + 3)^4 + 3")
{
    double epsilon = .001;
    double n = -4;
    double ans;
    ans = newtonApprox(n, z, zP, epsilon);

    REQUIRE(fabs(z(ans)) <= epsilon);
}

double a(double x)
{
    return pow((x - 16), 3) + 5;
}

double aP(double x)
{
    return 3 * pow((x - 16), 2);
}

TEST_CASE("newtonApprox - (4x-16)^3 + 5")
{
    double epsilon = .1;
    double n = 4;
    double ans;
    ans = newtonApprox(n, a, aP, epsilon);

    REQUIRE(fabs(a(ans)) <= epsilon);
}