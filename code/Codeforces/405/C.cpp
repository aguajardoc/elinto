// Problem: C. Unusual Product
// Contest: Codeforces - Codeforces Round 238 (Div. 2)
// URL: https://codeforces.com/contest/405/problem/C
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

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> mat(n, vector<int>(n, 0));
    int cur = 0;
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < n; j ++) {
    		cin >> mat[i][j];
    		if (i == j and mat[i][j]) cur++;
    	}
    }
    
    int q;
    cin >> q;
    while(q--) {
    	int x;
    	cin >> x;
    	if (x == 3) {
    		cout << cur % 2;
    	}
    	else {
    		int y;
    		cin >> y;
    		cur++;
    	}
    }
    
    cout << ln;
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
