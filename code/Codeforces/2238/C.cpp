// Problem: Village Guilds
// Contest: Codeforces
// URL: https://m2.codeforces.com/contest/2238/problem/C
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

int ans = 0;
vector<map<int, int>> pd;
vector<vector<int>> AL;

void dfs(int u, int depth) {
    // dbg(u, ans);
    map<int, int>& x = pd[u];
    set<int> aff;
    
    for (auto& v : AL[u]) {
        dfs(v, depth + 1);
        
        map<int, int>& y = pd[v];
        
        if (x.size() < y.size()) {
            swap(x, y);
        }
        
        // y is smallest
        for (auto& i : y) {
            if (x[i.first] and aff.insert(i.first).second) {
                ans++;
            }
            x[i.first] += i.second;
        }
    }
    
    ans++;
    pd[u][depth]++;
    
    // dbg(u, ans);
}

void solve() {
    int n;
    cin >> n;
    ans = 0;
    pd.assign(n, map<int, int>());
    AL.assign(n, vector<int>());
    
    for (int v = 1; v < n; v++) {
        int u;
        cin >> u;
        u--;
        AL[u].pb(v);
    }
    
    dfs(0, 0);
    
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
