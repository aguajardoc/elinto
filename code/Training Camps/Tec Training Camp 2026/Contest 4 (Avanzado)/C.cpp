// Problem: C. Sagheer and Apple Tree
// Contest: Codeforces - TC Tec 2026 Contest 4 (Avanzado)
// URL: https://codeforces.com/group/eZBA1VtmXM/contest/691247/problem/C
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
    vector<int> vals(n);
    vector<vector<int>> AL(n);
    int start = -1;
    
    for (auto& i : vals) cin >> i;
    for (int i = 0; i < n-1; i++) {
    	int x;
    	cin >> x;
    	x--;
    	AL[x].pb(i+1);
    	AL[i+1].pb(x);
    }
    
    for (int i = 0; i < n; i++) {
    	if (AL[i].size() == 1) start = i;
    }
    
    vector<int> red(1e7 + 1, 0);
    vector<int> blue;
    vector<int> blue2(1e7 + 1, 0);
    int tot = 0;
    
    queue<int> q;
    q.push(start);
    vector<int> color(n, -1);
    color[start] = 0;
    blue.pb(vals[start]);
    blue2[vals[start]]++;
    tot = vals[start];
    
    while (!q.empty()) {
    	int u = q.front();
    	q.pop();
    	
    	for (auto& v : AL[u]) {
    		if (color[v] != -1) continue;
    		
    		if (color[u] == 0) {
    			red[vals[v]]++;
    		}
    		else {
    			tot ^= vals[v];
    			blue.pb(vals[v]);
    			blue2[vals[start]]++;
    		}
    		
    		color[v] = 1 - color[u];
    		
    		q.push(v);
    	}
    }
    
    int ans = 0;
    if (tot == 0) {
    	int B = blue.size();
    	int R = (n - B);
    	
    	ans += (B * (B - 1)) / 2;
    	ans += (R * (R - 1)) / 2;
    	
    	for (int i = 1; i <= 1e7; i++) {
    		int b = blue2[i];
    		int r = red[i];
    		
    		ans += b * r;
    	}
    }
    else {
    	for (auto& i : blue) {
    		int k = tot ^ i;
    		if (k <= 1e7) ans += red[k];
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
