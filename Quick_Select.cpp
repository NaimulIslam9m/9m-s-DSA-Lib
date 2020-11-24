#include <local.h>

using IT = vec<array<int, 3>> :: iterator;

//* finding kth smallest element
int quick_select(IT lo, IT hi, int k) {
    if (hi - lo == 1) // signle value is always sorted
        return (*lo)[0];

    int pivot_idx = rand() % (hi - lo); // selecting randomized pevot
    swap(*(lo + pivot_idx), *(hi - 1)); // putting pevot at last position

    array<int, 3> piv = *(hi - 1); // pevot এর value হাতে রাখতেছি

    IT x = lo;
    ll cnt = 0; // pevot এর leftএ total কয়টা element আছে তা count করব
                // কারণ pevot এর ছোট value গুলাই pevot এর leftএ থাকবে।
    for (IT i = lo; i < hi - 1; i++)
        if (*i < piv) {
            swap(*i, *x);
            cnt += (*x)[1];
            x++;
        }

    swap(*x, *(hi - 1));
    if (k < cnt)
        return quick_select(lo, x, k);
    if (k >= cnt + (*x)[1])
        return quick_select(x + 1, hi, k - cnt - (*x)[1]);
    return (*x)[0];
}

// [Task: https://vjudge.net/problem/LightOJ-1349][Solution: https://pastebin.com/gJ1kwkaT]
// [More about algo: https://tinyurl.com/y4lwbcgo]