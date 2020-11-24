#include <bits/stdc++.h>
using namespace std;

void DBG() { cerr << endl; }
template<class Head, class... Tail>
void DBG(Head H, Tail... T) { cerr << ' ' << H; DBG(T...); }
#define dbg(...) cerr << "(" << (#__VA_ARGS__) << "):", DBG(__VA_ARGS__)

using ll = long long;
using ld = long double;
using str = string;

#define sqr(a) ll(a) * (a)
#define siz(a) int(a.size())
#define ints(a...) int a; read(a)
#define all(a) a.begin(), a.end()  // [i, n) => i + all(v)  |  [0, i) => all(v) - n + i
#define rall(a) a.rbegin(), a.rend()
#define trav(i, v) for (const auto i : v)
#define rep(i, b, n) for (auto i = b; i < n; i++)
#define per(i, b, n) for (auto i = b; i >= n; i--)
#define unify(a) sort(all(a)); a.resize(unique(all(a)) - a.begin())

template <class T> using vec = vector<T>;
template <class... Args> inline void read(Args&... args) { ((cin >> args), ...); }
template <class... Args> inline void show(Args... args) { ((cout << args << " "), ...); }
template <class T1, class T2> inline bool ckmin(T1 &a, T2 b) { return a > b ? a = b, 1 : 0; } // a = min(a, b)
template <class T1, class T2> inline bool ckmax(T1 &a, T2 b) { return a < b ? a = b, 1 : 0;  }
template <class T> inline void operator>> (istream& in, vector<T>& v) { rep(i, 0, siz(v)) in >> v[i]; }
template <class T> inline void operator<< (ostream& out, const vector<T>& v) { rep(i, 0, siz(v)) out << v[i] << " \n"[i + 1 == siz(v)]; }

const int MOD = 1e9 + 7;