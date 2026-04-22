// Problem: A - ><
// Contest: AtCoder - AtCoder Grand Contest 040
// URL: https://atcoder.jp/contests/agc040/tasks/agc040_a
// Memory Limit: 1024 MB
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
    string s;
    cin >> s;
    int n = s.length() + 1;
    vector<int> a(n, 0);
    
    for (int i = 1; i < n; i++) {
    	if (s[i-1] == '<') {
    		a[i] = a[i-1] + 1;
    	}
    }
    for (int i = n - 2; i >= 0; i--) {
    	if (s[i] == '>') {
    		a[i] = max(a[i+1] + 1, a[i]);
    	}
    }
    
    int ans = 0;
    for (auto& i : a) ans += i;
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
