#include "reduce_fraction.h"

int64_t ReduceFraction(int64_t numerator, int64_t denominator) {
    int64_t gcd = 0;
    int64_t a = numerator;
    int64_t b = denominator;
    while (b != 0) {
        gcd = b;
        b = a % b;
        a = gcd;
    }
    return numerator / gcd + denominator / gcd;
}
