// Problem: L. Valid BFS?
// Contest: Codeforces - TC Tec 2026 Contest 4 (Avanzado)
// URL: https://codeforces.com/group/eZBA1VtmXM/contest/691247/problem/L
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

void solve() {
    int n;
    cin >> n;
    vector<set<int>> AL(n);
    
    for (int i = 1; i < n; i++) {
    	int u, v;
    	cin >> u >> v;
    	u--, v--;
    	AL[u].insert(v);
    	AL[v].insert(u);	
    }
    vector<int> a(n);
    for (auto& i : a) cin >> i;
    for (auto& i : a) i--;
    
    if (a[0] != 0) {
    	cout << "No" << ln;
    	return;
    }
    
    int idx = 1;
    queue<int> q;
    q.push(0);
    bool poss = true;
    vector<int> visited(n, 0);
    visited[0] = 1;
    
    while (!q.empty() and poss) {
    	int u = q.front();
    	q.pop();
    	
    	int x = (int)AL[u].size() - 1 + (u == 0);
    	for (int i = 0; i < x; i++) {
    		if (AL[u].count(a[idx])) {
    			q.push(a[idx++]);
    		}
    		else {
    			poss = false;
    			break;
    		}
    	}
    }
    
    
    cout << (poss ? "Yes":"No") << ln;
    
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
