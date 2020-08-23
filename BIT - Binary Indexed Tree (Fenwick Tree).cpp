/*
    BIT update "just can ADD value" to the specific index.
    All here is 1 based indexed
*/
#include<bits/stdc++.h>
using namespace std;

#define LSB(n) ((n) & -(n))
const int MAX = 32001; // number of leaf noads (array elements)
int64_t Bit[MAX];

int64_t pref(int idx) {
    int64_t sum = 0;
    while(idx > 0) {
        sum += Bit[idx];
        idx -= LSB(idx);
    }
    return sum;
}

void update(int idx, int delta) {
    while(idx <= MAX) {
        Bit[idx] += delta;
        idx += LSB(idx);
    }
}

int rsum(int l, int r)
{
    return pref(r) - pref(l - 1);
}


int main()
{
    cin >> n; //array size

    for(int i=1; i<=n; i++) //taking input
    {
        cin >> x;
        update(i, x); // x এর জাইগায় যেই value নিব সেটা দিতে হবে।
    }

    //updating
    for(int i = 1; ; i++) {
        cin >> idx >> x;
        update(idx, -x);
        update(idx, x);
        // or add the difference
    }

    return 0;
}

//Problem 1: https://codeforces.com/contest/1073/problem/D
//Solution 1: https://codeforces.com/contest/1073/submission/44863255

//Problem 2: https://www.hackerrank.com/contests/university-codesprint-4/challenges/unique-art/problem
//Solution 2: http://p.ip.fi/T9YM

//Problem 3: https://csacademy.com/contest/round-47/task/cut-the-trees/statement/
