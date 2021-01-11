ll burnside_lemma(int n, int k)
{
    ll ans = 0;
    // rotation
    for (int i = 1; i <= n; i++) {
        ans += fastExp(k, __gcd(i, n));
    }

    //flip
    if (n&1) {
        ans += fastExp(k, n/2 + 1) * n;
    } else {
        ans += (fastExp(k, n/2) * (n/2)) + (fastExp(k, n/2 + 1) * (n/2));
    }
    return ans/(2*n);
}
