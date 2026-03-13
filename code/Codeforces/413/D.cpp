// Problem: D. 2048
// Contest: Codeforces - Coder-Strike 2014 - Round 2
// URL: https://codeforces.com/contest/413/problem/D
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

int dp[2001][2060][2];
int n, k, target;
vector<int> a;

int recurse(int idx, int mask, int done) {
	if (idx == n) {
		return done;
	}
	
	if (dp[idx][mask][done] != -1) return dp[idx][mask][done];
	
	int res = 0;
	
	if (!a[idx] or a[idx] == 2) {
		int new_mask = mask + 2;
		int new_done = done;
		
		if (new_mask >= target) {
			new_done = 1;
			new_mask = 0;
		}
		
		res += recurse(idx + 1, new_mask, new_done);
		res %= MOD;
	}
	
	if (!a[idx] or a[idx] == 4) {
		int new_mask = (mask & 2) ? 4 : mask + 4;
		int new_done = done;
		
		if (new_mask >= target) {
			new_done = 1;
			new_mask = 0;
		}
		
		res += recurse(idx + 1, new_mask, new_done);
		res %= MOD;
	}
	
	return dp[idx][mask][done] = res;
}

void solve() {
    cin >> n >> k;
    a.assign(n, 0);
    target = 1 << k;
    for (auto& i : a) cin >> i;
    
    fill_n(&dp[0][0][0], 2001*2060*2, -1);
    
    cout << recurse(0, 0, 0) << ln;
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
