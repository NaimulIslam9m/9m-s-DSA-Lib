/**
    O(sz(dividend))
    divisor <= 10^18
*/
//finding remainder
int Remainder(int divisor, string dividend)
{
    int rem = 0;
    for(int i = 0; i < sz(dividend); i++) {
        rem = (rem*10 + (dividend[i]-48))%divisor;
    }
    return rem;
}


//finding quotient
string Quotient(int divisor, string dividend)
{
    bool first = 1;
    int rem = 0;
    string quot;
    for(int i = 0; i < sz(dividend); i++) {
        rem = rem*10 + (dividend[i]-48);
        if(first && rem < divisor) continue;
        quot += (rem/divisor)+48;
        rem %= divisor;
        first = 0;
    }
    return quot;
}


//multiply
string Multiply(string a, string b)
{
    vector<int> ans(1000000);
    string Ans;
    int carry = 0, i, j, k;
    reverse(all(a));
    reverse(all(b));
    if (sz(a) < sz(b)) swap(a, b);

    for (i = 0; i < sz(b); i++) {
        for (j = 0; j < sz(a); j++) {
            carry =  ans[i+j] + (b[i]-'0') * (a[j]-'0') + carry;
            ans[i+j] = carry%10;
            carry /= 10;
        }

        for (k = 0; carry; k++) {
            ans[i+j+k] = carry%10;
            carry /= 10;
        }
    }

    for (int I = i+j+k-2; ~I; I--) {
        Ans.push_back(char(ans[I]+'0'));
    }

    return Ans;
}
