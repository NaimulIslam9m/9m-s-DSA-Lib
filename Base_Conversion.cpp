#include <local.h>

int64_t pow_n(int64_t a, int p) {
    int64_t ans = 1;
    while (p) {
        if (p & 1) ans *= a;
        a = a * a;
        p >>= 1;
    }
    return ans;
}

// * convert to decimal
// * a => number to convert, base => base of a
int64_t getDecimal(int64_t a, int base) {
    assert(a > -1);
    int64_t b = 0, i = 0;
    while (a) {
        b += a % 10 * pow_n(base, i++);
        a /= 10;
    }
    return b;
}

// * convert decimal to other base
vector<int> convert(int64_t a, int base) {
    assert(a > -1);
    vector<int> v;
    while (a) {
        v.emplace_back(a % base);
        a /= base;
    }
    reverse(v.begin(), v.end());
    return v;
}