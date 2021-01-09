#include <local.h>

//* original value of a[i] can be obtained through d[a[i]]
vector<int> d = a;
unify(d);
rep(i, 0, n) {
	a[i] = lower_bound(all(d), a[i]) - d.begin();
}

//* Even faster implementation
int n = a.size();
vector<pair<int, int>> pairs(n);
for (int i = 0; i < n; ++i)
{
	pairs[i] = {a[i], i};
}
sort(pairs.begin(), pairs.end());
int nxt = 0;
for (int i = 0; i < n; ++i)
{
	if (i > 0 && pairs[i - 1].first != pairs[i].first)
		nxt++;
	a[pairs[i].second] = nxt;
}