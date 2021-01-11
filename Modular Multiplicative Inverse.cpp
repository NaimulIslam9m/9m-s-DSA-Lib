#include <local.h>
using ll = int64_t;
const int MAX = 2e5;
const int MOD = 1e9 + 7;

//**********************************[using extended gcd (extended euclid)]*********************************//
ll extended_GCD(ll a, ll b, ll &x, ll &y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    ll x1, y1;
    ll gcd = extended_GCD(b%a, a, x1, y1);
    x = y1 - (b/a)*x1;
    y = x1;
    return gcd;
}

ll modinv(ll a, ll MOD) {
    ll x, y;
    extended_GCD(a, MOD, x, y);
    if (x < 0) x += MOD;
    return x;
}


//*************************************[using Fermarts little theorem]*************************************//
int mul(ll x, ll y) {
    return (x * y)%MOD;
}

int modinv(ll a, int p) {
    ll ans = 1;
    while (p) {
        if (p & 1) ans = mul(ans, a);
        a = mul(a, a);
        p >>= 1;
    }
    return ans;
}


int32_t main()
{
    int a;
    // for extended gcd
    modinv(a, MOD);
    // for fermarts little theroem
    modinv(a, MOD-2);
    return 0;
}