// Problem: Sum of Four Values
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1642
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

struct Ele {
    int val;
    int idx1, idx2;
};

bool valid(Ele& a, Ele& b) {
    if (a.idx1 == b.idx1 or a.idx1 == b.idx2 or
        a.idx2 == b.idx1 or a.idx2 == b.idx2
    ) return false;
    
    return true;
}

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n); for (auto& i : a) cin >> i;
    
    vector<Ele> adj;
    
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            adj.pb({a[i] + a[j], i, j});
        }
    }
    
    unordered_map<int, vector<Ele>> seen;
    for (int i = 0; i < adj.size(); i++) {
        int target = x - adj[i].val;
        
        for (auto& j : seen[target]) {
            if (valid(adj[i], j)) {
                cout << adj[i].idx1+1 << " " << adj[i].idx2+1 << " " << j.idx1+1 << " " << j.idx2+1 << ln;
                return;
            }
        }
        
        seen[adj[i].val].pb(adj[i]);
    }
    
    cout << "IMPOSSIBLE" << ln;
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
