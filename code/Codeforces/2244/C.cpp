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

vector<int> visited_items, visited_idxs, visited, a;
vector<vector<int>> AL;

void dfs(int u) {
    visited_items.pb(a[u]);
    visited_idxs.pb(u);
    visited[u] = true;

    for (auto& v : AL[u]) {
        if (visited[v]) continue;

        dfs(v);
    }

}

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    a.assign(n, 0); for (auto& i : a) cin >> i; for (auto& i : a) i--;
    AL.assign(n + 1, vector<int>());

    for (int i = 0; i < n; i++) {
        if (i + x < n) AL[i].pb(i + x);
        if (i + x < n) AL[i+x].pb(i);
        if (i + y < n) AL[i].pb(i + y);
        if (i + y < n) AL[i+y].pb(i);
    }

    visited.assign(n, 0);
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        // if all in component match their ids, good!
        visited_items.clear();
        visited_idxs.clear();

        dfs(i);

        sort(visited_items.begin(), visited_items.end());
        sort(visited_idxs.begin(), visited_idxs.end());

        if (visited_idxs != visited_items) {
            cout << "NO" << ln;
            return;
        }
    }

    cout << "YES" << ln;
}

signed main() {
    fast_cin();
    
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        solve();
    }

    return 0;
}
// g++ C.cpp && ./a.out <input.in>output.out