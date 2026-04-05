// Problem: H. Huron Designs
// Contest: Codeforces - 2025 ICPC Gran Premio de Mexico 1ra Fecha
// URL: https://codeforces.com/gym/105873/problem/H
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

struct Item {
	int d, p, c, lx, rx, ly, ry;
};

ld get_expected_value(int mask, int new_item, vector<Item>& items) {
	int n = items.size();
	// Get time
	int time_elapsed = 0;
	for (int i = 0; i < n; i++) {
		if (mask & (1ll << i)) {
			time_elapsed += items[i].c;
		}
	}
	
	Item& cur = items[new_item];
	time_elapsed += cur.c;
	
	// If can't add or no extra profit then we are done here
	if (time_elapsed > cur.d) return 0;
	if (time_elapsed > cur.ry) return cur.p;
	
	// Now we can do the fun part :)
	ld T1 = (cur.rx * (cur.rx + 1)) / 2 - (cur.lx * (cur.lx - 1)) / 2;
	ld T2 = cur.rx - cur.lx + 1;
	ld T3 = cur.ry - max(cur.ly, time_elapsed);
	ld T4 = cur.ry - cur.ly;
	
	if (cur.ly == cur.ry) {
		T3 = 1, T4 = 1;
	}
	
	ld EV = cur.p + (T1 / T2) * (T3 / T4);
	
	return EV;
}

void solve() {
    int n;
    cin >> n;
    
    vector<ld> dp(1ll << n, 0);
  	vector<Item> items(n);
  	for (int i = 0; i < n; i++) {
  		cin >> items[i].d >> items[i].p >> items[i].c >> items[i].lx >> items[i].rx >> items[i].ly >> items[i].ry;
  	}
    
    ld ans = 0;
    for (int i = 1; i < (1ll << n); i++) {
    	
    	for (int j = 0; j < n; j++) {
    		if (i & (1ll << j)) {
    			int mask = (i ^ (1ll << j));
    			
    			ld EV = get_expected_value(mask, j, items);
    			
    			dp[i] = max(dp[i], dp[mask] + EV);
    			
    			ans = max(ans, dp[i]);
    		}
    	}
    	
    }
    
    cout << fixed << setprecision(10) << ans << ln;
}

signed main() {
    fast_cin();
    
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
