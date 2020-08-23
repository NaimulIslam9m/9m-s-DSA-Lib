// segment tree
/*
    all 1 based indexed
    all means ALL :/
*/

#include<bits/stdc++.h>
using namespace std;
#define Maxx 10000

int T[Maxx*3 + 100];

int query(int node, int beg, int end, int i, int j) {
    if(beg >= i && end <= j)
        return T[node];
    if(end < i || beg > j)
        return 0;
    int mid = (beg + end) / 2;
    int p = query(2*node, beg, mid, i, j);
    int q = query(2*node + 1, mid + 1, end, i, j);
    return p+q;
}

void update(int node, int beg, int end, int i, int val) {
    if(beg == i && end == i) {
        T[node] += val;
        return;
    }
    if(end < i || beg > i)
        return;
    int mid = (beg + end) / 2;
    update(2*node, beg, mid, i, val);
    update(2*node + 1, mid+1, end, i, val);
    T[node] = T[2*node] + T[2*node + 1];
}
