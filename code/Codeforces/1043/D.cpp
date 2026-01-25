// Problem: D. Mysterious Crime
// Contest: Codeforces - Codeforces Round 519 by Botan Investments
// URL: https://codeforces.com/contest/1043/problem/D
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

void solve() {
	int n, m;
	cin >> n >> m;
    vector<vector<int>> loc(n, vector<int>(m, -1));
    vector<vector<int>> a(m, vector<int> (n, 0));
    for (int i = 0; i < m; i++) {
    	for(int j = 0; j < n; j++) {
    		int x;
    		cin >> x;
    		x--;
    		loc[x][i] = j;
    		a[i][j] = x;
    	}
    }
    
    int ans = 0;
    
    int cur = 1;
    for (int i = 1; i < n; i++) {
    	// If all of them match the previous, cur++
    	// 1, 0 -> 2, 1
    	// For all loc[a[0][i]], they should be loc[a[0][i-1]] + 1
    	bool works = true;
    	for (int j = 0; j < m; j++) {
    		if (loc[a[0][i]][j] != loc[a[0][i-1]][j] + 1) works = false;
    	}
    	if (works) {
    		cur++;
    	}
    	// Else add to ans and reset
    	else {
    		ans += (cur * (cur + 1)) / 2;
    		cur = 1;
    	}
    }
    ans += (cur * (cur + 1)) / 2;
    
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
