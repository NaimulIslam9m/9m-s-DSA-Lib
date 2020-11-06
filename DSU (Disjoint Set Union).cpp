#include <local.h>

struct DSU
{
	int connected; // number of components
	vector<int> par, sz;

	void init(int n) {
		par = sz = vector<int> (n + 1, 0);
		for (int i = 1; i <= n; i++)
			par[i] = i, sz[i] = 1;
		connected = n;
	}

	// always need to use "getPar" to get parent of some node
	// becasue par[] might not have main parent
	int getPar(int u) {
		while (par[u] != u) u = par[u] = par[par[u]];
		return u;
	}

	int getSize(int u) {
		return sz[getPar(u)];
	}

	void unite(int u, int v) {
		int par1 = getPar(u), par2 = getPar(v);

		if (par1 == par2)
			return;

		connected--;

		if (sz[par1] > sz[par2]) 
			swap(par1, par2);

		sz[par2] += sz[par1];
		sz[par1] = 0;
		par[par1] = par2;
	}
};

//Problem 1 (DSU + Divide and Conquer): https://codeforces.com/contest/813/problem/F
//Solution 1: https://codeforces.com/contest/813/submission/48548930
