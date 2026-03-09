// Problem: E. Lomsat gelral
// Contest: Codeforces - Educational Codeforces Round 2
// URL: https://codeforces.com/contest/600/problem/E
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
vector<int> colors, ans;
vector<vector<int>> AL;
vector<map<int, int>> oppct, ct;

void dfs(int u, int p) {
	if (oppct[u].count(colors[u])) {
		ct[u][oppct[u][colors[u]]] -= colors[u];
		if (!ct[u][oppct[u][colors[u]]]) ct[u].erase(oppct[u][colors[u]]);
		oppct[u][colors[u]]++;
		ct[u][oppct[u][colors[u]]] += colors[u];
	}
	else {
		oppct[u][colors[u]]++;
		ct[u][oppct[u][colors[u]]] += colors[u];
	}
	
	for (auto& v : AL[u]) {
		if (v == p) continue;
		
		dfs(v, u);
		
		// Merge v's maps onto mine
		map<int, int>& ctu = ct[u];
		map<int, int>& oppctu = oppct[u];
		map<int, int>& ctv = ct[v];
		map<int, int>& oppctv = oppct[v];
		
		// trickkkkkkkkkkkk
		if (ctu.size() + oppctu.size() < ctv.size() + oppctv.size()) {
			swap(ctu, ctv);
			swap(oppctu, oppctv);
		}
		
		// dbg(u);
		// dbg(ctu.rbegin()->second);
		// dbg(ctv.rbegin()->second);
		// dbg(v);
		
		for (auto& k : oppctv) {
			int newCount = k.second + oppctu[k.first];
			
			// dbg(k.first);
			// dbg(k.second);
			// dbg(oppctu[k.first]);
			// dbg(newCount);
			// dbg(ctu[1]);
			
			// Update counts
			ctu[oppctu[k.first]] -= k.first;
			if (!ctu[oppctu[k.first]]) ctu.erase(oppctu[k.first]);
			oppctu[k.first] = newCount;
			ctu[oppctu[k.first]] += k.first;
			
			// dbg(oppctu[k.first]);
			// dbg(ctu[oppctu[k.first]]);
		}
		
		// dbg(ctu.rbegin()->second);
		// dbg(ctv.rbegin()->second);
		// cout << ln;
	}
	
	ans[u] = ct[u].rbegin()->second;
}

void solve() {
    int n;
    cin >> n;
    colors.assign(n, 0);
    AL.assign(n, vector<int> ());
    ans.assign(n, 0);
    ct.assign(n, map<int, int>());
    oppct.assign(n, map<int, int>());
    
    for (auto& i : colors) cin >> i;
    
    for (int i = 1; i < n; i++) {
    	int u, v;
    	cin >> u >> v;
    	u--, v--;
    	AL[u].pb(v);
    	AL[v].pb(u);
    }
    
    dfs(0, -1);
    
    for (auto& i : ans) {
    	cout << i << " ";
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
