#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> v(10);

void read() {
    generate(v.begin(), v.end(), []() {
        return rand() % 15;
    });
}

signed main() {
    read();
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());

    vector<int> compress(N);
    for (int i = 0; i < (int)v.size(); i++)
        compress[v[i]] = i;
    
    for (int i = 0; i < (int)v.size(); i++)
        cout << compress[v[i]] << ' ';
}