#include <local.h>
/**
 **  calcuate upto MAX = 10^4
 *   using precalculation
 */
int C[MAX][MAX];
void precal()
{
    C[0][0] = 1;
    for (int i = 1; i < MAX; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || i == j) C[i][j] = 1;
            else C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
}

/**
 **  calcuate upto n = 10^18
 */
int ncr(int n, int r)
{
    int ans = 1;
    r = min(r, n - r);
    for (int i = 0; i < r; i++) {
        ans = ans * (n - i) / (i + 1);
    }
    return ans;
}

/**
 *   calculating nCr using factorial
 **  claculate upto N = 10^8
 *   useing precalculation
 **  you can remove ifact array and do it manually for memory optimization
 */
vector<int64_t> fact(MAX), ifact(MAX);

int64_t pow_n(int64_t a, int64_t p, const int64_t mod = MOD) {
    int64_t ans = 1;
    a %= mod;
    while(p > 0) {
        if(p & 1) ans = ans * a % mod;
        a = a * a % mod;
        p >>= 1;
    }
    return ans;
}

int64_t inv(int b) {
    return pow_n(b, MOD - 2);
}

void precal() {
    fact[0] = fact[1] = 1;
    for (int i = 2; i < MAX; i++)
        fact[i] = fact[i - 1] * i % MOD;

    ifact[MAX - 1] = inv(fact[MAX - 1]);
    for (int i = MAX - 2; ~i; i--)
        ifact[i] = ifact[i + 1] * (i + 1) % MOD;
}

int64_t ncr(int n, int r) {
    if (r > n) return 0;
    return fact[n] * ifact[r] % MOD * ifact[n - r] % MOD;
}

int npr(int n, int r) {
    if (r > n) return 0;
    return fact[n] * ifact[n - r] % MOD;
}