/**
        দশমিক মুলদ(rational) সংখ্যাকে p/q আকারে আনা
*/
void convertRationalNum(string num, int &p, int &q)
{
    bool dot = 0;
    p = 0; q = 1;
    for(int i = 0; i < sz(num); i++) {
        if(num[i] == '.') {
            dot = 1;
            continue;
        }
        p = p*10 + (num[i]-48);
        if(dot) q *= 10;
    }
    int g = gcd(p, q);
//    as p and q are coprime
    p /= g;
    q /= g;
}



/**
    finding decimal digit in rational number p/q
    or p/q থেকে দশমিকে নেওয়া
*/
bool findDigit(int p, int q, int c)
{
    for(int i = 0; i < q; i++) {    // its q because of pigeonhole principle
        p *= 10;
        if((p/q)%10 == c) {
            return 1;
        }
        p %= q;
    }
    return 0;
}
