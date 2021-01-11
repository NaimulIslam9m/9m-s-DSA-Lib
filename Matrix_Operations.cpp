#include <local.h>

// ! notice the value N
vec<vec<int>> multiply(vec<vec<int>> &a, vec<vec<int>> &b) {
    vec<vec<int>> c(N, vec<int>(N, 0));
    rep(i, 0, N)
        rep(j, 0, N)
            rep(k, 0, N)
                c[i][j] += a[i][k] * b[k][j];
    return c;
}

vec<vec<int>> pow_n(vec<vec<int>> &a, int p) {
    vec<vec<int>> ans(N, vec<int>(N, 0));
    rep(i, 0, N)
        ans[i][i] = 1;

    while (p > 0) {
        if (p & 1) {
            ans = multiply(ans, a);
        }
        a = multiply(a, a);
        p >>= 1;
    }
    return ans;
}