/*
    find XOR of a range of natural number
*/

#include<bits/stdc++.h>
using namespace std;

int computeXOR(int n) // xor from 1 to n
{
    int ck = n&3;   // n%4

    if(ck==0) return n;
    else if(ck==1) return 1;
    else if(ck==2) return n+1;
    else if(ck==3) return 0;
}

int findXOR(int l, int r) // xor form [l to r]
{
    return (computeXOR(l-1)^computeXOR(r));
}

int main()
{
    return 0;
}
