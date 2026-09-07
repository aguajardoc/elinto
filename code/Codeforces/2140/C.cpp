// Problem: C. Ultimate Value
// Contest: Codeforces - Codeforces Round 1049 (Div. 2)
// URL: https://codeforces.com/contest/2140/problem/C
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
    vector<int> a(n);
    int cur = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i % 2) {
            cur -= a[i];
        }
        else cur += a[i];
    }
    
    int ans = cur + n - 1 - (n % 2 == 0);
    
    vector<int> adj(n), adj2(n), p(n+1, -INF), p2(n+1,-INF);
    int mn = -INF, mx = -INF;
    for (int i = 0; i < n; i++) {
        adj[i] = 2 * a[i] + i;
        adj2[i] = 2 * a[i] + (n - i - 1);
        if (i % 2 == 0) {
            adj[i] *= -1;
            adj2[i] *= -1;
        }
    }
    
    for (int i = n - 1; i >= 0; i--) {
        p[i] = max(p[i+1], (i % 2 == 1 ? adj[i]:-INF));
        p2[i] = max(p2[i+1], (i % 2 == 0 ? adj2[i]:-INF));
    }
    
    
    // if even index, i take from adj
    // adj[i] + max pos to my right
    // if odd index, i take from adj2
    // adj2[i] + max neg to my right
    
    // for (auto& i : adj) {
        // cout << i << " ";
    // }
//     
    // cout << ln;
    
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            ans = max(ans, cur + adj[i] + p[i]);
        }
        else {
            ans = max(ans, cur + adj2[i] + p2[i]);  
        }
    }
    
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
