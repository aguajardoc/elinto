// Problem: M. Moon Dancers
// Contest: Codeforces - 2021 ICPC Gran Premio de Mexico 1ra Fecha
// URL: https://codeforces.com/gym/103274/problem/M
// Memory Limit: 256 MB
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
    vector<int> a(n);
    for (auto& i : a) cin >> i;
    sort(a.begin(), a.end());
    int ans = 0;
    
    for (int diff = 1; diff <= 359; diff++) {
        vector<int> taken(n, 0);
        int res = 0;
        
        vector<vector<int>> AL(360);
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < n; j++) {
                int idx = (i + j) % n;
                
                int v = a[idx] - a[i];
                v = ((v % 360) + 360) % 360;
                
                if (v == diff) {
                    AL[i].pb(idx);
                    AL[idx].pb(i);
                }
            }
        }
        
        vector<int> visited(360, 0);
        vector<int> color(360, -1);
        for (int i = 0; i < 360; i++) {
            if (visited[i]) continue;
            visited[i] = 1;
            color[i] = 0;
            queue<int> q;
            q.push(i);
            
            int c0 = 1, c1 = 0;
            
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                
                for (auto& v : AL[u]) {
                    if (visited[v]) continue;
                    color[v] = 1 - color[u];
                    if (color[v]) c1++;
                    else c0++;
                    
                    q.push(v);
                    visited[v] = 1;
                }
            }
            
            res += min(c0, c1);
        }
        
        // dbg(diff, res);
        ans = max(ans, res);
    }
    
    
    cout << ans << ln;
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
