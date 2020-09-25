int64_t powmod_n(int64_t a, int p, const int mod = MOD)
{
    int64_t ans = 1;
    a %= mod;
    while(p)
    {
        if(p & 1) ans = (ans * a)%mod;
        a = (a * a)%mod;
        p >>= 1;
    }
    return ans;
}

// multiply two numbers a and b
// and avoiding overflow in big modular multiplication
ll mulMod(ll a, ll b, ll Mod)
{
    ll res = 0;     // res must be 0
    while(b) {
        if(b&1) res = (res+a)%Mod;
        a = (a << 1)%Mod;
        b >>= 1;
    }
    return res;
}