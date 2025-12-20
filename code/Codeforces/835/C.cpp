// Problem: C. Star sky
// Contest: Codeforces - Codeforces Round 427 (Div. 2)
// URL: https://codeforces.com/contest/835/problem/C
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
#define INF 2e18
#define PI 3.14159265358979323846
#define MOD 1000000007

double eps = 1e-9;
struct Star {
	ll x, y, s;
};
ll brightness[11][102][102];

void solve() {
    ll n, q, c;
    cin >> n >> q >> c;
    
    for (auto& i : brightness) for (auto& j : i) for (auto& k : j) k = 0;
    
    vector<map<ll, vector<ll>>> starMap(c + 1);
    vector<Star> stars;

    for (int i = 0; i < n; i++) {
    	ll x, y, s;
    	cin >> x >> y >> s;
    	stars.push_back({x, y, s});
    	
    	for (int t = 0; t <= c; t++) {
    		brightness[t][x][y] += (s + t) % (c + 1);
    	}
    }
    
    for (int i = 0; i <= 100; i++) {
    	for (int j = 0; j <= c; j++) {
    		starMap[j][i] = vector<ll> (102, 0);
    	}
    }
    
    for (int t = 0; t <= c; t++) {
    	for (int x = 0; x <= 100; x++) {
    		for (int y = 0; y <= 100; y++) {
    			starMap[t][x][y + 1] = starMap[t][x][y] + brightness[t][x][y];
    		}
    	}
    }
    
    while (q--) {
    	ll t, x1, y1, x2, y2;
    	cin >> t >> x1 >> y1 >> x2 >> y2;
    	t %= (c + 1);
    	ll res = 0;
    	
    	for (int x = x1; x <= x2; x++) {
    		res += starMap[t][x][y2 + 1] - starMap[t][x][y1];
    	}
    	
    	cout << res << ln;
    }
}

signed main() {
    fast_cin();
    
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
