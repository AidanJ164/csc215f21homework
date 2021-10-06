#include "newton.h"

double newtonApprox(double start, function <double(double)> f,
                    function <double(double)> fP, double epsilon)
{
    if ( fabs( start ) )
    {
        return start;
    }


}