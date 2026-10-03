// Problem: E - lt and le
// Contest: AtCoder - AtCoder Beginner Contest 478
// URL: https://atcoder.jp/contests/abc478/tasks/abc478_e
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

struct Edge {
    int v, type;
};

int n, m;
map<pair<int, int>, int> queries_proc;
vector<vector<Edge>> AL;
vector<int> a;
bool poss = true;

void dfs(int u, int val, int len) {
    // dbg(u, val, a[u]);
    // If this pos has a non conflicting declared val
    // we good!
    if (a[u] and a[u] >= val) return;
    if (val > n or len > n + 5) {
        poss = false;
        return;
    }
    a[u] = val;
    
    for (auto& e : AL[u]) {
        // dbg(e.v, e.type, u);
        dfs(e.v, val + e.type, len + 1);
    } 
}

void solve() {
    cin >> n >> m;
    a.assign(n, 0);
    for (int i = 0; i < m; i++) {
        int t, u, v;
        cin >> t >> u >> v;
        u--, v--;
        if (u == v) {
            if (t == 1) poss = false;
        }
        else {
            queries_proc[{u, v}] = max(queries_proc[{u, v}], t);
        }
    }
    AL.resize(n);
    for (auto& i : queries_proc) {
        AL[i.first.first].pb({i.first.second, i.second});
    }
    
    for (int u = 0; u < n; u++) {
        dfs(u, 1, 0);
        if (!poss) {
            cout << "No" << ln;
            return;
        }
    }
    cout << "Yes" << ln;
    
    for (auto& i : a) if (!i) i = 1;
    
    for (auto& i : a) cout << i << " ";
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
