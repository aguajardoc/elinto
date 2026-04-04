// Problem: The 67th OEIS Problem
// Contest: Codeforces
// URL: https://m1.codeforces.com/contest/2218/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

#define ln "\n"
#define fast_cin() \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define iofiles() \
    freopen("input.in", "r", stdin); \
    freopen("output.out", "w", stdout)
#define dbg(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1) { cout << name << ": " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args) {
    const char *comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << ": " << arg1 << " |";
    __f(comma + 1, args...);
}

#define ll long long
#define int ll
#define ld long double
#define pb push_back

const ll INF = LLONG_MAX / 4;
const ld PI = acos(-1);
const int MOD = 1000000007;
const double eps = 1e-9;

// Usage: sieve(); p -> list of primes up to N
const int N = 100000;
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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    int cur = 1;
    a[0] = 1;
    int cp = 0;
    int trig = 0;
    set<int> x;
    for (int i = 1; i < n; i++) {
    	if (trig == 1) {
    		cur = gcd(cur, p[cp-1]);
    		trig = 2;
    	}
    	else if (trig == 2) {
    		cur /= p[cp-1];
    		trig = 0;
    	}
    	if (cur * p[cp] * p[cp+1] <= 1e14) {
    		cur *= p[cp];
    	}
    	else {
    		cur *= p[cp];
    		cur *= p[cp+1];
    		cp++;
    		trig = 1;
    	}
    	
    	a[i] = cur;
    	// if (!x.insert(gcd(a[i-1], a[i])).second) {
    		// dbg(cur);
    		// dbg(gcd(a[i-1], a[i]));
    	// }
    }
    
    for (auto& i : a) {
    	cout << i << " ";
    }
    cout << ln;
}

signed main() {
    fast_cin();
    sieve();
    
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
