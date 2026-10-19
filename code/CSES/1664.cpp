// Problem: Movie Festival Queries
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1664
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
// #define int ll
#define ld long double
#define pb push_back

const ll INF = INT32_MAX / 4;
const ld PI = acos(-1);
const int MOD = 1000000007;
const double eps = 1e-9;

const int N = 1e6 + 67;
int AL[N], up[20][N];
vector<int> stoe[N];

void solve() {
    int n, q; cin >> n >> q;
    multiset<int> active_ends;
    fill_n(&AL[0], N, INF);
    
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        stoe[a].pb(b);
        active_ends.insert(b);
    }
    for (int i = 0; i <= N; i++) {
        if (active_ends.empty()) continue;
        int nxt = *active_ends.begin();
        AL[i] = nxt;
        
        for (auto& j : stoe[i]) {
            active_ends.erase(active_ends.find(j));
        }
    }
    
    for (int i = 0; i < N; i++) {
        up[0][i] = AL[i];
    }
    
    for (int i = 1; i < 20; i++) {
        for (int j = 0; j < N; j++) {
            
            int p = up[i-1][j];
            if (p == INF) up[i][j] = INF;
            else up[i][j] = up[i-1][p];
        }
    }
    
    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;
        
        int res = 0;
        int cur = l;
        while (true) {
            int last = -1;
            for (int j = 0; j < 20; j++) {
                if (up[j][cur] <= r) last = j;
            }
            
            if (last == -1) break;
            res+=(1ll << last);
            cur = up[last][cur];
        }
        
        cout << res << ln;
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
