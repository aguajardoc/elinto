// Problem: B. Balanced Codex of Knuth
// Contest: Codeforces - 2026 XVIII Donald Knuth Annual Programming Contest by ESCOM-IPN
// URL: https://codeforces.com/gym/106722/problem/B
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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

const int N = 2000000 + 67;

int subtree_size[N], dist[N], weights[N], sow = 0, ans[N];
vector<int> AL[N];

int get_sts(int u, int p=-1) {
    subtree_size[u] = weights[u];
    
    for (auto& v : AL[u]) {
        if (v == p) continue;
        
        dist[v] = dist[u] + 1;
        subtree_size[u] += get_sts(v, u);
    }
    
    return subtree_size[u];
}

void dfs(int u, int res, int p=-1) {
    ans[u] = res;
    
    for (auto& v : AL[u]) {
        if (v == p) continue;
        
        int change = (sow - subtree_size[v]) - subtree_size[v];
        
        dfs(v, res + change, u);
    }
}


void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> weights[i];
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v; u--, v--;
        AL[u].pb(v);
        AL[v].pb(u);
    }
    
    get_sts(0);
    int base = 0;
    for (int i = 0; i < n; i++) {
        base += dist[i] * weights[i];
        sow += weights[i];
    }
    dfs(0, base);
    
    int res = INF;
    for (int i = 0; i < n; i++) {
        res = min(res, ans[i]);
    }
    
    cout << res << ln;
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
