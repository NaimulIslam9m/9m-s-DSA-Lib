// segment tree
/*
    all 1 based indexed
    all means ALL :/
*/
// recursive
#define MAX 100000

int T[MAX * 4 + 100];

int query(int node, int beg, int end, int i, int j) {
    if(beg >= i && end <= j) return T[node];
    if(end < i || beg > j) return 0;

    int mid = (beg + end) / 2;
    int p = query(2 * node, beg, mid, i, j);
    int q = query(2 * node + 1, mid + 1, end, i, j);
    return p + q;
}

void update(int node, int beg, int end, int i, int val) {
    if(beg == end) {  // beg == end == i
        T[node] += val;
        return;
    }
    if(end < i || beg > i) return;

    int mid = (beg + end) / 2;
    update(2 * node, beg, mid, i, val);
    update(2 * node + 1, mid + 1, end, i, val);
    T[node] = T[2 * node] + T[2 * node + 1];
}




//iterative [perfect!]
const int MAX = 1e5;  // limit for array size
int start;  // next smallest power of 2
int TT[4 * MAX + 100];

void build() {
  for (int i = start - 1; i > 0; --i) TT[i] = TT[i<<1] + TT[i<<1|1];
}

void modify(int p, int value) {  // set value at position p [0 based index]
  for (TT[p += start] = value; p > 1; p >>= 1) TT[p>>1] = TT[p] + TT[p^1];
}

int query(int l, int r) {  // sum on interval [l, r) [0 base index]
  int res = 0;
  for (l += start, r += start; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += TT[l++];
    if (r&1) res += TT[--r];
  }
  return res;
}

int main() {
    cin >> n;
    start = 1LL << int(ceil(log2(n)));
    for (int i = 0; i < n; ++i) cin >> TT[start + i];
    build();
    modify(pos-1, val);
    cout << query(l-1, r) << '\n';
    return 0;
}