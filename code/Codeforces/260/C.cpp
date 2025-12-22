// Problem: C. Balls and Boxes
// Contest: Codeforces - Codeforces Round 158 (Div. 2)
// URL: https://codeforces.com/contest/260/problem/C
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

ll getBalls(ll x, ll i, ll n, ll ai) {
	return ((x - i) + n) % n + n * ai;
}

void solve() {
    ll n, x;
    cin >> n >> x;
    x--;
    vector<int> a(n), turns(n);
    for (auto& i : a) cin >> i;
    ll mt = 1e11;
    ll idx = -1;
    for (int i = 0; i < n; i++) {
    	ll turns = getBalls(x, i, n, a[i]);
    	if (turns < mt) {
    		mt = turns;
    		idx = i;
    	}
    	// dbg(i, turns);
    }
    
    ll ogmt =  mt;
    
    for (ll i = idx + 1; mt and i <= (x + n); i++) {
    	a[i % n]--;
    	mt--;
    	
    	// dbg(i % n, mt);
    	if (i % n == x) break;
    }
    
    for (ll i = 0; i < n; i++) {
    	a[i] -= mt / n;
    }
    
    a[idx] = ogmt;
    
    for (auto& i : a) {
    	cout << i << " ";
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
