// Problem: B. Little Pony and Sort by Shift
// Contest: Codeforces - Codeforces Round 259 (Div. 2)
// URL: https://codeforces.com/contest/454/problem/B
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
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i : a) cin >> i;
    
    int mn = 1e9;
    int idx = -1;
    bool lg = false;
    for (int i = 0; i < n; i++) {
    	if (a[i] < mn or (a[i] == mn and lg)) {
    		mn = a[i];
    		idx = i;
    		lg = false;
    	}
    	else if (a[i] > mn) {
    		lg = true;
    	}
    }
    
    bool poss = true;
    for (int i = idx; i < idx + n - 1; i++) {
    	if (a[(i + 1) % n] < a[i % n]) {
    		poss = false;
    	}
    }
    
    if (poss) {
    	cout << (n - idx) % n << ln;
    }
    else cout << -1 << ln;
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
