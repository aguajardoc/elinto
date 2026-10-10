// Problem: M. Mathematics Enthusiastic
// Contest: Codeforces - 2026 XVIII Donald Knuth Annual Programming Contest by ESCOM-IPN
// URL: https://codeforces.com/gym/106722/problem/M
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

void solve() {
    int n; cin >> n;
    int tn = 1; for (int i = 0; i < n; i++) tn *= 3;
    vector<string> grid(tn, string(tn, '.'));
    
    vector<string> tile = {"*"};
    
    for (int i = 1; i <= n; i++) {
        vector<string> new_tile(tile.size() * 3, string(tile.size() * 3, '.'));
        int m = new_tile.size();
        for (int j = 0, cur = 0; j < m; j += m/3) {
            for (int k = 0; k < m; k+=m/3, cur++) {
                if (cur%2) continue;
                for (int x = 0; x < m/3; x++) {
                    for (int y = 0; y < m/3; y++) {
                        new_tile[j+x][k+y] = tile[x][y];
                    }
                }
            }
        }
        
        tile = new_tile;
    }
    
    for (auto& i : tile) {
        cout << i << ln;
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
