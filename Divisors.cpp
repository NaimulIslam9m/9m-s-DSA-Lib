/**
    p যদি x দিয়ে ভাগ যায় তবে x p এর একটা divisor(গুণনীয়ক)  or factor.
    1 থেকে n পর্যন্ত প্রতিটা সংখ্যার list of divisor বের করব
    O(n Log(n))
*/

vector<int> divisors[int(1e5)];

void Divisors(int n)
{
    for(int i = 1; i <= n; i++)
        for(int j = i; j <= n; j += i)
            divisors[j].eb(i);
}



/**
    Number of Divisors
    O(sqrt(n))
*/
/*********[using just SQRT]*********/

int NOD(int n)
{
    int i, cnt = 0;
    for(i = 1; i*i < n; i++) if(n%i == 0) cnt += 2;
    if(i*i == n) cnt++;
    return cnt;
}

/********[using FORMULA]***********/

int NOD(int n)
{
    int ans = 1, cnt = 1;
    if(!(n&1)) {
        while(!(n&1)) {
            cnt++;
            n >>= 1;
        }
        ans *= cnt;
    }

    for(int i = 3; i*i <= n; i += 2)
    {
        if(n%i == 0) {
            cnt = 1;
            while(n%i == 0) {
                cnt++;
                n /= i;
            }
            ans *= cnt;
        }
    }
    if(n > 2) ans *= 2;
    return ans;
}



/**
    Sum of Divisors
*/
int64_t pow_n(int64_t a, int p)
{
    int64_t ans = 1;
    while(p)
    {
        if(p & 1) ans = (ans * a);
        a = (a * a);
        p >>= 1;
    }
    return ans;
}

int SOD(int n)
{
    int ans = 1, cnt = 1;
    if(!(n&1)) {
        while(!(n&1)) {
            cnt++;
            n >>= 1;
        }
        ans *= (pow_n(2, cnt) - 1)/(2-1);
    }

    for(int i = 3; i*i <= n; i += 2)
    {
        if(n%i == 0) {
            cnt = 1;
            while(n%i == 0) {
                cnt++;
                n /= i;
            }
            ans *= (pow_n(i, cnt) - 1)/(i-1);
        }
    }
    if(n > 2) ans *= (pow_n(n, 2) - 1)/(i-1);
    return ans;
}




