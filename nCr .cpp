/*
    calcuate upto MAX = 10^4
    using precalculation
*/
int C[MAX][MAX];
void precal()
{
    C[0][0] = 1;
    for (int i = 1; i < MAX; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || i == j) C[i][j] = 1;
            else C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    }
}

/*
    calcuate upto n = 10^18
*/
int ncr(int n, int r)
{
    int ans = 1;
    r = min(r, n-r);
    for (int i = 0; i < r; i++) {
        ans = ans*(n-i)/(i+1);
    }
    return ans;
}


/*
    calculating nCr using factorial
    claculate upto N = 10^8
    useing precalculation
*/
int fact[N], invfact[N];

int pow(int a, int b, int m)
{
	int ans=1;
	while(b)
	{
		if(b&1) ans = (ans*a)%m;
		a=(a*a)%m;
		b /= 2;
	}
	return ans;
}

int modinv(int k)
{
	return pow(k, MOD-2, MOD);
}

void precompute()
{
	fact[0]=fact[1]=1;
	for(int i=2;i<N;i++)
	{
		fact[i]=fact[i-1]*i;
		fact[i]%=MOD;
	}
	invfact[N-1]=modinv(fact[N-1]);
	for(int i=N-2;i>=0;i--)
	{
		invfact[i]=invfact[i+1]*(i+1);
		invfact[i]%=MOD;
	}
}

int nCr(int x, int y)
{
	if(y>x)
		return 0;
	int num=fact[x];
	num*=invfact[y];
	num%=MOD;
	num*=invfact[x-y];
	num%=MOD;
	return num;
}
