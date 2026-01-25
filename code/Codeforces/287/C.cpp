// Problem: C. Lucky Permutation
// Contest: Codeforces - Codeforces Round 176 (Div. 2)
// URL: https://codeforces.com/contest/287/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
    if (n % 4 != 0 and (n-1) % 4 != 0) {
    	cout << -1 << ln;
    	return;
    }
    
    vector<int> ans(n, 0);
    // Four pointers ahh
    int l = 0, r = n - 1;
    while (l + 1 < r - 1) {
    	int a = l, b = l + 1, c = r - 1, d = r;
    	
    	ans[r-1] = a;
    	ans[l] = b;
    	ans[r] = c;
    	ans[l+1] = d;
    	
    	l+=2;
    	r-=2;
    }
    
    if (n % 2) {
    	ans[n/2] = n/2;
    }
    
    for (auto& i : ans) {
    	cout << i+1 << " ";
    }
    cout << ln;
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
