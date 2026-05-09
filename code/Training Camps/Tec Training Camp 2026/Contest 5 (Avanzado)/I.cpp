// Problem: I. MUH and Cube Walls
// Contest: Codeforces - TC Tec 2026 Contest 5 (Avanzado)
// URL: https://codeforces.com/group/eZBA1VtmXM/contest/691508/problem/I
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

vector<int> z_function(vector<int> s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a, b, c,d;
    for (int i = 0; i < n; i++) {
    	int x;
    	cin >> x;
    	a.pb(x);
    }
    for (int i = 0; i < m; i++) {
    	int x;
    	cin >> x;
    	b.pb(x);
    }
    for (int i = 1; i < m; i++) {
    	c.pb(b[i] - b[i-1]);
    }
    c.pb(1e10);
    for (int i = 1; i < n; i++) {
    	c.pb(a[i] - a[i-1]);
    }
    
    
    vector<int> res = z_function(c);
    int ans = 0;
    
    for (auto& i : res) {
    	ans += (i == m - 1);
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
