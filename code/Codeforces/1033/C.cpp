// Problem: C. Permutation Game
// Contest: Codeforces - Lyft Level 5 Challenge 2018 - Elimination Round
// URL: https://codeforces.com/contest/1033/problem/C
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

vector<vector<int>> AL;
vector<int> moves;
vector<int> visited;

void dfs(int u) {
	visited[u] = true;
	
	int m = 0;
	for (auto& v : AL[u]) {
		if (visited[v]) {
			if (m % 2 == 0 and moves[v] % 2 == 0) {
				m = moves[v] + 1;
			}
			else if (m == 0) {
				m = moves[v] + 1;
			}
			continue;
		}
		
		dfs(v);
	}
	
	moves[u] = m;
} 

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i : a) {
    	cin >> i;
    	i--;
    }
    
    AL.assign(n, vector<int>());
    visited.assign(n, 0);
    moves.assign(n, -1);
    
    for (int i = 0; i < n; i++) {
    	for (int j = i + a[i] + 1; j < n; j += a[i] + 1) {
    		if (a[j] > a[i]) {
    			AL[a[i]].pb(a[j]);
    		}
    	}
    	for (int j = i - a[i] - 1; j >= 0; j -= a[i] + 1) {
    		if (a[j] > a[i]) {
    			AL[a[i]].pb(a[j]);
    		}
    	}
    }
    
    for (int i = n - 1; i >= 0; i--) {
    	dfs(i);
    }
    
    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++) {
    	ans[i] = (moves[a[i]] % 2);
    	// dbg(a[i], moves[a[i]]);
    }
    	
    for (auto& i : ans) {
    	if (i % 2) {
    		cout << "A";
    	}
    	else cout << "B";
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
