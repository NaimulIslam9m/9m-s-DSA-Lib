#include <local.h>
/**-----------------------------------------------------------------------------------------------------------------------
 * *                                                     INFO
 * Prime factor of a number
 * Complexity: O(sqrt(n))
 *-----------------------------------------------------------------------------------------------------------------------**/

vector<int> PF;

void primeFactors(int n) {
    int i;1
    while (n % 2 == 0) {
        PF.emplace_back(2);
        n /= 2;
    }
    for (i = 3; i * i <= n; i += 2) { // careful about overflow of i*i
        while (n % i == 0) {
            PF.emplace_back(i);
            n /= i;
        }
    }
    if (n > 2) 
        PF.emplace_back(n);
}

/// using the concept of "prime factors comes in pairs"
void primeFactors(int n) {
    int i;
    int sqrt_n = floor(sqrt(n));
    for (i = 2; i < sqrt_n; i++) {
        if (n % i == 0) {
            PF.emplace_back(i);
            PF.emplace_back(n / i);
        }
    }
    if (n % sqrt_n == 0) 
        PF.emplace_back(sqrt_n);
}

/**-----------------------------------------------------------------------------------------------------------------------
 * *                                                     INFO
 * * Counting DISTINCT PRIME FACTORS for every number
 * factor == divisor
 *-----------------------------------------------------------------------------------------------------------------------**/

vector<int> primeFactor(MAX);

void incrementAllMultiples(int i) {
    for (int j = i; j < MAX; j += i) 
        primeFactor[j]++;
}

void getDistinctPrimeFactors() {
    for (int i = 2; i < MAX; i++) 
        if (primeFactor[i] == 0) 
            incrementAllMultiples(i);
}



/**-----------------------------------------------------------------------------------------------------------------------
 * *                                                     INFO
 * *  for multiple queries
 *  O(n Log(Log(n))) for sieve
 *  O(Log(n)) printing prime factor
 *-----------------------------------------------------------------------------------------------------------------------**/

const int MAX = 1e6 + 10;

int SPF[MAX], PF[MAX], prefSum[MAX];

void sieveSPF() {
    int i, j;
    for (i = 1; i <= MAX; i++) 
        SPF[i] = i;

    int sqrtMAX = int(sqrt(MAX));
    for (i = 2; i <= sqrtMAX; i++) {
        if (SPF[i] == i) {
            for (j = i * i; j <= MAX; j += i)
                if (SPF[j] == j) 
                    SPF[j] = i;
        }
    }
}

// printing prime factors of x
void primeFactors(int x) {
    vector<int> pf;
    while (x != 1) {
        pf.emplace_back(SPF[x]);
        x /= SPF[x];
    }

    for (auto it : pf)
        cout << it << ' ';
    cout << '\n';
}

void precalc() {
    sieveSPF();
    int i;

    // calculating number of prime factors of x
    PF[0] = PF[1] = 0;
    for (i = 2; i < MAX; i++)
        PF[i] = PF[i / SPF[i]] + 1;

    // whien we need to calculate number of prime factors of n!
    for (i = 1; i < MAX; i++)
        prefSum[i] = prefSum[i - 1] + PF[i];
}