#include <cmath>
#include <functional>

using namespace std;

double newtonApprox( double start, function <double(double)> f,
                     function <double(double)> fP, double epsilon );
