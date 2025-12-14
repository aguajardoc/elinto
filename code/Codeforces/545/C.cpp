// Problem: C. Woodcutters
// Contest: Codeforces - Codeforces Round 303 (Div. 2)
// URL: https://codeforces.com/contest/545/problem/C
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
#define INF 2e18
#define PI 3.14159265358979323846
#define MOD 1000000007

double eps = 1e-9;
int n;
vector<int> a, h;
vector<vector<int>> dp;

int recurse(int idx, int dir) {
	if (idx == n) {
		return 0;
	}
	if (dp[dir][idx] != -1) return dp[dir][idx];
	
	int fell = 0;
	if (!idx or (idx and (((dir == 0 or dir == 1) and a[idx] - h[idx] > a[idx - 1]) or (dir == 2 and a[idx] - h[idx] > a[idx - 1] + h[idx - 1])))) {
		fell = max(fell, recurse(idx + 1, 1) + 1);
	}
	if (idx == n - 1 or (idx != n - 1 and a[idx] + h[idx] < a[idx + 1])) {
		fell = max(fell, recurse(idx + 1, 2) + 1);
	}
	
	fell = max(fell, recurse(idx + 1, 0));
	
	return dp[dir][idx] = fell;
}

void solve() {
    cin >> n;
    a.assign(n, 0);
    h.assign(n, 0);
    dp.assign(3, vector<int> (n, -1));
    for (int i = 0; i < n; i++) {
    	cin >> a[i] >> h[i];
    }
    cout << recurse(0,0) << ln;
}

signed main() {
    fast_cin();
    
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
