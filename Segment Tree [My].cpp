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
    int L = node<<1;
    int R = L+1;
    int mid = beg + ((end - beg)>>1);
    int p = query(L, beg, mid, i, j);
    int q = query(R, mid+1, end, i, j);
    return p+q;
}

void update(int node, int beg, int end, int i, int val) {
    if(beg == i && end == i) {
        T[node] += val;
        return;
    }
    if(end < i || beg > i)
        return;
    int L = node<<1;
    int R = L+1;
    int mid = beg + ((end - beg)>>1);
    update(L, beg, mid, i, val);
    update(R, mid+1, end, i, val);
    T[node] = T[L] + T[R];
}
