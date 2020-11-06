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

int64_t pow_n(int64_t a, int p, const int mod = MOD) {
    // if mod is a prime
    p %= (mod - 1); 

    int64_t ans = 1;
    a %= mod;
    while (p) {
        if (p & 1) ans = ans * a % mod;
        a = a * a % mod;
        p >>= 1;
    }
    return ans;
}

// multiply two numbers a and b
// and avoiding overflow in big modular multiplication
// for O(1) way see the next snipt
// or just use __uint128_t
uint64_t mulMod(uint64_t a, uint64_t b, uint64_t mod)
{
    uint64_t res = 0;     // res must be 0
    while(b) {
        if(b & 1) res = (res + a) % mod;
        a = (a << 1) % mod;
        b >>= 1;
    }
    return res;
}

// source: https://cs.stackexchange.com/questions/77016/modular-multiplication
uint64_t mul_mod(uint64_t a, uint64_t b, uint64_t mod)
{
    if (a >= mod) a %= mod;
    if (b >= mod) b %= mod;

    long double x = a;
    uint64_t c = x * b / mod;
    int64_t r = (int64_t)(a * b - c * mod) % (int64_t)mod;
    return r < 0 ? r + mod : r;
}