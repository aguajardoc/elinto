// Problem: E. Segments Removal
// Contest: Codeforces - Codeforces Round 452 (Div. 2)
// URL: https://codeforces.com/problemset/problem/899/E
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

map<int, map<int, int>> freq;
map<int, pair<int, int>> adj;

void init(vector<pair<int, int>>& p) {
	int n = p.size();
	for (int i = 0; i < n; i++) {
		freq[p[i].second][i] = p[i].first;
		adj[i] = {i - 1, i + 1};
		if (i + 1 == n) adj[i].second = -1;
	}
}

pair<int, int> query() {
	auto& vmap = freq.rbegin()->second;
	int index = vmap.begin()->first;
	int val = vmap.begin()->second;
	
	return {index, val};
}

void remove(int idx, int left, int right) {
	int lg = freq.rbegin()->first;
	auto& vmap = freq.rbegin()->second;
	vmap.erase(idx);
	if (vmap.empty()) freq.erase(lg);
	
	if (left != -1) adj[left].second = right;
	if (right != -1) adj[right].first = left;
}

void solve() {
    int n;
    cin >> n;
    int cur = -1;
    vector<pair<int, int>> p;
    for (int i = 0; i < n; i++) {
    	int x;
    	cin >> x;
    	
    	if (cur != x) {
    		p.pb({x, 1});
    		cur = x;
    	}
    	else {
    		p.back().second++;
    	}
    }
    
    int ans = 0;
    init(p);

    
    while (!freq.empty()) {
    	auto [index, val] = query();
    	
    	// Initial removal
    	int left = adj[index].first;
    	int right = adj[index].second;
    	
    	remove(index, left, right);
    	ans++;
    	
    	if (left == -1 or right == -1) continue;
    	
    	// If same, also remove
    	int vleft = p[left].first;
    	int vright = p[right].first;
    	
    	
    	if (vleft == vright) {
    		remove(right, left, adj[right].second);
    		
    		int curleft = p[left].second;
    		int curright = p[right].second;
    		
    		int merged = curleft + curright;
    		p[left].second = merged;
    		p[right].second = 0;
    		
    		freq[curleft].erase(left);
    		if (freq[curleft].empty()) freq.erase(curleft);
    		
    		freq[curright].erase(right);
    		if (freq[curright].empty()) freq.erase(curright);
    		
    		freq[merged][left] = vleft;
    	}
    }
    
    cout << ans << ln;
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
