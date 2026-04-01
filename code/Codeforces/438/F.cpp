// Problem: F. First Problem
// Contest: Codeforces - 2025 ICPC Gran Premio de Mexico 1ra Fecha
// URL: https://codeforces.com/gym/105873/problem/F
// Memory Limit: 1024 MB
// Time Limit: 10000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize("O3,unroll-loops")
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

const int INF = INT32_MAX / 4;
const ld PI = acos(-1);
const int MOD = 1000000007;
const double eps = 1e-9;

const int N = 100005;
int a[N];

void solve() {
    int n, k;
    cin >> n >> k;
    
    for (int i = 0; i < n; i++) cin >> a[i];
    
    while(k--) {
    	char type;
    	int l, r;
    	cin >> type >> l >> r;
    	l--, r--;
    	if (type == 'Q') {
    		int mx = 0;
    		for (int i = l; i <= r; i++) mx = max(mx, a[i]);
    		cout << mx << ln;
    	}
    	else if (type == 'A') {
    		for (int i = l; i <= r; i++) a[i]++;
    	}
    	else {
    		int mx = 0;
    		for (int i = 0; i < n; i++) mx = max(mx, a[i]);
    		for (int i = l; i <= r; i++) a[i] -= a[i] * (a[i] == mx);
    	}
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