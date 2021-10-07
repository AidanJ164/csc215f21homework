#include "newton.h"

double newtonApprox(double x, function <double(double)> func,
                    function <double(double)> funcP, double epsilon)
{
    if ( fabs( func(x) ) < epsilon )
    {
        return x;
    }

    x = x - ( func( x ) / funcP( x ) );
    
    x = newtonApprox(x, func, funcP, epsilon);

    return x;
}