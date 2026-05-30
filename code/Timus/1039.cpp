// Problem: 1039. Anniversary Party
// Contest: Timus Online Judge - Ural State University Internal Contest October'2000 Students Session
// URL: https://acm.timus.ru/problem.aspx?num=1039&space=1
// Memory Limit: 8 MB
// Time Limit: 500 ms
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

int dp[2][6001];
int c[6001];
int root[6001];
vector<int> AL[6001];

void recurse(int u, int p) {
	dp[0][u] = 0;
	dp[1][u] = c[u];
	
	for (auto& v : AL[u]) {
		if (v == p) continue;
		
		recurse(v, u);
		dp[0][u] += max(dp[0][v], dp[1][v]);
		dp[1][u] += dp[0][v];
	}
}

void solve() {
    int n;
    cin >> n;
    fill_n(&root[0], 6001, 0);
    for (int i = 0; i < n; i++) {
    	cin >> c[i];
    }
    
    while (true) {
    	int u, v;
    	cin >> u >> v;
    	if (!u and !v) break;
    	
    	u--, v--;
    	AL[v].pb(u);
    	root[u] = 1;
    }
    int r = -1;
    for (int i = 0; i < n; i++) {
    	if (!root[i]) {
    		r = i;
    		break;
    	}
    }
    
    recurse(r, -1);
    
    cout << max(dp[0][r], dp[1][r]) << ln;
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
