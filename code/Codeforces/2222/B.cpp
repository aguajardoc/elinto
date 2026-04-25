// Problem: Artistic Balance Tree
// Contest: Codeforces
// URL: https://m1.codeforces.com/contest/2222/problem/B
// Memory Limit: 256 MB
// Time Limit: 1500 ms
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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> evens, odds, b(m);
    for (int i = 0; i < n; i++) {
    	int x;
    	cin >> x;
    	if (i % 2 == 0) {
    		evens.pb(x);
    	}
    	else {
    		odds.pb(x);
    	}
    }
    
    sort(evens.begin(), evens.end());
    sort(odds.begin(), odds.end());
    
    bool me = false, mo = false;
    
    for (int i = 0; i < m; i++) {
    	int y;
    	cin >> y;
    	y--;
    	
    	if (y % 2 == 0) {
    		if (!evens.empty() and evens.back() >= 0) {
    			evens.pop_back();
    		}
    		else {
    			if (!evens.empty() and !me) {
    				evens.pop_back();
    			} 
    		}
    		me = true;
    	}
    	else {
    		if (!odds.empty() and odds.back() >= 0) {
    			odds.pop_back();
    		}
    		else {
    			if (!odds.empty() and !mo) {
    				odds.pop_back();
    			} 
    		}
    		mo = true;
    	}
    }
    
    int ans = 0;
    for (auto& i : evens) ans += i;
    for (auto& i : odds) ans += i;
    
    cout << ans << ln;
}

signed main() {
    fast_cin();
    
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
