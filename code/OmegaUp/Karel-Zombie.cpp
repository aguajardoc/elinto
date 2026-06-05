// Problem: 20192. Karel-Zombie
// Contest: omegaUp
// URL: https://omegaup.com/arena/problem/Karel-Zombie/
// Memory Limit: 32 MB
// Time Limit: 100000 ms
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

int n, k, x, y;

int get_at_row(int r, int d) {
    int dist = abs(r - x);
    if (d < dist) return 0;
    d -= dist;
    
    int at_row = 2 * d + 1;
    
    int shift = (at_row + 1) / 2;
    return shift * shift;
}

int get_at_col(int c, int d) {
    int dist = abs(c - y);
    if (d < dist) return 0;
    d -= dist;
    
    int at_row = 2 * d + 1;
    
    int shift = (at_row + 1) / 2;
    return shift * shift;
}

int get_at_corner(int r, int c, int dir, int d) {
    int dist = abs(r - x) + abs(c - y);
    if (d < dist) return 0;
    // dbg(dir, dist, d);
    
    int L = 0, R = 1e9;
    int ans = 0;
    while (L <= R) {
        int m = (L + R) / 2;
        
        int nx = r, ny = c;
        
        if (dir == 0) {
            // -, -
            nx -= m;
        }
        else if (dir == 1) {
            // -, +
            nx -= m;
        }
        else if (dir == 2) {
            // +, -
            nx += m;
        }
        else {
            nx += m;
        }
        
        int ndist = abs(nx - x) + abs(ny - y);
        
        if (d < ndist) {
            R = m - 1; 
        }
        else {
            // dbg(m, ans);
            ans = max(ans, m);
            L = m + 1;
        }
    }
    
    ans++;
    // dbg(dir, dist, d);
    // dbg(ans);
    int aff = (ans * (ans + 1)) / 2;
    // dbg(dir);
    // dbg(ans, aff);
    
    return aff;
}

int f(int d) {
    int ans = 2 * d * d + 2 * d + 1;
    // subtract from row -1
    int RM1 = get_at_row(-1, d);
    // subtract from row n
    int RMN = get_at_row(n, d);
    // subtract from col -1
    int CM1 = get_at_col(-1, d);
    // subtract from col n
    int CMN = get_at_col(n, d);
    
    // add from corner up left from (-1, -1)
    int LU = get_at_corner(-1, -1, 0, d);
    // add from corner up right from (-1, n)
    int RU = get_at_corner(-1, n, 1, d);
    // add from corner down left from (n, -1)
    int LD = get_at_corner(n, -1, 2, d);
    // add from corner down right from (n, n)
    int RD = get_at_corner(n, n, 3, d);
    
    
    // dbg(d);
    // dbg(ans);
    // dbg(RM1);
    // dbg(RMN);
    // dbg(CM1);
    // dbg(CMN);
    // dbg(LU);
    // dbg(RU);
    // dbg(LD);
    // dbg(RD);
    
    ans -= RM1;
    ans -= RMN;
    ans -= CM1;
    ans -= CMN;
    
    // dbg(ans);
    
    ans += LU;
    ans += RU;
    ans += LD;
    ans += RD;
    
    // dbg(ans);
    
    return ans;
}

void solve() {
    cin >> n >> k >> x >> y;
    x--, y--;
    swap(x, y);
    
    int l = 0, r = 2 * n;
    int ans = INF;
    while (l <= r) {
        int m = (l + r) / 2;
        
        int fm = f(m);
        
        if (fm >= k) {
            ans = min(ans, m + 1);
            r = m - 1;
        }
        else {
            l = m + 1;
        }
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
