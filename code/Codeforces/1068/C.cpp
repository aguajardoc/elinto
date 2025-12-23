// Problem: C. Colored Rooks
// Contest: Codeforces - Codeforces Round 518 (Div. 2) [Thanks, Mail.Ru!]
// URL: https://codeforces.com/contest/1068/problem/C
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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> cells(101), ans(101);
    
    for (int i = 0; i < m;i++) {
    	int u, v;
    	cin >> u >> v;
    	if (u > v) swap(u, v);
    	
    	cells[u].push_back({u, v});
    }
    
    int offset = 1;
    
    for (int i = 1; i <= n; i++) {
    	for (int j = 0; j <= cells[i].size(); j++) {
    		ans[i].push_back({i, j + offset});
    	}
    	for (int j = 0; j < cells[i].size(); j++) {
    		ans[cells[i][j].second].push_back({cells[i][j].second, j + offset + 1});
    	}
    	offset += cells[i].size() + 1;
    }
    
	for (int i = 1; i <= n; i++) {
    	cout << ans[i].size() << ln;
    	for (auto& [u, v] : ans[i]) {
    		cout << u << " "<< v << ln;
    	}
    }
    cout << ln;
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
