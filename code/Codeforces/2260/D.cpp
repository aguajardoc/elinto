// Problem: D. Signs of Prefix Sums
// Contest: Codeforces - Educational Codeforces Round 194 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2260/problem/D
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

struct Seg {
    int count;
    char type;
};

bool checkOne(vector<Seg>& a) {
    int n = a.size();
    if (n == 1) return 1;
    
    for (int i = 1; i < n; i++) {
        if (a[i].type == '0' or a[i-1].type == '0') {
            if (a[i-1].count % 2 == 0) return false;
            if (i != n - 1 and a[i].count % 2 == 0) return false;
            
            continue;
        }
        return 0;
    }
    
    return 1;
}

bool checkTwo(vector<Seg>& a) {
    int n = a.size();
    if (n == 1) return 1;
    
    for (int i = 1; i < n-1; i++) {
        if (a[i].type == '0') {
            i++; // safe to skip next sign
            continue;
        }
        if (a[i].count == 2 and a[i+1].type != '0') {
            return 0;
        }
    }
    
    return 1;
}

void solve() {
    int n; cin >> n; string s; cin >> s;
    int consec = 0;
    for (int i = 1; i < n; i++) consec |= (s[i] == '0' and s[i-1] == '0');
    if (s[0] == '0' or consec) {
        cout << -1 << ln; return;
    }
    
    vector<Seg> segs;
    char cty = s[0];
    int count = 1;
    for (int i= 1; i < n; i++) {
        if (s[i] != cty) {
            segs.pb({count, cty});
            cty = s[i]; count = 1;
        }
        else count++;
    }
    segs.pb({count, cty});
    
    bool one = checkOne(segs);
    bool two = checkTwo(segs);
    
    if (one) {
        cout << 1 << ln;
        return;
    }
    if (two) {
        cout << 2 << ln;
        return;
    }
    cout << 3 << ln;
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
