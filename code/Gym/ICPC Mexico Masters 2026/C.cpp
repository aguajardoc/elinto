// Problem: C. Campus Walkways
// Contest: Codeforces - ICPC Masters Mexico 2026
// URL: https://codeforces.com/gym/106646/problem/C
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

const int N = 200005;
int sts[N], ans[N], visited[N], dist[N];
vector<pair<int, int>> AL[N];
map<pair<int, int>, int> opp;
int res = 0;
int n;

void dfs(int u) {
    visited[u] = true;
    
    for (auto& [v, w] : AL[u]) {
        if (visited[v]) continue;
        
        dist[v] = dist[u] + w;
        res += dist[v];
        dfs(v);
        sts[u] += sts[v];
    }
    
    sts[u]++;
}

void dfs2(int u, int r) {
    visited[u] = true;
    ans[u] = r;
    
    for (auto& [v, w] : AL[u]) {
        if (visited[v]) continue;
        
        int L = w * (sts[v]);
        int R = opp[{u, v}] * (n - sts[v]);
        
        // dbg(sts[u], sts[v]);
        // dbg(r, L, R);
        
        dfs2(v, r + R - L);
    }
}

void solve() {
    cin >> n;
    
    fill_n(&visited[0], N, 0);
    fill_n(&sts[0], N, 0);
    fill_n(&ans[0], N, 0);
    fill_n(&dist[0], N, 0);
    
    for (int i = 0; i < n - 1; i++) {
        int u, v, a, b;
        cin >> u >> v >> a >> b;
        AL[u].pb({v, a});
        AL[v].pb({u, b});
        
        opp[{u, v}] = b;
        opp[{v, u}] = a;
    }
    
    dfs(1);
    int base = res;
    // dbg(base);
    
    fill_n(&visited[0], N, 0);
    dfs2(1, base);
    
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
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
