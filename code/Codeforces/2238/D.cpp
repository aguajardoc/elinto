// Problem: D. Storming Arasaka
// Contest: Codeforces - Codeforces Round 1106 (Div. 2)
// URL: https://codeforces.com/contest/2238/problem/D
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

vector<int> p;
bitset<1000001> bs;

void sieve() {
    bs.set();
    bs[0] = bs[1] = false;
    
    for (int i = 2; i <= 1000000; i++) {
        if (!bs[i]) continue;
        for (int j = i * i; j <= 1000000; j+= i) {
            bs[j] = false;
        }
        p.pb(i);
    }
}

void solve() {
    int n;
    cin >> n;
    map<int, int> fac;
    int x = n;
    int tot = 0;
    for (int i = 0; i < p.size() and p[i] * p[i] <= x; i++) {
        while (x % p[i] == 0) {
            fac[p[i]]++;
            tot++;
            x /= p[i];
        }
    }
    if (x > 1) {
        fac[x]++;
        tot++;
    }
    
    int ans = fac.size() + tot - 1;
    
    cout << ans << ln;
}

signed main() {
    fast_cin();
    sieve();
    
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
