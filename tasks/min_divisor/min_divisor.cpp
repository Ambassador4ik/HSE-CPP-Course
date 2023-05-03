#include "min_divisor.h"

#include "math.h"

int64_t MinDivisor(int64_t number) {
    int64_t min_divisor = 1;
    for (int64_t i = 2; i <= static_cast<int64_t>(round(sqrt(number))); i++) {
        if (number % i == 0) {
            min_divisor = i;
            break;
        }
    }
    if (min_divisor == 1) {
        min_divisor = number;
    }
    return min_divisor;
}
