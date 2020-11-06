#include <local.h>
/**-----------------------------------------------------------------------------------------------------------------------
 * *                                                     INFO
 * Prime factor of a number
 * Complexity: O(sqrt(n))
 *-----------------------------------------------------------------------------------------------------------------------**/

namespace factorBasic {

    // {prime factor, power}
    template <class T> 
    vector<pair<T, int>> getFactors(T n) {
        vector<pair<T, int>> pf;
        /**
         * For faster execution, precalculate primes using sieve
         * For getting prime factors of n 
         * you just need upto the next prime after sqrt(n)
         * !careful about overflow p*p <= n
         */
        
        for (T i = 2; i * i <= n; i++)
            if (n % i == 0) {
                int c = 0;
                while (n % i == 0) 
                    n /= i, c++;
                pf.emplace_back(i, c);
            }
        if (n > 1) 
            pf.emplace_back(n, 1);
        
        return pf;
    }

    /**
     * for finding NOD fast
     * first precalculate primes using sieve
     * then count prime factors
     * and use formula (e1 + 1)(e2 + 1)...
     */
    template <class T>
    vector<T> getDivisors(T n) {
        vector<T> div;

        T i = 1;
        while (i * i < n) {
            if (n % i == 0) {
                div.emplace_back(i),
                div.emplace_back(n / i);
            }
            i++;
        }
        if (i * i == n)
            div.emplace_back(i);

        sort(all(div));
        return div;
    }
}
using namespace factorBasic;

/**-----------------------------------------------------------------------------------------------------------------------
 * *                                                     INFO
 * * Counting DISTINCT PRIME FACTORS for every number
 * MAX <= 1e8
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
 * MAX <= 1e8
 *-----------------------------------------------------------------------------------------------------------------------**/

const int MAX = 1e6 + 10;

int SPF[MAX], PF[MAX], prefSum[MAX];

void sieveSPF() {
    int i, j;
    for (i = 1; i <= MAX; i++) 
        SPF[i] = i;

    int sqrtMAX = int(sqrt(MAX));
    for (i = 2; i <= sqrtMAX; i++) 
        if (SPF[i] == i) 
            for (j = i * i; j <= MAX; j += i)
                if (SPF[j] == j) 
                    SPF[j] = i;
}

// not necessary
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

// not necessary
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