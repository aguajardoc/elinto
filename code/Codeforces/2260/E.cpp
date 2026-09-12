// Problem: E. Cyclic Balance
// Contest: Codeforces - Educational Codeforces Round 194 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2260/problem/E
// Memory Limit: 512 MB
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
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<vector<int>> pref(2, vector<int>(n + 1, 0)), runs = pref;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            pref[j][i+1] = pref[j][i];
        }
        
        pref[s[i]-'0'][i+1]++;
        
        for (int j = 0; j < 2; j++) {
            runs[j][i+1] = runs[j][i];
        }
        
        if (i and s[i] != s[i-1]) runs[s[i]-'0'][i+1]++;
    }
    
    while (m--) {
        int l, r;
        cin >> l >> r;
        
        int ct0 = pref[0][r] - pref[0][l-1];
        int ct1 = pref[1][r] - pref[1][l-1];
        int b0 = runs[0][r] - runs[0][l];
        int b1 = runs[1][r] - runs[1][l];
        
        int d = b0 + b1;
        if (s[r-1] != s[l-1]) d++;
        
        int C = d/2;
        int A = ct0 - C;
        int B = ct1 - C;
        
        int k = max({
            ct0/2 + ct0%2,
            ct1/2 + ct1%2,
            C,
            (A+B+C)/3 + min(1ll,(A+B+C)%3)
        });
        
        
        cout << k * 4 - (r - l + 1) << ln;
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
