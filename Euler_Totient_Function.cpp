#include <local.h>
/**=======================================================================================================================
 *                                                   USING NUMBER OF DIVISOR
 *=======================================================================================================================**/
/**-----------------------------------------------------------------------------------------------------------------------
 * *                                                     INFO
 *  O(sqrt(n))
 *-----------------------------------------------------------------------------------------------------------------------**/
template <class T>
T Phi(T n)
{
    T ans = n;

    if (n % 2 == 0) {
        while (n % 2 == 0)
            n /= 2;
        ans -= ans / 2;
    }

    for (int i = 3; ll(i) * i <= n; i += 2) {
        if (n % i == 0) {
            while (n % i == 0) 
                n /= i;
            ans -= ans / i;
        }
    }

    if(n > 1) 
        ans -= ans / n;

    return ans;
}



/**=======================================================================================================================
 *                                                    USING SIEVE
 *=======================================================================================================================**/

/**-----------------------------------------------------------------------------------------------------------------------
 * *                                                     INFO
 * * Main: get Phi values upto MAX
 * * By-product: prime checker
 *  O(n)
 *-----------------------------------------------------------------------------------------------------------------------**/
const int MAX = 5e6 + 100;
int phi[MAX];
bitset<MAX> vis;
vec<unsigned long long> pref(MAX);

void sievePHI() {
    for (int i = 1; i < MAX; i++) 
        phi[i] = i;

    vis[0] = vis[1] = 1; // need for prime check

    for (int i = 2; i < MAX; i++) 
        if (vis[i] == 0) 
            for (int j = i; j < MAX; j += i) {
                vis[j] = 1;
                phi[j] = (phi[j] / i) * (i - 1);
            }
}



/**=======================================================================================================================
 *                                                    USING SEGMENTED SIEVE
 *=======================================================================================================================**/


const ll MAX = 1e14 + 10;   // maximum possible number for b
const int sqrtMAX = int(sqrt(MAX))+1; // find all primes under sqrtMAX
vector<int> primes;
bool flag[sqrtMAX+1];

void sieve()    ///include in main!!!
{
    primes.eb(2);
    int ssMAX = ceil(sqrt(sqrtMAX));

    for(int i = 3; i <= ssMAX; i += 2) {
        if(flag[i] == 0)
            for(int j = i*i; j <= sqrtMAX; j += i+i)
                flag[j] = 1;
    }

    for(int i = 3; i <= sqrtMAX; i += 2)
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


//    as we have got all the primes under sqrtMAX
//    so we can use those primes for formula
//    and if there is still a prime above sqrtMAX
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

