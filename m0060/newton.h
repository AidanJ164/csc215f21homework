#include <cmath>
#include <functional>

using namespace std;

double newtonApprox( double start, function <double(double)> func,
                     function <double(double)> funcP, double epsilon );
