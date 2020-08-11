/********************************************[Binet's Formula]************************************************/
/**
    Using Golden Ratio
    finding fibonacci number in O(1)
*/
int fib(int n) // started from 0
{
    double phi = (1 + sqrt(5)) / 2;   // golden ration
    return round(pow(phi, n) / sqrt(5));
}



/********************************************[Matrix Multiplication]*****************************************/
/**
    O(log(p))
*/

void matrixMul(int x[2][2], int y[2][2])
{
    int a = x[0][0]*y[0][0] + x[0][1]*y[1][0];
    int b = x[0][0]*y[0][1] + x[0][1]*y[1][1];
    int c = x[1][0]*y[0][0] + x[1][1]*y[1][0];
    int d = x[1][0]*y[0][1] + x[1][1]*y[1][1];

    x[0][0] = a%Mod, x[0][1] = b%Mod;
    x[1][0] = c%Mod, x[1][1] = d%Mod;
}

int fastExp(int b[2][2], int p)
{
    int ans[2][2] = {{1, 0}, {0, 1}}; // identity matrix

    while (p) {
        if (p&1) matrixMul(ans, b);
        matrixMul(b, b);
        p >>= 1;
    }

    return ans[0][0]%Mod;
}

int fibo(int n)
{
    if (n == 0 || n == 1) return n;

    int F[2][2] = {{1, 1}, {1, 0}};

    return fastExp(F, n-1);
}
