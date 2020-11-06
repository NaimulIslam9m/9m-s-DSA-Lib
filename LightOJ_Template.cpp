#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using str = string;

#define sqr(a) ll(a) * a
#define siz(a) int(a.size())
#define gcd(a, b) __gcd(a, b)
#define all(a) a.begin(), a.end()  // [i, n) => i + all(v)  |  [0, i) => all(v) - n + i
#define rall(a) a.rbegin(), a.rend()
#define lcm(a, b) (a / gcd(a, b) * b)
#define trav(i, v) for (const auto i : v)
#define rep(i, b, n) for (int i = b; i < n; i++)
#define per(i, b, n) for (int i = b; i >= n; i--)
#define unify(a) sort(all(a)); a.resize(unique(all(a)) - a.begin())

template <class T> using vec = vector<T>;
template <class T1, class T2> inline bool ckmin(T1 &a, T2 b) { return a > b ? a = b, 1 : 0; } // a = min(a, b)
template <class T1, class T2> inline bool ckmax(T1 &a, T2 b) { return a < b ? a = b, 1 : 0;  } 
template <class T> inline void operator>> (istream& in, vector<T>& v) { rep(i, 0, siz(v)) in >> v[i]; }
template <class T> inline void operator<< (ostream& out, const vector<T>& v) { rep(i, 0, siz(v)) out << v[i] << " \n"[i + 1 == siz(v)]; }

// static char buff[1 << 20]; // 1048576 == 1e6

const int MOD = 10000019;

void solve() {
    
}

signed main() {
    int _ = 1;
    // scanf("%d", &_);
    rep(i, 1, _ + 1) {
        // printf("Case %d: ", i);
        solve();
    }
    return 0;
}