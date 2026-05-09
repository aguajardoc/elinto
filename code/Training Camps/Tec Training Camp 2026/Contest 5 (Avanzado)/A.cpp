// Problem: A. Arpa and a game with Mojtaba
// Contest: Codeforces - TC Tec 2026 Contest 5 (Avanzado)
// URL: https://codeforces.com/group/eZBA1VtmXM/contest/691508/problem/A
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

bitset<100001> bs;
vector<int> p;

void sieve() {
	bs.set();
	bs[0] = bs[1] = false;
	for (ll i = 2; i <= 100000; i++) {
		if (!bs[i]) continue;
		for (ll j = i * i; j <= 100000; j += i) {
			bs[j] = false;
		}
		
		p.pb(i);
	}
}

map<int, int> dp;

int getNimber(int u) {
	if (u == 0) {
		return 0;
	}
	
	if (dp.count(u)) return dp[u];
	
	bool on = false;
	set<int> nimbers;
	// dbg(u);
	for (int i = 30; i >= 0; i--) {
		if (!on and !(u & (1ll << i))) continue;
		on = true;
		
		int v = u;
		for (int j = i; j <= 30; j++) {
			// dbg(u, j, v);
			v &= ~(1ll << j);
			if (j > i and u & (1ll << j)) {
				v |= (1ll << (j - i - 1));
			}
		}
		
		if (u != v) {
			int x = getNimber(v);
			nimbers.insert(x);
			// dbg(u, v, i);
			// dbg(x);
			// cout << ln;
		}
	}
	
	int mex = 0;
	for (auto& i : nimbers) {
		if (i != mex) break;
		mex++;
	}
	
	return dp[u] = mex;
}

void solve() {
    int n;
    cin >> n;
    map<int, int> pows;
    for (int i = 0; i < n; i++) {
    	int x;
    	cin >> x;
    	
    	for (int j = 0; j < p.size() and p[j] * p[j] <= x; j++) {
    		int ct = 0;
    		while (x % p[j] == 0) {
    			x /= p[j];
    			ct++;
    		}
    		
    		if (ct) pows[p[j]] |= (1ll << (ct - 1));
    	}
    	
    	if (x > 1) {
    		pows[x] |= (1ll << 0);
    	}
    }
    
    int ans = 0;
    for (auto& i : pows) {
    	// dbg(i.first);
    	// dbg(i.second);
    	// cout << ln;
    	ans ^= getNimber(i.second);
    	
    	// dbg(getNimber(i.second));
    }
    
    cout << (ans ? "Mojtaba":"Arpa") << ln;
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
