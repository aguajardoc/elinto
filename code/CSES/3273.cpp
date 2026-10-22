// Problem: Colored Chairs
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/3273
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

bool query(int x) {
    cout << "? " << x << ln;
    char r; cin >> r;
    return (r == 'B');
}

void solve() {
    int n;
    cin >> n;
    int start = query(1);
    
    int L = 1, R = n;
    int ans = n+1;
    while (L <= R) {
        int m = (L + R) / 2;
        
        int color = query(m);
        int expected = (m - 1 + start) % 2;
        
        if (color != expected) {
            ans = min(m, ans);
            R = m - 1;
        }
        else {
            L = m + 1;
        }
    }
    
    cout << "! " << ans -1<< ln;
}

signed main() {
    // fast_cin();
    
    // RBRBBRB
    // RBR
    // RRRRR
    // BRBRB
    // BRRBR
    // BBRBR
    // BRBBR
    // BRBRR
    
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
