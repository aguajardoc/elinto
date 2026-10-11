// Problem: K. Fallout Van Buren: Wasteland Survival
// Contest: Codeforces - 2026 II Abraham Macias Annual Programming Contest by ESCOM-IPN
// URL: https://codeforces.com/gym/106721/problem/K
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

vector<int> a, d;

bool poss(int x) {
    int n = a.size();
    
    for (int damage = 1; damage <= x; damage++) {
        int armor = x - damage;
        
        bool valid = true;
        for (int i = 0; i < n; i++) {
            int hits_rec = armor / a[i] + min(1ll, armor % a[i]) + 1;
            int hits_dealt = d[i] / damage + min(1ll, d[i] % damage) + 1;
            
            if (hits_dealt > hits_rec) valid = false;
        }
        
        if (valid) return true;
    }
    
    return false;
}

void solve() {
    int n; cin >> n;
    a.resize(n);
    d.resize(n);
    for (int i = 0;i < n; i++) {
        cin >> a[i] >> d[i];
    }
    
    int l = 0, r = 2000;
    int x = INF;
    while (l <= r) {
        int m = (l + r) / 2;
        
        bool fm = poss(m);
        if (fm) {
            x = min(x, m);
            r = m - 1;
        }
        else l = m + 1;
    }
    
    
    cout << x << ln;
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
