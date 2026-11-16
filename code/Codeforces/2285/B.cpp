// Problem: B. Diverse String
// Contest: Codeforces - Codeforces Round 1135 (Div. 2)
// URL: https://codeforces.com/contest/2285/problem/B
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
    int n, k; cin >> n >> k;
    int z = 0, o = 0;
    string s; cin >> s;
    for (auto& i : s) {
    	if (i == '0') z++;
    	else o++;
    }
    
    int ans = 1;
    if (z >= o) {
    	z += min(o, k);
    	o -= min(o, k);
    }
    else {
    	o += min(z, k);
    	z -= min(z, k);
    }
    
    ans += (z * (z+1)) / 2;
    ans += (o * (o+1)) / 2;
    
    cout << ans << ln;
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
