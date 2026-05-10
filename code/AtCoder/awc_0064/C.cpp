// Problem: C - Summer Homework Plan
// Contest: AtCoder - AtCoder Weekday Contest 0064 Beta
// URL: https://atcoder.jp/contests/awc0064/tasks/awc0064_c
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

int dp[101][100100];
int n, m;
vector<int> r, t;

int recurse(int idx, int time) {
	if (idx == n or time == m) {
		return 0;
	}
	
	if (dp[idx][time] != -1) return dp[idx][time];
	
	int res = 0;
	res = recurse(idx + 1, time);
	if (time + t[idx] <= m)res = max(res, recurse(idx + 1, time + t[idx]) + r[idx]);
	
	return dp[idx][time] = res;
}

void solve() {
    cin >> n >> m;
    fill_n(&dp[0][0], 101*100100, -1);
    r.assign(n, 0);
    t.assign(n, 0);
    
    for (int i = 0; i < n; i++) {
    	cin >> r[i] >> t[i];
    }
    
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
