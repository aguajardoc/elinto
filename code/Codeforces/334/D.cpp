// Problem: D. Chips
// Contest: Codeforces - Codeforces Round 194 (Div. 2)
// URL: https://codeforces.com/contest/334/problem/D
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
    int k = n / 2 - 1;
    vector<int> rows(1001, 0), cols(1001, 0);
    for (int i = 0; i < m; i++) {
    	int x, y;
    	cin >> x >> y;
    	rows[x] = 1;
    	cols[y] = 1;
    }
    
    int ans = 0;
    for (int i = 2, j = 0; j < k; j++, i++) {
    	// Top row
    	if (!cols[i]) ans++;
    	// Right col
    	if (!rows[i]) ans++;
    	// Bottom row
    	if (!cols[n - i + 1]) ans++;
    	// Left col
    	if (!rows[n - i + 1]) ans++;
    }
    
    if (n % 2) {
    	if (!cols[n/2+n%2]) ans++;
    	else if (!rows[n/2+n%2]) ans++;
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
