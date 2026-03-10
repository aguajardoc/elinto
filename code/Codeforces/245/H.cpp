// Problem: H. Queries for Number of Palindromes
// Contest: Codeforces - CROC-MBTU 2012, Elimination Round (ACM-ICPC)
// URL: https://codeforces.com/contest/245/problem/H
// Memory Limit: 256 MB
// Time Limit: 5000 ms
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

int mat[5001][5001], nm[5001][5001];

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    
    for (int i = 0; i < n; i++) {
    	deque<char> fwd, bwd;
    	for (int j = i; j < n; j++) {
    		fwd.push_back(s[j]);
    		bwd.push_front(s[j]);
    		
    		if (fwd == bwd) {
    			mat[i][j]++;
    		}
    	}
    }
    
    for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= n; j++) {
    		nm[i][j] = mat[i-1][j-1] - nm[i-1][j-1] + nm[i-1][j] + nm[i][j-1];
    		// cout << nm[i][j] << " ";
    	}
    	// cout << ln;
    }
  
    
    int q;
    cin >> q;
    while(q--) {
    	int l, r;
    	cin >> l >> r;
    	
    	// dbg(nm[r][r]);
    	// dbg(nm[l][r-1]);
    	// dbg(nm[l-1][r]);
    	// dbg(nm[l-1][l-1]);
    	
    	int ans = nm[r][r] - nm[l-1][r] - nm[r][l-1] + nm[l-1][l-1];
    	
    	cout << ans << ln;
    }
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
