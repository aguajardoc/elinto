// Usage: a^b % m
long long binexp(long long a, long long b, long long m = 1000000007) {
    long long res = 1;
    while (b) {
        if (b & 1) {
            res = (res * a) % m;
        }

        a = (a * a) % m;
        b >>= 1;
    }

    return res;
}