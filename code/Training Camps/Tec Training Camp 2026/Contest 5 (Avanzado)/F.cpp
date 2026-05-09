// Problem: F. Mysterious Present
// Contest: Codeforces - TC Tec 2026 Contest 5 (Avanzado)
// URL: https://codeforces.com/group/eZBA1VtmXM/contest/691508/problem/F
// Memory Limit: 64 MB
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
// #define int ll
#define ld long double
#define pb push_back

const ll INF = LLONG_MAX / 4;
const ld PI = acos(-1);
const int MOD = 1000000007;
const double eps = 1e-9;

short dp[5011];
short par[5011];

struct Envelope {
	int w, h, idx;
};

vector<Envelope> enve;
vector<vector<short>> AL;

int m;

short dfs(int idx) {
	if (idx == m) {
		return 0;
	}
	
	if (dp[idx] != -1) return dp[idx];
	
	int res = 0;
	for (auto& v : AL[idx]) {
		int nr = dfs(v) + 1;
		
		if (nr > res) {
			res = nr;
			par[idx] = v;
		}
	}
	
	return (dp[idx] = res);
}

void solve() {
    int n, w, h;
    cin >> n >> w >> h;
    enve.pb({w, h, 0});
    fill_n(&dp[0], 5001, -1);
    fill_n(&par[0], 5001, -1);
    
    for (int i = 0; i < n; i++) {
    	int wi, he;
    	cin >> wi >> he;
    	if (wi <= w or he <= h) continue;
    	
    	enve.pb({wi, he, i + 1});
    }
    
    m = enve.size();
    AL.resize(m);
    
    for (int i = 0; i < m; i++) {
    	for (int j = 0; j < m; j++) {
    		if (i == j) continue;
    		
    		if (enve[j].w > enve[i].w and
    			enve[j].h > enve[i].h
    		) {
    			AL[i].pb(j);
    		}
    	}
    }
    
    
    short ans = dfs(0);
    if (!ans) {
    	cout << 0 << ln;
    	return;
    }
    cout << ans << ln;
    int cur = 0;
    while (cur != -1) {
    	cur = par[cur];
    	if (cur != -1) {
    		cout << enve[cur].idx << " ";
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
