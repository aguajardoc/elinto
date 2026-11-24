// Problem: B - Increasing Prefix XOR
// Contest: AtCoder - AtCoder Regular Contest 141
// URL: https://atcoder.jp/contests/arc141/tasks/arc141_b
// Memory Limit: 1024 MB
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
const int MOD = 998244353;
const double eps = 1e-9;

int dp[66][66];
int n, m;
int mspow, mspowr;

struct Edge {
	int v, w;
};

vector<vector<Edge>> AL;

int recurse(int idx, int pow) {
	if (idx == n) return 1;
	if (pow > __lg(m) + 1) return 0;
	
	if (dp[idx][pow] != -1) return dp[idx][pow];
	
	int res = 0;
	for (auto& [v, w] : AL[pow]) {
		if (v < pow) continue;
		int x = recurse(idx + 1, v)%MOD;
		res += ((x) * (w % MOD))%MOD;
		res %= MOD;
		if (x == 0) break;
		
		res %= MOD;
	}
	
	return dp[idx][pow] = res;
}

void solve() {
    cin >> n >> m;
    if (n > 63) {
    	cout << 0 << ln;
    	return;
    }
    mspow = (1ll << __lg(m));
    mspowr = m - mspow + 1;
    
    AL.resize(__lg(m)+2);
    for (int i = 0; i <= __lg(m); i++) {
    	for (int j = i + 1; j <= __lg(m) + 1; j++) {
    		int w = (1ll << (j-1));
    		if (j == (__lg(m)+1)) w = mspowr;
    		// dbg(i,j,w);
    		AL[i].pb({j, w});
    	}
    }
    
    fill_n(&dp[0][0], 66*66, -1);
    
    cout << recurse(0, 0) << ln;
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
