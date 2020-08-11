// Primality Test
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

ll mulMod(ll a, ll b, ll Mod) {
    ll res = 0;     // it MUST be 0
    while (b) {
        if (b & 1) res = (res + a) % Mod;
        a = (a << 1) % Mod;
        b >>= 1;
    }
    return res;
}

ll fastExp(ll a, ll p, ll Mod) {
    ll ans = 1;
    a %= Mod;
    while (p) {
        if (p & 1) ans = mulMod(ans, a, Mod);
        a = mulMod(a, a, Mod);
        p >>= 1;
    }
    return ans;
}

bool isPrime(ll n, int iter = 5) {
    if (n < 4) return n == 2 || n == 3;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 0; i < iter; i++) {
        ll a = 2 + rand() % (n - 3);
        if (fastExp(a, n - 1, n) != 1) return 0;
    }
    return 1;
}


/*******************************************[USING Miller Rabin]************************************************/

ll mulMod(ll a, ll b, ll Mod) {
    ll res = 0;     // it MUST be 0
    while (b) {
        if (b & 1) res = (res + a) % Mod;
        a = (a << 1) % Mod;
        b >>= 1;
    }
    return res;
}

ll fastExp(ll a, ll p, ll Mod) {
    ll ans = 1;
    a %= Mod;
    while (p) {
        if (p & 1) ans = mulMod(ans, a, Mod);    // ans*a % Mod
        a = mulMod(a, a, Mod);  // a*a % Mod
        p >>= 1;
    }
    return ans;
}

bool isComposite(ll n, ll a, ll d, int s) {
    ll x = fastExp(a, d, n);    // a^d % n
    if (x == 1 || x == n - 1) return 0;    // x == {1, -1}

    for (int I = 1; I <= s; I++) {
        x = mulMod(x, x, n);
        if (x == n - 1) return 0;  // (a^d)^2r % n == -1  // r -> [1, s-1]
    }
    return 1;
}

bool isPrime(ll n, int iter = 5) {
    if (n < 4) return n == 2 || n == 3;
    if (n % 2 == 0 || n % 3 == 0) return 0;

    int s = 0;
    ll d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        s++;
    }

    for (int i = 0; i < iter; i++) {
        ll a = 2 + rand() % (n - 3);  // a -> [2, n-2]  // OR use first k (k > 9) prime numbers for base [probability for  incorrectness 1/4^k]
        if (isComposite(n, a, d, s)) return 0;
    }
    return 1;
}
