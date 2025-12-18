// Problem: C. Biathlon
// Contest: Codeforces - Codeforces Beta Round 72 (Div. 2 Only)
// URL: https://codeforces.com/contest/84/problem/C
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

struct Target {
	int L, R, idx;
	bool operator <(const Target& other) const {
		return (L < other.L);
	}
};

void solve() {
    int n;
    cin >> n;
    vector<Target> ranges(n);
    for (int i = 0; i < n; i++) {
    	int l, r;
    	cin >> l >> r;
    	ranges[i] = {l - r, l + r, i};
    }
    sort(ranges.begin(), ranges.end());
    // for (auto& i : ranges) {
    	// cout << i.L << " " << i.R << ln;
    // }
    
    int m;
    cin >> m;
    vector<int> ans(n, -1);
    int hit = 0;
    for (int i = 0; i < m; i++) {
    	int x, y;
    	cin >> x >> y;
    	Target bet = {x, -1, -1};
    	auto it = upper_bound(ranges.begin(), ranges.end(), bet);
    	if (it == ranges.begin()) continue;
    	
    	it--;
    	// verify
    	Target gotcha = *it;
    	int radius = (gotcha.R - gotcha.L) / 2;
    	int center = gotcha.L + radius;
    	int md = ((x - center) * (x - center) + y * y);
    	// dbg(x, y, gotcha.L, gotcha.R, radius, md);
    	if (gotcha.L <= x and gotcha.R >= x and md <= radius * radius) {
    		if (ans[gotcha.idx] == -1) {
    			ans[gotcha.idx] = i + 1;
    			hit++;
    		}
    	}
    	
    	if (it == ranges.begin()) continue;
    	
    	it--;
    	// verify
		gotcha = *it;
    	radius = (gotcha.R - gotcha.L) / 2;
    	center = gotcha.L + radius;
    	md = ((x - center) * (x - center) + y * y);
    	if (gotcha.L <= x and gotcha.R >= x and md <= radius * radius) {
    		if (ans[gotcha.idx] == -1) {
    			ans[gotcha.idx] = i + 1;
    			hit++;
    		}
    	}
    }
    
    
    cout << hit << ln;
    for (auto& i : ans) {
    	cout << i << " ";
    }
    cout << ln;
    
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
