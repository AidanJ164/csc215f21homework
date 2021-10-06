#include "newton.h"

double newtonApprox(double start, function <double(double)> f,
                    function <double(double)> fP, double epsilon)
{
    if ( fabs( f(start) ) < epsilon )
    {
        return start;
    }

    start = start - ( f( start ) / fP( start ) );
    
    start = newtonApprox(start, f, fP, epsilon);

    return start;
}