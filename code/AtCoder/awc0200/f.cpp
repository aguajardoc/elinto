// Problem: F - Dungeon Conquest
// Contest: AtCoder - AtCoder Weekday Contest 0200 Beta
// URL: https://atcoder.jp/contests/awc0200/tasks/awc0200_f
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
const int MOD = 1000000007;
const double eps = 1e-9;

int dp[3001][3001]; // idx, health
int n, m;
vector<int> a,b,c;

int recurse(int idx, int health) {
	if (idx == n) return 0;
	
	if (dp[idx][health] != -1) return dp[idx][health];
	
	int res = 0;
	// Reach rest area
	int new_health = health - a[idx];
	if (new_health < 0) return dp[idx][health] = -INF;
	
	// Take both options
	if (idx == n - 1) return dp[idx][health] = 0;
	
	int hb = min(new_health + b[idx], m);
	res = max(
		recurse(idx + 1, hb),
		recurse(idx + 1, new_health) + c[idx]
	);
	
	return dp[idx][health] = res;
}

void solve() {
    cin >> n >> m;
    a.resize(n); for (auto& i : a) cin >> i;
    b.resize(n-1);
    c.resize(n-1); 
    for (int i = 0; i < n - 1; i++) {
    	cin >> b[i] >> c[i];
    }
    fill_n(&dp[0][0], 3001*3001, -1);
    
    cout << recurse(0, m) << ln;
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
