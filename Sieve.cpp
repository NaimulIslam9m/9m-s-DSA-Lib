#include <local.h>
/**=======================================================================================================================
 *                                                     SIEVE OF ERATOSTHENES
 *=======================================================================================================================**/

/**-----------------------------------------------------------------------------------------------------------------------
 * *                                                     INFO
 * * Main: marking primes
 * * By-product: list of primes
 * * Complexity: O( n Log(Log(n)) )
 *
 * * this code can generate 5761461 primes (  5 * 10^6 টা প্রাইম! :o )
 * * primality test upto MAX
 *-----------------------------------------------------------------------------------------------------------------------**/

const int MAX = 1e8;
vector<bool> isPrime(MAX, true);
vector<int> primes;

void markNonPrimes(int i) {
    for (int j = i * i; j < MAX; j += i)  // MAX -> যত পর্যন্ত প্রাইম চাই ততো
        isPrime[j] = 0;
}

void getPrimes(bool getList = 0) {
    if (getList) 
        primes.emplace_back(0);   // to make 1based indexed
    isPrime[0] = isPrime[1] = 0;
    int sqrtMAX = round(sqrt(MAX));
    
    for (int i = 2; i <= sqrtMAX; i++) 
        if (isPrime[i]) 
            markNonPrimes(i);

    if (getList) {
        primes.emplace_back(2);
        for (int i = 3; i < MAX; i += 2) // list has primes upto MAX
            if (isPrime[i])
                primes.emplace_back(i);
    }
}

/*==================================================== END OF SIEVE OF ERATOSTHENES ====================================================*/




/**=======================================================================================================================
 *                                                     Linear Sieve
 *=======================================================================================================================**/

/**-----------------------------------------------------------------------------------------------------------------------
 * *                                                   INFO
 * * Main: Get prime list
 * * By-product: smallest prime factor of all numbers 
 * * Complexity O(n)
 * * Tip: spf[i] == i means i is prime [except 0] ;)
 *-----------------------------------------------------------------------------------------------------------------------**/

const int MAX = 1e8 + 2;
int spf[MAX];
vector<int> primes;

void fastSieve() {
    for (int i = 2; i < MAX; i++) {
        if (spf[i] == 0) {
            spf[i] = i;
            primes.emplace_back(i);
        }
        for (int j = 0; j < (int)primes.size() && primes[j] <= spf[i] && i * primes[j] < MAX; j++)
            spf[i * primes[j]] = primes[j];
    }
}


//** memory efficient implementation **//
bitset<MAX> isPrime;
vector<int> primes;

void fastSieve() {
    isPrime.set();
    for (int i = 2; i < MAX; i++) {
        if (isPrime[i]) 
            primes.emplace_back(i);
        for (int j = 0; j < (int)primes.size() && i * primes[j] < MAX; j++) {
            isPrime[primes[j] * i] = 0;
            if (i % primes[j] == 0)
                break;
        }
    }
}

/*==================================================== END OF Linear Sieve ====================================================*/






/**=======================================================================================================================
 *                                                     SEGMENTED SIEVE
 *=======================================================================================================================**/

/**-----------------------------------------------------------------------------------------------------------------------
 * *                                                     INFO
 * * Main: marking primes in a range
 * Complexity: O((R-L+1)Log Log(R)+ √R Log Log(√R))
 *-----------------------------------------------------------------------------------------------------------------------**/

vector<ll> primes;

ll ceil(ll nom, ll denom) {
    return (nom + denom - 1) / denom;
}

vector<bool> getMarkedPrimesBetweenLR(int L, int R) {
    vector<bool> isPrime(R - L + 1, true);
    for (auto prime : primes) {
        ll i = max((prime * prime), ceil(L, prime) * prime);
        while (i <= R) {
            isPrime[i - L] = false;
            i += prime;
        }
    }
    if (L == 1) isPrime[0] = false;
    return isPrime;
}

void getPrimes(int sqrtR) {
    vector<bool> isPrime(sqrtR + 1, true);

    // get prime numbers from 2 to sqrtR
    for (int i = 2; i <= sqrtR; i++) {
        if (isPrime[i]) {
            primes.emplace_back(i);
            for (int j = i * i; j <= sqrtR; j += i)
                isPrime[j] = false;
        }
    }
}

vector<bool> segmentedSieve(int L, int R) {
    int sqrtR = round(sqrt(R));
    // for multiple test case put this line at start
    // and pass the sqrt of maximum possible value of R
    getPrimes(sqrtR); 
    return getMarkedPrimesBetweenLR(L, R);
}

/*==================================================== END OF SEGMENTED SIEVE ====================================================*/




/**=======================================================================================================================
 *                                                     MEMORY EFFICIENT SIEVE
 *=======================================================================================================================**/

const int MAX = 1e7 + 1;
vector<int> primes;
bitset<MAX> isPrime; 

void sieve()
{
    isPrime.set();
    int sqrtMAX = round(sqrt(MAX));

    for (int i = 4; i < MAX; i += 2)
        isPrime[i] = 0;

    for (int i = 3; i <= sqrtMAX; i += 2) 
        if (isPrime[i]) 
            for (int j = i * i, k = 2 * i; j < MAX; j += k)
                isPrime[j] = 0;

    primes.emplace_back(2);
    for (int i = 3; i < MAX; i += 2)
        if (isPrime[i])
            primes.emplace_back(i);
}

/*==================================================== END OF MEMORY EFFICIENT SIEVE ====================================================*/

