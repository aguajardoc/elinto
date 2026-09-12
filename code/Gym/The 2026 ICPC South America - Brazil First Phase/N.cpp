// Problem: N. Nlogônia's Keys
// Contest: Codeforces - The 2026 ICPC South America - Brazil First Phase
// URL: https://codeforces.com/gym/106679/problem/N
// Memory Limit: 1024 MB
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

void solve() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> EL(n - 1);
    vector<vector<int>> AL(n + 1);
    
    for (int i = 0; i < n-1; i++) {
        cin >> EL[i].first >> EL[i].second;
        AL[EL[i].first].pb(EL[i].second);
        AL[EL[i].second].pb(EL[i].first);
    }
    
    vector<vector<int>> keys(n + 1);
    int cur = 1;
    
    for (int i = 0; i < n - 1; i++) {
        int u = EL[i].first, v = EL[i].second;
        int ku = cur++, kv = cur++;
        
        auto dfs = [&](auto& self, int u, int p, int tk) -> void {
            keys[u].pb(tk);
            for (auto& v : AL[u]) {
                if (v != p) self(self, v, u, tk);
            }
        };
        
        dfs(dfs, u, v, ku); dfs(dfs, v, u, kv);
    }
    
    cout << cur - 1 << ln;
    for (int i = 1; i <= n; i++) {
        cout << keys[i].size() << " ";
        for (auto& j : keys[i]) {
            cout << j << " ";
        }
        cout << ln;
    }
    
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
