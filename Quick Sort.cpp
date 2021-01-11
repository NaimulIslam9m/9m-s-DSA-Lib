#include<bits/stdc++.h>
using namespace std;
const int Maxx = 1e5+10;
int arr[Maxx];

int Partition(int beg, int end)
{
    int low = beg;
    int high = end;
    bool right = true;      // very important.

    while(low < high)
    {
            if(arr[low] > arr[high])
            {
                swap(arr[low], arr[high]);
                right = right ^ 1;      // vitore dhukle value take toggle kortesi
            }
            if(right) high--;
            else low++;
    }
    return low; // or return high;
}

void quickSort(int beg, int end)
{
    if(beg >= end) return;
    int i = Partition(beg, end);
    quickSort(beg, i);
    quickSort(i+1, end);
}

int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> arr[i];

    quickSort(0, n-1);

    for(int i=0; i<n; i++)
        cout << arr[i] << " \n"[i==n-1];
    return 0;
}
