#include <local.h>

/*******************************************[TRIAL DIVISION]**********************************************/
/**
    O(sqrt(n))
*/

bool isPrime(int n) {
    if (n < 4) return n == 2 || n == 3;

    if (n % 2 == 0 || n % 3 == 0) return false;  //for skipping middle 5 numbers

    int sqrt_n = int(sqrt(n));
    for (int i = 5; i <= sqrt_n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}


/***************************************[USING FERMART'S LITTLE THEOREM]**********************************/
/**
    O(Log(n))
*/

int64_t mulMod(int64_t a, int64_t b, int64_t Mod) {
    int64_t res = 0;     // it MUST be 0
    while (b) {
        if (b & 1) res = (res + a) % Mod;
        a = (a << 1) % Mod;
        b >>= 1;
    }
    return res;
}

int64_t fastExp(int64_t a, int64_t p, int64_t Mod) {
    int64_t ans = 1;
    a %= Mod;
    while (p) {
        if (p & 1) ans = mulMod(ans, a, Mod);
        a = mulMod(a, a, Mod);
        p >>= 1;
    }
    return ans;
}

bool isPrime(int64_t n, int iter = 5) {
    if (n < 4) return n == 2 || n == 3;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 0; i < iter; i++) {
        int64_t a = 2 + rand() % (n - 3);
        if (fastExp(a, n - 1, n) != 1) return 0;
    }
    return 1;
}


/*******************************************[USING Miller Rabin]************************************************/

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template <class T>
T Rand(T l, T r) {
	uniform_int_distribution<T> uid(l, r);
	return uid(rng);
}

int64_t mulMod(int64_t a, int64_t b, int64_t Mod) {
    int64_t res = 0;     // it MUST be 0
    while (b > 0) {
        if (b & 1) res = (res + a) % Mod;
        a = (a << 1) % Mod;
        b >>= 1;
    }
    return res;
}

int64_t pow_n(int64_t a, int64_t p, int64_t Mod) {
    int64_t ans = 1;
    a %= Mod;
    while (p > 0) {
        if (p & 1) ans = mulMod(ans, a, Mod);    // ans*a % Mod
        a = mulMod(a, a, Mod);  // a*a % Mod
        p >>= 1;
    }
    return ans;
}

bool isComposite(int64_t n, int64_t a, int64_t d, int s) {
    int64_t x = pow_n(a, d, n);    // a^d % n
    if (x == 1 || x == n - 1) // x == {1, -1}
        return 0;

    for (int I = 1; I <= s; I++) {
        x = mulMod(x, x, n);
        if (x == n - 1) // (a^d)^2r % n == -1  // r -> [1, s-1]
            return 0;
    }
    return 1;
}

bool isPrime(int64_t n, int iter = 5) {
    if (n < 4) return n == 2 || n == 3;
    if (n % 2 == 0 || n % 3 == 0) return 0;

    int s = 0;
    int64_t d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        s++;
    }

    for (int i = 0; i < iter; i++) {
        int64_t a = 2 + Rand(0ll, n - 4);  // a -> [2, n-2]  // OR use first k (k > 9) prime numbers for base [probability for  incorrectness 1/4^k]
        if (isComposite(n, a, d, s)) 
            return 0;
    }
    return 1;
}