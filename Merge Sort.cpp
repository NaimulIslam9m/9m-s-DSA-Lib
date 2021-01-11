/**
    mid begin er dike tahkbe
*/
#include<bits/stdc++.h>
using namespace std;
const int Maxx = (int) 1e5;
vector<int> v(Maxx);

void merge(int beg, int end, int mid)
{
    int temp[Maxx], i, j;

    for(i = beg; i <= end; i++)
        temp[i] = v[i];

    int n = mid - beg + 1;  // first length
    int m = end - mid;      // last length
    int k = beg;

    i = j = 0;
    while(i < n && j < m)
    {
        if(temp[i+beg] < temp[j+mid+1])
            v[k++] = temp[(i++) + beg];
        else
            v[k++] = temp[(j++) + mid+1];
    }
    while(i < n)
        v[k++] = temp[(i++) + beg];
    while(j < m)
        v[k++] = temp[(j++) + mid+1];
}

void mergesort(int beg, int end)
{
    if(beg >= end) return;
    int mid = beg + ((end - beg)>>1);
    mergesort(beg, mid);
    mergesort(mid+1, end);

    merge(beg, end, mid);
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> v[i];

    mergesort(0, n-1);

    for(int i = 0; i < n; i++)
        cout << v[i] << " \n"[i == n-1];

    return 0;
}
/**
15
277 5 368 -8 17 96 976 12 0 1 58 14 89 85 26
*/
