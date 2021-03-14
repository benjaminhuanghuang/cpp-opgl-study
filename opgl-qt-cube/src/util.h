#ifndef UTIL_H
#define UTIL_H


namespace Util
{
    double normalize_between_0_1(double x, double xmax, double xmin);
    double normalize_between_minus1_plus1(double x, double xmax, double xmin);
    double normalize_between_a_b(double x, double xmax, double xmin, double a, double b);
}

#endif // UTIL_H
