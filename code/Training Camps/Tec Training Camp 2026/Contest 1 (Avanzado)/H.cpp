// Problem: H. Git Gud
// Contest: Codeforces - TC Tec 2026 Contest 1 (Avanzado)
// URL: https://codeforces.com/group/eZBA1VtmXM/contest/690676/problem/H
// Memory Limit: 1024 MB
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
// #define int ll
#define ld long double
#define pb push_back

const ll INF = LLONG_MAX / 4;
const ld PI = acos(-1);
const int MOD = 1000000007;
const double eps = 1e-9;

void solve() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> ops;
    int sol = 0;

    for (int M = 63, x = 0; x < 3; M *= 63, x++) {
	    vector<vector<int>> buckets(63);
	    for (int i = M/63; i <= 250000; i+=M/63) {
	    	int p = i / (M/63);
	    	p %= 63;
	    	buckets[p].pb(i);
	    }
	    
	    for (int i = 1; i < 63; i++) {
	    	sort(buckets[i].rbegin(), buckets[i].rend());
	    	for (auto& j : buckets[i]) {
	    		ops.pb({j, M/63});
	    		sol += M/63;
	    	}
	    }
    }
    
    sol += 3 * 1000 * 61;
    sol += 2000;
    // dbg(sol);
    
    cout << ops.size() << ln;
    for (auto& [y, l] : ops) {
    	cout << y << " " << l << ln;
    }
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
