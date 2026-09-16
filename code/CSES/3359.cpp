// Problem: Minimal Grid Path
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/3359
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

int n, visited[3001][3001];
string grid[3001];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> grid[i];
        grid[i] = 'X' + grid[i];
    }
    
    queue<pair<int, int>> q;
    q.push({1, 1});
    string ans; ans += grid[1][1];
    visited[1][1] = 1;
    
    while (!q.empty()) {
        queue<pair<int, int>> aux;
        char mn = 'Z';
        while (!q.empty()) {
            aux.push(q.front());
            
            if (q.front().first != n) {
                mn = min(mn, grid[q.front().first + 1][q.front().second]);
            }
            
            if (q.front().second != n) {
                mn = min(mn, grid[q.front().first][q.front().second + 1]);
            }
            
            q.pop();
        }
        
        while (!aux.empty()) {
            if (aux.front().first != n and !visited[aux.front().first+1][aux.front().second] and grid[aux.front().first + 1][aux.front().second] == mn) {
                q.push({aux.front().first + 1, aux.front().second});
                visited[aux.front().first+1][aux.front().second] = 1;
            }
            
            if (aux.front().second != n and !visited[aux.front().first][aux.front().second+1] and grid[aux.front().first][aux.front().second + 1] == mn) {
                q.push({aux.front().first, aux.front().second + 1});
                visited[aux.front().first][aux.front().second + 1] = 1;
            }
            
            aux.pop();
        }
        
        ans += mn;
    }
    
    ans.pop_back();
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
