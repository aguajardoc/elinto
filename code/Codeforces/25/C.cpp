// Problem: C. Roads in Berland
// Contest: Codeforces - Codeforces Beta Round 25 (Div. 2 Only)
// URL: https://codeforces.com/contest/25/problem/C
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

const ll INF = LLONG_MAX / 4;
const ld PI = acos(-1);
const int MOD = 1000000007;
const double eps = 1e-9;

int FW(vector<vector<int>>& AM, vector<int> changes) {
	int n = AM.size();
	
	for (auto& k : changes) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				AM[i][j] = min(AM[i][j], AM[i][k] + AM[k][j]);
			}
		}
	}
	
	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			res += AM[i][j];
		}
	}
	res/=2;
	
	return res;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> AM(n, vector<int> (n, 0));
    for (auto& i : AM) for (auto& j : i) cin >> j;
    vector<int> d(n);
    iota(d.begin(), d.end(), 0);
    FW(AM, d);
    
    int q;
    
    cin >> q;
    while(q--) {
    	int u, v, w;
    	cin >> u >> v >> w;
    	u--, v--;
    	AM[u][v] = min(AM[u][v], w);
    	AM[v][u] = min(AM[v][u], w);
    	
    	vector<int> altered = {u, v};
    	int x = FW(AM, altered);
    	
    	cout << x << " ";
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
