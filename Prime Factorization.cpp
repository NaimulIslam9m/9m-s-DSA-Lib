// Prime Factorization
/**
 * Complexity: O(sqrt(n))
 */
vector<int> primeFactors;

void primeFactors(int n) {
    int i;
    while (n % 2 == 0) {
        primeFactors.emplace_back(2);
        n /= 2;
    }
    for (i = 3; i * i <= n; i += 2) { // careful about overflow of i*i
        while (n % i == 0) {
            primeFactors.emplace_back(i);
            n /= i;
        }
    }
    if (n > 2) {
        primeFactors.emplace_back(n);
    }
}

/// using the concept of "prime factors comes in pairs"
void primeFactors(int n) {
    int i;
    int sqrt_n = floor(sqrt(n));
    for (i = 2; i < sqrt_n; i++) {
        if (n % i == 0) {
            primeFactors.emplace_back(i);
            primeFactors.emplace_back(n / i);
        }
    }
    if (n % sqrt_n == 0) primeFactors.emplace_back(sqrt_n);
}


/*********************************[USING SIEVE]**************************************/
/**
    for multiple queries
    O(n Log(Log(n))) for sieve
    O(Log(n)) printing prime factor
*/

const int Maxx = 1e6 + 10;

int smallestPrimeFactor[Maxx], primeFactor[Maxx], prefSum[Maxx];

void sieveSPF() {
    int i, j;
    for (i = 1; i <= Maxx; i++) smallestPrimeFactor[i] = i;

    int sqrtMaxx = ceil(sqrt(Maxx));
    for (i = 2; i <= sqrtMaxx; i++) {
        if (smallestPrimeFactor[i] == i) {
            for (j = i * i; j <= Maxx; j += i)
                if (smallestPrimeFactor[j] == j) smallestPrimeFactor[j] = i;
        }
    }
}

// printing prime factors of x
void primeFactors(int x) {
    vector<int> pf;
    while (x != 1) {
        primeFactor.emplace_back(smallestPrimeFactor[x]);
        x /= smallestPrimeFactor[x];
    }
    print(primeFactor);
}

// calculating number of prime factors of x
void precalc() {
    sieveSPF();
    int i;

    primeFactor[0] = primeFactor[1] = 0;
    for (i = 2; i < Maxx; i++)
        primeFactor[i] = primeFactor[i / smallestPrimeFactor[i]] + 1;

    // whien we need to calculate number of prime factors of n!
    for (i = 1; i < Maxx; i++)
        prefSum[i] = prefSum[i - 1] + primeFactor[i];
}





