// Problem: B. Cosmic Tables
// Contest: Codeforces - Codeforces Round 137 (Div. 2)
// URL: https://codeforces.com/contest/222/problem/B
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
int a[1001][1001];

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n  ; i++) {
    	for (int j = 0; j < m; j++) cin >> a[i][j];
    }
    map<int, int> row, col;
    for (int i = 0; i < n; i++) row[i] = i;
    for (int i = 0; i < m; i++) col[i] = i;
    while(k--) {
    	char p; int x, y;
    	cin >> p >> x >> y;
    	x--, y--;
    	if (p == 'c') {
    		swap(col[x], col[y]);
    	}
    	if (p == 'r') {
    		swap(row[x], row[y]);
    	}
    	if (p == 'g') {
    		cout << a[row[x]][col[y]] << ln;
    	}
    }
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
