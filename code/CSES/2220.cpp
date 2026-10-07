// Problem: Counting Numbers
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/2220
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
string s, t;
const int n = 20;
int dp[n + 1][2][2][11][2];

int recurse(int idx, int al, int ah, int la, int start) {
    if (idx == n) {
        return 1;
    }
    
    if (dp[idx][al][ah][la][start] != -1) return dp[idx][al][ah][la][start];
    int res = 0;
    for (int i = 0; i <= 9; i++) {
        if (al and i < s[idx] - '0') continue;
        if (ah and i > t[idx] - '0') continue;
        if (i == la and start) continue;
    
        res += recurse(idx + 1, (al ? (i == s[idx] - '0'):0), (ah ? (i == t[idx] - '0'):0), i, start or i);
    }
    
    return dp[idx][al][ah][la][start] = res;
}

void solve() {
    cin >> s >> t;
    while (s.size() < n) s = '0' + s;
    while (t.size() < n) t = '0' + t;
    fill_n(&dp[0][0][0][0][0], (n + 1) * 2 * 2 * 11 * 2, -1);
    
    cout << recurse(0, 1, 1, 0, 0);
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
