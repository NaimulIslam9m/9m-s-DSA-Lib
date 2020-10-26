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
 *-----------------------------------------------------------------------------------------------------------------------**/

const int MAX = 1e5;
vector<bool> isPrime(MAX, true);
vector<int> primes;

void markMultiplesAsNonPrime(int i) {
    for (int j = i * i; j < MAX; j += i) { // MAX -> যত পর্যন্ত প্রাইম চাই ততো
        isPrime[j] = 0;
    }
}

void getPrimes() {
    primes.emplace_back(0);   // to make 1based indexed
    isPrime[0] = isPrime[1] = 0;
    int sqrtMAX = int(sqrt(MAX));
    
    for (int i = 2; i <= sqrtMAX; i++) {
        if (isPrime[i]) {
            primes.emplace_back(i);   // stores prime from 2 to sqrtMAX
            markMultiplesAsNonPrime(i);
        }
    }
}

/**-----------------------------------------------------------------------------------------------------------------------
 * *                                                     INFO
 * * Counting DISTINCT PRIME FACTORS for every number
 * factor == divisor
 *-----------------------------------------------------------------------------------------------------------------------**/

vector<int> primeFactor(MAX);

void incrementAllMultiples(int i) {
    for (int j = i; j < MAX; j += i) {
        primeFactor[j]++;
    }
}

void getDistinctPrimeFactors() {
    for (int i = 2; i < MAX; i++) {
        if (primeFactor[i] == 0) {
            incrementAllMultiples(i);
        }
    }
}

/*==================================================== END OF SIEVE OF ERATOSTHENES ====================================================*/




/**=======================================================================================================================
 *                                                     SEGMENTED SIEVE
 *=======================================================================================================================**/

/**-----------------------------------------------------------------------------------------------------------------------
 * *                                                     INFO
 * * Main: marking primes in a range
 * Complexity: O((R-L+1)Log Log(R)+ √R Log Log(√R))
 *-----------------------------------------------------------------------------------------------------------------------**/

vector<int> primes;

int ceil(int nom, int denom) {
    return (nom + denom - 1) / denom;
}

vector<bool> getMarkedPrimesBetweenLR(int L, int R) {
    vector<bool> isPrime(R - L + 1, true);
    for (auto prime : primes) {
        int i = max((prime * prime), ceil(L, prime) * prime);
        while (i <= R) {
            isPrime[i - L] = false;
            i += prime;
        }
    }
    if (L == 1) isPrime[0] = false;
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
    int sqrtR = int(sqrt(R));
    getPrimes(sqrtR);
    return getMarkedPrimesBetweenLR(L, R);
}


/*==================================================== END OF SEGMENTED SIEVE ====================================================*/




/**=======================================================================================================================
 *                                                     MEMORY EFFICIENT SIEVE
 *=======================================================================================================================**/

#define getbit(n, i) (((n) & (1LL << i)) != 0)
#define setbit1(n, i) ((n) | (1LL << i))

bool flag[(MAX + 31) / 32];
vector<int> primes;

void sieve() {
    for (int i = 4; i <= MAX; i += 2)
        setbit1(flag[i / 32], i % 32);  // i/32 == i>>5 AND i%32 == i&31

    primes.emplace_back(0); // to make 1based indexed
    primes.emplace_back(2);

    int sqrtMAX = int(sqrt(MAX));
    for (i = 3; i <= sqrtMAX; i += 2)
        if (getbit(flag[i / 32], i % 32) == 0)
            for (j = i * i; j <= MAX; j += i + i)
                setbit1(flag[j / 32], j % 32);

    for (i = 3; i <= MAX; i += 2) {
        if (getbit(flag[i / 32], i % 32) == 0) {
            primes.emplace_back(i);
        }
    }
}

/*==================================================== END OF MEMORY EFFICIENT SIEVE ====================================================*/

