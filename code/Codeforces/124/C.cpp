// Problem: C. Prime Permutation
// Contest: Codeforces - Codeforces Beta Round 92 (Div. 2 Only)
// URL: https://codeforces.com/contest/124/problem/C
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

bitset<1001> bs;
vector<int> p;

void sieve() {
	bs.set();
	bs[0] = bs[1] = false;
	
	for (int i = 2; i <= 1000; i++) {
		if (!bs[i]) continue;
		for (int j = i * i; j <= 1000; j+=i) {
			bs[j] = false;
		}
		p.push_back(i);
	}
}

vector<int> getFac(int x) {
	vector<int> r;
	for (int i = 0; i < p.size() and p[i] * p[i] <= x; i++) {
		while (x % p[i] == 0) {
			if (r.empty() or r.back() != p[i]) r.pb(p[i]);
			x /= p[i];
		}
	}
	if (x > 1) r.pb(x);
	return r;
}

vector<set<int>> DSU;
vector<int> visited(1001, 0);
vector<vector<int>> AL(1001);

void dfs(int u, int& idx) {
	visited[u] = true;
	DSU[idx].insert(u);
	
	for (auto& v : AL[u]) {
		if (visited[v]) continue;
		dfs(v, idx);
	}
}

void solve() {
    // for every prime, mark all positions with a color
    // if we find a color, then all of the positions at all
    // indices prime factors must have it
    
    // for each prime, get all pfs of the involved nums
    // dsu ah, like actually
    string s;
    cin >> s;
    int n = s.length();
    
    for (int i = 0; i < p.size(); i++) {
    	for (int j = 1; p[i] * j <= n; j++) {
    		int idx = p[i] * j;
    		
    		vector<int> pfac = getFac(idx);
    		for (auto& k : pfac) {
    			AL[k].pb(idx);
    			AL[idx].pb(k);
    		}
    	}
    }
    
    int idx = 0;
    for (int i = 2; i <= n; i++) {
    	if (!visited[i]) {
    		DSU.pb(set<int>());
    		dfs(i, idx);
    		idx++;
    	}
    }
    
    map<char, int> ct;
    for (auto& i : s) {
    	ct[i]++;
    }
    
    vector<char> ans(n, '$');
    
    for (auto& i : DSU) {
    	int sz = i.size();
    	
    	bool poss = false;
    	char goat;
    	for (auto& j : ct) {
    		if (j.second >= sz) {
    			poss = true;
    			goat = j.first;
    		}
    	}
    	
    	if (!poss) {
    		cout << "NO" << ln;
    		return;
    	}
    	
    	for (auto& j : i) {
    		ans[j - 1] = goat;
    		ct[goat]--;
    	}
    }
    
    cout << "YES" << ln;
    for (int i = 0; i < n; i++) {
    	if (ans[i] == '$') {
    		for (auto& j : ct) {
    			if (j.second > 0) {
    				ans[i] = j.first;
    				j.second--;
    				break;
    			}
    		}
    	}
    	cout << ans[i];
    }
    cout << ln;
}

signed main() {
    fast_cin();
    sieve();
    
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
