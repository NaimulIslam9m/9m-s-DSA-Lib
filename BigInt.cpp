#include "local.h"

using BigInt = vec<int>;

BigInt BigInteger(string &a) {
    // not considering negative
    int len = siz(a);
    BigInt b(len);
    rep(i, 0, len)
        b[i] = a[i] - '0';
    return b;
}

void RemoveZeros(BigInt &a) {
    while (siz(a) > 1 && a.back() == 0)
        a.pop_back();
}

void AddZeros(BigInt &a, int len) {
    while (siz(a) < len)
        a.emplace_back(0);
}

BigInt operator+ (BigInt a, BigInt b) {
    reverse(all(a));
    reverse(all(b));
    int len = max(siz(a), siz(b));

    AddZeros(a, len);
    AddZeros(b, len);

    BigInt c(len);
    int carry = 0;

    rep(i, 0, len) {
        int x = a[i] + b[i] + carry;
        carry = x > 9 ? 1 : 0;
        c[i] = x % 10;
    }
    if (carry)
        c.emplace_back(1);

    reverse(all(c));

    return c;
}

BigInt operator* (BigInt a, BigInt b) {
    reverse(all(a));
    reverse(all(b));

    if (siz(a) < siz(b))
        swap(a, b);

    int carry = 0, len_a = siz(a), len_b = siz(b);
    BigInt c(3 * siz(a));

    rep(i, 0, len_b) {
        rep(j, 0, len_a) {
            carry = c[i + j] + b[i] * a[j] + carry;
            c[i + j] = carry % 10;
            carry /= 10;
        }

        for (int j = 0; carry; j++) {
            c[i + len_a + j] = carry % 10;
            carry /= 10;
        }
    }

    RemoveZeros(c);
    reverse(all(c));

    return c;
}

void operator<< (ostream& out, const BigInt &a) {
    trav(t, a)
        out << t;
    out << '\n';
}

void operator>> (istream& in, BigInt &a) {
    string s; in >> s;
    a = BigInteger(s);
}