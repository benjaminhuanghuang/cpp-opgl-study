#include "util.h"

namespace Util
{
    double normalize_between_0_1(double x, double xmax, double xmin)
    {
        return (x - xmin) / (xmax - xmin);
    }

    double normalize_between_minus1_plus1(double x, double xmax, double xmin)
    {
        return 2.0 * ((x - xmin) / (xmax - xmin)) - 1.0;
    }

    double normalize_between_a_b(double x, double xmax, double xmin, double a, double b)
    {
        return (b - a) * ((x - xmin) / (xmax - xmin)) + a;
    }
} // end namespace Util
