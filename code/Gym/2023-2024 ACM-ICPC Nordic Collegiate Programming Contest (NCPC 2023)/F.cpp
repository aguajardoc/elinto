// Problem: F. Factor-Full Tree
// Contest: Codeforces - 2023-2024 ACM-ICPC Nordic Collegiate Programming Contest (NCPC 2023)
// URL: https://codeforces.com/gym/105427/problem/F
// Memory Limit: 512 MB
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
vector<vector<pair<int, int>>> ANAL;
vector<ll> ans, P;
vector<ll> mp(67, 0);
int n;

int dfs_depth(int u, int p) {
	
	int mx = 0;
	for (auto& v : AL[u]) {
		if (v == p) continue;
		
		int d = dfs_depth(v, u) + 1;	
		mx = max(mx, d);
		
		ANAL[u].pb({d, v});
	}
	
	return mx;
}

int vp(ll a, ll p){
	int ret = 0;
	while(a%p == 0){
		ret++;
		a/=p;
	}
	return ret;
}

void dfs_mp(int u, int p, int idx) {
	
	ans[u] = ans[p];
	
	int pot = 0;
	for(int i = 0; i<n; i++){
		if(ans[i]%ans[p] == 0){
			pot = max(pot, vp(ans[i]/ans[p], P[idx]));
		}
	}
	// while (ans[u] % P[idx] == 0) {
		// ans[u] /= P[idx];
	// }
	
	for (int i = 0; i < pot+1; i++) {
		ans[u] *= P[idx];
	}
	
	
	// for (int i = 0; i < 67; i++) {
		// int loc = 1;
		// for (int j = 0; j < mp[i]; j++) {
			// loc *= p[i];
		// }
		// ans[u] *= loc;
	// }
	
	//mp[idx]++;

	for (int v = 0; v < ANAL[u].size(); v++) {
		// papa, excepto que cambias el idx del # hijo
		dfs_mp(ANAL[u][v].second, u, v + idx);
	}
}

void solve() {
	cin >> n;  
	AL.resize(n);
	ANAL.resize(n);
	ans.assign(n, 1);
	
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		AL[u].pb(v);
		AL[v].pb(u);
	}
	
	dfs_depth(0, -1);
	
	for (auto& u : ANAL) {
		sort(u.rbegin(), u.rend());
	}
	
	dfs_mp(0, 0, 0);
	
	for (auto& i : ans) {
		cout << i/2 << " ";
	}
	cout << ln;
}

signed main() {
    fast_cin();
    
    for (int i = 2; P.size() <= 67; i++) {
    	bool prime = true;
    	for (int j = 2; j * j <= i; j++) {
    		if (i % j == 0) prime = false;
    	}
    	
    	if (prime) P.pb(i);
    }
    
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
