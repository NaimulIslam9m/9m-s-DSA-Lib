// segment tree
/*
    all 1 based indexed
    all means ALL :/
*/
// recursive 
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




//iterative [perfect!]
const int N = 1e5;  // limit for array size
int n;  // array size
int t[2 * N];

void build() {  // build the tree
  for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
}

void modify(int p, int value) {  // set value at position p
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
}

int query(int l, int r) {  // sum on interval [l, r)
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += t[l++];
    if (r&1) res += t[--r];
  }
  return res;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", t + n + i);
  build();
  modify(0, 1);
  printf("%d\n", query(3, 11));
  return 0;
}