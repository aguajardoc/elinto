// Problem: B. Another Sorting Problem
// Contest: Codeforces - Codeforces Round 1099 (Div. 2)
// URL: https://codeforces.com/contest/2231/problem/B
// Memory Limit: 256 MB
// Time Limit: 1500 ms
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
    int n;
    cin >> n;
    // get max, then update value of k?
    vector<pair<int, int>> incs(n, {-INF, INF});
	vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) {
    	if (a[i] >= a[i-1]) continue;
    	int L = a[i-1] - a[i];
    	int R = INF;
    	if (i < n - 1) {
    		R = a[i+1] - a[i];
    	}
    	
    	incs[i] = {L, R};
    }
    
    bool poss = true;
    int L = -INF, R = INF;
    for (auto& [x, y] : incs) {
    	L = max(L, x);
    	R = min(R, y);
    }
    
    // dbg(L);
    
    for (int i = 1; i < n; i++) {
    	if (a[i] < a[i-1]) {
    		a[i] += L;
    	}
    }
    
    if (!is_sorted(a.begin(),a.end())) {
    	cout << "NO" << ln;
    }
    else cout << "YES" << ln;
    
    
}

signed main() {
    fast_cin();
    
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
