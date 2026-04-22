// Problem: E. Erasmus Valthron
// Contest: Codeforces - 2026 ICPC Gran Premio de Mexico 1ra Fecha
// URL: https://codeforces.com/gym/106495/problem/E
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
// #define int ll
#define ld long double
#define pb push_back

const ll INF = LLONG_MAX / 4;
const ld PI = acos(-1);
const int MOD = 1000000007;
const double eps = 1e-9;

vector<int> p;
bitset<1001> bs;

void sieve() {
	bs.set();
	bs[0] = bs[1] = false;
	
	for (int i = 2; i <= 1000; i++) {
		if (!bs[i]) continue;
		for (int j = i * i; j <= 1000; j += i) {
			bs[j] = false;
		}
		p.pb(i);
	}
}

void solve() {
    int n, q;
    cin >> n >> q;
    
    vector<pair<vector<int>, int>> ct(n + 1);
    for (int i = 1; i <= n; i++) {
    	int x = i;
    	ct[i].second = i;
    	for (int j = 0; j < p.size() and p[j] * p[j] <= x; j++) {
    		while (x % p[j] == 0) {
    			x /= p[j];
    			ct[i].first.pb(p[j]);
    		}
    	}
    	
    	if (x > 1) {
    		ct[i].first.pb(x);
    	}
    }
    
    sort(ct.begin(), ct.end());
    
    while(q--) {
    	int k;
    	cin >> k;
    	cout << ct[k].second << ln;
    }
}

signed main() {
    fast_cin();
    sieve();
    
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
