// Problem: G. Index Removal
// Contest: Codeforces - Codeforces Round 1119 (Div. 3)
// URL: https://codeforces.com/contest/2259/problem/G
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

void brute(int n, int k, vector<int> a) {
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        if (i == 0 or i == n - 1) {
            ans[i] = 0;
            continue;
        }
        
        int cur = a[i-1];
        int res = 0;
        int p1 = 0, p2 = 0, p3 = 0;
        for (int j = i + 1; j < n; j++) {
            int d = k - (a[j] - cur);
            p1 += k; p2 -= a[j]; p3 += cur;
            // dbg()
            // if (d >= 0 or j == n - 1) dbg(i, j);
            if (d >= 0) break;
            
            res += -d;
            // dbg(d);
            cur = a[j] + d;
        }
        
        ans[i] = res;
    }
    
    for (auto& i : ans) cout << i << " ";
    // cout << ln;
}

void solve2(int n, int k, vector<int> a) {
    vector<int> ans(n, 0), S(n+1, 0);
    for (int i = 0; i < n; i++) {
        S[i+1] = S[i] + a[i];
    }
    for (int i = 0; i < n; i++) {
        if (i == 0 or i == n - 1) {
            ans[i] = 0;
            continue;
        }
        
        int l = i + 1, r = n - 1;
        int res = 0;
        int stop = n;
        while (l <= r) {
            int m = (l + r) / 2;
            
            int fm = k * (m - i) - (a[m] - a[i-1]);
            
            if (fm >= 0) {
                stop = min(stop, m);
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        
        // dbg(i, stop);
        int x = stop - i;
        // dbg(x);
        res = res + k * (x * (x - 1)) / 2;
        // dbg(res);
        res = res + (x - 1) * a[i-1];
        // dbg(res);
        res = res - (S[stop] - S[i+1]);
        // dbg(res);
        
        ans[i] = -res;
    }
    for (auto& i : ans) cout << i << " ";
    cout << ln;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n); for (auto& i : a) cin >> i;
    
    // cout << "\nBRUTE:\n";
    // brute(n, k, a);
    // cout << "\nOPTIMIZED:\n";
    solve2(n, k, a);
}

signed main() {
    fast_cin();
    
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
