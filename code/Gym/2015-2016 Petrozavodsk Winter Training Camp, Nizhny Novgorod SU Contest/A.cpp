// Problem: A. Prevent a Galactic War!
// Contest: Codeforces - 2015-2016 Petrozavodsk Winter Training Camp, Nizhny Novgorod SU Contest
// URL: https://codeforces.com/gym/100960/problem/A
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
// #pragma GCC optimize ("Ofast")
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
    vector<vector<ld>> c(n, vector<ld>(n, 0));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int cx;
            cin >> cx;
            c[i][j] = cx;
        }
    }
    
    vector<ld> yold(n), ynew(n);
    
    for (auto& i : yold) cin >> i;
    for (auto& i : ynew) cin >> i;
    
    vector<ld> xold(n);
    
    for (int i = 0; i < n; i++) {
        xold[i] = yold[i];
        for (int j = 0; j < n; j++) {
            xold[i] += c[i][j];
        }
    }
    
    vector<ld> xnew = ynew;
    vector<ld> ans(n), ratio(n);
    for (int X = 0; X <= 10; X++) {
        for (int i = 0; i < n; i++) {
            ratio[i] = xnew[i] / xold[i];
        }
        
        for (int i = 0; i < n; i++) {
            ans[i] = ynew[i];
            for (int j = 0; j < n; j++) {
                ans[i] += c[i][j]*ratio[j];
                
            }   
        }
        
        
        xnew = ans;   
    }
    
    for (auto& i : ans) {
        cout << fixed << setprecision(10) << i << " ";
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