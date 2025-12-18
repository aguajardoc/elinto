// Problem: D. Dima and Lisa
// Contest: Codeforces - Codeforces Round 324 (Div. 2)
// URL: https://codeforces.com/contest/584/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
#define INF 2e18
#define PI 3.14159265358979323846
#define MOD 1000000007

double eps = 1e-9;

bitset<100001> bs;
vector<int> p;

void sieve() {
	bs.set();
	bs[0] = bs[1] = false;
	
	for (ll i = 2; i <= 100000; i++) {
		if (!bs[i]) continue;
		for (ll j = i * i ; j <= 100000; j+=i) {
			bs[j] = false;
		}
		p.push_back(i);
	}
}

bool isPrime(ll x) {
	for (int i = 0; i < p.size() and p[i] * p[i] <= x; i++) {
		if (x % p[i] == 0) {
			return false;
		}
	}
	
	return true;
}

void solve() {
    ll n;
    cin >> n;
    
    // check if 1 prime
    if (isPrime(n)) {
    	cout << 1 << ln << n << ln;
    	return;
    }
    
    // check if 2 primes 
    if (isPrime(n - 2)) {
    	cout << 2 << ln << 2 << " " << n - 2 << ln;
    	return;
    }
    
    // check if 3 primes
    // find closest
    int best;
    for (int i = n - 4; i >= 0; i--) {
    	if (isPrime(i)) {
    		best = i;
    		break;
    	}
    }
    
    // bruteforce the rest
    for (int a = 0; a <= 500; a++) {
    	for (int b = a; b <= 500; b++) {
    		if (p[a] + p[b] + best == n) {
    			cout << 3 << ln << p[a] << " " << p[b] << " " << best << ln;
    			return;
    		}
    	}
    }
}

signed main() {
    fast_cin();
    sieve();
    
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
