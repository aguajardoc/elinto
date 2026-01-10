// Usage: sieve(); p -> list of primes up to N
const int N = 10000000;
bitset<N + 1> bs;
vector<int> p;

void sieve() {
    bs.set();
    bs[0] = bs[1] = false;

    for (long long i = 2; i <= N; i++) {
        if (!bs[i]) continue;
        for (long long j = i * i; j <= N; j += i) bs[j] = false;
        p.push_back(i);
    }
}