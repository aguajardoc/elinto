// Problem: Modular GCD
// Contest: CodeChef - AUG18
// URL: https://www.codechef.com/problems/GCDMOD
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

const ll INF = LLONG_MAX / 4;
const ld PI = acos(-1);
const int MOD = 1000000007;
const double eps = 1e-9;

bitset<1000001> bs;
vector<int> p;

void sieve() {
	bs.set();
	bs[0] = bs[1] = false;
	for (int i = 2; i <= 1000000; i++) {
		if (!bs[i]) continue;
		for (int j = i * i; j <= 1000000; j+=i) {
			bs[j] = false;
		}
		p.pb(i);
	}
}

map<int, int> getPfac(int x) {
	map<int, int> res;
	for (int i = 0; i < p.size() and p[i] * p[i] <= x; i++) {
		bool flag = false;
		while (x % p[i] == 0) {
			x /= p[i];
			res[p[i]]++;
		}
		
	}
	
	if (x > 1) res[x]++;
	
	return res;
}

ll binexp(ll a, ll b, ll m)  {
	ll res = 1;
	while(b) {
		if (b&1) {
			res = (a * res) % m;
		}
		a = (a*a)%m;
		b >>= 1;
	}
	
	return res;
}

void solve() {
    int A, B, N;
    cin >> A >> B >> N;
    
    if (A == B) {
    	int amod = binexp(A%MOD, N, MOD);
    	int bmod = binexp(B%MOD, N, MOD);
    	int sum = amod + bmod;
    	sum %= MOD;
    	
    	cout << sum << ln;
    	return;
    }
    
    int K = abs(A - B);
    map<int, int> facsK = getPfac(K);
    int ans = 1;
    
    for (auto& i : facsK) {
    	// Get sum mod i
    	int cur = i.first;
    	int last = 1;
    	for (int j = 1; j <= i.second; j++, cur *= i.first) {
	    	int amod = binexp(A%cur, N, cur);
	    	int bmod = binexp(B%cur, N, cur);
	    	int sum = amod + bmod;
	    	sum %= cur;
	    	
	    	if (sum == 0) {
	    		last = cur;
	    	}
    	}
    	
		ans *= last;
		ans %= MOD;
		// dbg(i.first, i.second, cur);
    	// dbg(i, amod, bmod, sum);
    }
    
    cout << ans << ln;
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
