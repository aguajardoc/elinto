// Problem: J. Juicy Revenge
// Contest: Codeforces - 2026 XVIII Donald Knuth Annual Programming Contest by ESCOM-IPN
// URL: https://codeforces.com/gym/106722/problem/J
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
// #define int ll
#define ld long double
#define pb push_back

const ll INF = LLONG_MAX / 4;
const ld PI = acos(-1);
const int MOD = 1000000007;
const double eps = 1e-9;

struct Prob {
    int x, p, q;
};
int n;

Prob a[5001];
ld dp[2][5001];

void solve() {
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].p >> a[i].q;
    }
    
    fill_n(&dp[0][0], 2*5001, -INF);
    
    dp[0][0] = 0;
    dp[1][0] = 0;
    
    for (int i = 1; i <= n; i++) {
        int now = i % 2;
        int last = 1 - now;
        ld expected_gain = (ld)a[i-1].x * (ld)a[i-1].p / (ld)a[i-1].q;
        for (int j = 1; j <= n; j++) {
            ld cur_gain = expected_gain * j;
            dp[now][j] = max(
                dp[last][j-1] + cur_gain,
                dp[last][j]
            );
        }
        
        
    }
    
    for (int i = 1; i <= n; i++) {
        cout << fixed << setprecision(10) << dp[n%2][i] << " ";
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
