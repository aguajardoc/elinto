// Problem: Shortest Subsequence
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1087
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

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    int mp[128]; mp['A'] = 0, mp['C'] = 1, mp['G'] = 2, mp['T'] = 3;
    string pm = "ACGT";
    vector<vector<int>> np(4, vector<int>());
    vector<vector<int>> next(4, vector<int>(n + 1, INF));
    
    for (int i = 1; i <= n; i++) {
        np[mp[s[i-1]]].pb(i);
    }
    
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < 4; j++) {
            auto it = upper_bound(np[j].begin(), np[j].end(), i);
            if (it != np[j].end()) next[j][i] = *it;
        }
    }
    
    queue<int> q;
    q.push(0);
    vector<int> visited(n + 1, 0);
    vector<int> par(n + 1, -1);
    visited[0] = 1;
    
    string ans;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            // dbg(i, u, next[i][u]);
            if (next[i][u] == INF) {
                int cur = u;
                ans += pm[i];
                int p = i;
                
                while (cur) {
                    ans += s[cur-1];
                    cur = par[cur];
                }
                
                reverse(ans.begin(), ans.end());
                cout << ans << ln;
                return;
            }
            
            if (visited[next[i][u]]) continue;
            visited[next[i][u]] = 1;
            par[next[i][u]] = u;
            q.push(next[i][u]);
        }
    }
    
    cout << 67 << ln;
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
