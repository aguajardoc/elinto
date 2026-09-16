// Problem: D. Disco Elysium
// Contest: Codeforces - 2026 ICPC Gran Premio de Mexico Repechaje
// URL: https://codeforces.com/gym/106710/problem/D
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
#define int ll
#define ld long double
#define pb push_back

const ll INF = LLONG_MAX / 4;
const ld PI = acos(-1);
const int MOD = 1000000007;
const double eps = 1e-9;

void solve() {
    int n, k; cin >> n >> k;
    map<int, int> ct;
    vector<int> a(n); 
    for (auto& i : a) {
        cin >> i;
        ct[i]++;
    }
    
    vector<int> proc;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        if (proc.empty() or proc.back() != a[i]) {
            proc.pb(a[i]);
            ct[a[i]]--;
        }
    }
    
    for (auto& [x, c] : ct) {
        while (c > 0) {
            c--;
            proc.pb(x);
        }
    }
    
    int mex = 0;
    for (int i = 0; i < proc.size(); i++) {
        if (proc[i] == mex) mex++;
        else {
            if (k) {
                k--;
                proc.pop_back();
                i--;
                mex++;
            }
            else break;
        }
    }
    
    cout << mex << ln;
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
