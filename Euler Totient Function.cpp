/*****************************************[USING NUMBER OF DIVISOR]***************************************/
/**
    O(sqrt(n))
    very fast for single large query
*/
int Phi(int n)
{
    int ans, i;
    ans = n;

    if(n%2 == 0) {
        while(n%2 == 0) n /= 2;
        ans -= ans/2;
    }

    for(i=3; i*i<=n; i+=2) {
        if(n%i==0) {
            while(n%i==0) n /= i;
            ans -= ans/i;
        }
    }

    if(n>2) ans -= ans/n;

    return ans;
}




/************************************************[USING SIEVE]**************************************************/
/**
    O(n)
    exeTime => 0.2 sec
    formula phi(n) = n*(1-1/p1)*(1-1/p2)...*(1-1/pk)
    for multiple query
*/

const int Maxx = 2e6 + 100;
int phi[Maxx];      // (value of phi[i]) < i
bool flag[Maxx];

void sievePHI()    /// call in Main
{
    int i , j;
    for(i = 1; i <= Maxx; i++) phi[i] = i;

    phi[1] = flag[1] = 1;

    for(i = 2; i <= Maxx; i++)
    {
        if(flag[i] == 0)
        {
            for(j = i; j <= Maxx; j += i)
            {
                flag[j] = 1;
                phi[j] = (phi[j] / i) * (i - 1);
            }
        }
    }
}



/*********************************************[USING SEGMENTED SIEVE]******************************************/


const ll Maxx = 1e14 + 10;   // maximum possible number for b
const int sqrtMaxx = int(sqrt(Maxx))+1; // find all primes under sqrtMaxx
vector<int> primes;
bool flag[sqrtMaxx+1];

void sieve()    ///include in main!!!
{
    primes.eb(2);
    int ssMaxx = ceil(sqrt(sqrtMaxx));

    for(int i = 3; i <= ssMaxx; i += 2) {
        if(flag[i] == 0)
            for(int j = i*i; j <= sqrtMaxx; j += i+i)
                flag[j] = 1;
    }

    for(int i = 3; i <= sqrtMaxx; i += 2)
        if(flag[i] == 0)
            primes.eb(i);
}

const int RNG = 1e5 + 1;    // maximum range for b-a
ll phi[RNG], rem[RNG];      // must declare this array globally, for memory issue

void segSievePHI(ll a, ll b)
{
    for(int i = 0; i <= b-a; i++) {
        rem[i] = phi[i] = a+i;
    }


//    as we have got all the primes under sqrtMaxx
//    so we can use those primes for formula
//    and if there is still a prime above sqrtMaxx
//    for a number then we can get that prime from rem[]

    for(int i = 0; i < sz(primes); i++) {
        int p = primes[i];
        ll j = p < a ? ((a+p-1)/p)*p : p;   // ceil(a/p) = (a+p-1)/p

        while(j <= b) {
            phi[j-a] = (phi[j-a]/p) * (p-1);
            while(rem[j-a]%p == 0) {
                rem[j-a] /= p;
            }
            j += p;
        }
    }

    for(int i = 0; i <= b-a; i++) {
        if(rem[i] > 2) {
            phi[i] = (phi[i]/rem[i]) * (rem[i]-1);
        }
    }

    for(int i = 0; i <= b-a; i++) { //printing
        show(phi[i]);
    }
}

void _case()
{
    ll a, b; cin >> a >> b;
    segSievePHI(a, b);
}

