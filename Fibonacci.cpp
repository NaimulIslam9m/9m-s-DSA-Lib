/********************************************[Binet's Formula]************************************************/
/**
    Using Golden Ratio
    finding fibonacci number in O(1)
*/
int fibo(int n) // fibo(0) = 0
{
    double phi = (1 + sqrt(5)) / 2; // golden ration
    return round(pow(phi, n) / sqrt(5));
}

/********************************************[Matrix Multiplication]*****************************************/
/**
    O(log(p))
*/

void matrixMul(int64_t x[2][2], int64_t y[2][2]) {
    int64_t a = x[0][0] * y[0][0] % MOD + x[0][1] * y[1][0] % MOD;
    int64_t b = x[0][0] * y[0][1] % MOD + x[0][1] * y[1][1] % MOD;
    int64_t c = x[1][0] * y[0][0] % MOD + x[1][1] * y[1][0] % MOD;
    int64_t d = x[1][0] * y[0][1] % MOD + x[1][1] * y[1][1] % MOD;

    x[0][0] = a % MOD, x[0][1] = b % MOD;
    x[1][0] = c % MOD, x[1][1] = d % MOD;
}

int64_t pow_n(int64_t b[2][2], int64_t p) {
    int64_t ans[2][2] = {{1, 0}, {0, 1}}; // identity matrix

    while (p > 0) {
        if (p & 1)
            matrixMul(ans, b);
        matrixMul(b, b);
        p >>= 1;
    }

    return ans[0][0] % MOD;
}

int64_t fibo(int64_t n) {
    if (n == 0 || n == 1)
        return n;

    int64_t F[2][2] = {{1, 1}, {1, 0}};

    return pow_n(F, n - 1);
}