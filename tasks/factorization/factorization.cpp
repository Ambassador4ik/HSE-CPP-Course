#include "factorization.h"

std::vector<std::pair<int64_t, int>> Factorize(int64_t x) {
    std::vector<std::pair<int64_t, int>> result;
    for (int64_t p = 2; p * p <= x; ++p) {
        if (x % p == 0) {
            result.emplace_back(p, 0);
            while (x % p == 0) {
                x /= p;
                ++result.back().second;
            }
        }
    }
    if (x != 1) {
        result.emplace_back(x, 1);
    }
    return result;
}
