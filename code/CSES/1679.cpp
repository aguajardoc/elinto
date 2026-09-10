// Problem: Course Schedule
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1679
// Memory Limit: 512 MB
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

vector<int> vis, order;
vector<vector<int>> AL;

bool topo(int u) {
    vis[u] = 1;
    
    for (auto& v : AL[u]) {
        if (vis[v] == 1) return false;
        if (vis[v] == 0 and not topo(v)) return false;    
    }
    
    vis[u] = 2;
    order.pb(u);
    return true;
}


void solve() {
    int n, m;
    cin >> n >> m;
    
    AL.assign(n + 1, vector<int>());
    vis.assign(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        AL[a].pb(b);
    }
    
    for (int i = 1; i <= n; i++) {
        if (!vis[i] and !topo(i)) {
            cout << "IMPOSSIBLE" << ln;
            return;
        }
    }
    
    reverse(order.begin(), order.end());
    for (auto& i : order) {
        cout << i << " ";
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
