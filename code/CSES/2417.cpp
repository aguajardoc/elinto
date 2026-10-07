// Problem: Counting Coprime Pairs
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/2417
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

vector<int> p;
bitset<1000010> bs;

void sieve() {
    bs.set();
    bs[0] = bs[1] = false;
    
    for (int i = 2; i <= 1000000; i++) {
        if (!bs[i]) continue;
        for (int j = i * i; j <= 1000000; j+=i) {
            bs[j] = false;
        }
        p.pb(i);
    }
}

const int N = 1000001;
pair<int, int> ct[N];


void get_mask(int x) {
    // dbg(x);
    vector<int> fac;
    for (int i = 0; p[i] * p[i] <= x and i < p.size(); i++) {
        if (bs[x]) break;
        bool flag = false;
        while (x % p[i] == 0) {
            x /= p[i];
            flag = true;
        }
        
        if (flag) fac.pb(p[i]);
    }
    
    if (x > 1) fac.pb(x);
    
    // for (auto& i : fac) {
        // cout << i << " ";
    // }
    // cout << ln;
    
    int n = fac.size();
    for (int i = 1; i < (1ll << n); i++) {
        int num = 1;
        int inc = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1ll << j)) {
                num *= fac[j];
                inc++;
            }
        }
        
        ct[num].first = inc;
        ct[num].second++;
    }
}

void solve() {
    int n; cin >> n;
    vector<int> a(n), masks(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        get_mask(a[i]);
    }
    
    int ans = (n * (n - 1)) / 2;
    for (int i = 1; i <= 1e6; i++) {
        int cost = (ct[i].second * (ct[i].second - 1)) / 2;
        if (!(ct[i].first % 2)) cost *= -1;
        
        ans -= cost;
    }
    
    cout << ans << ln;
}

signed main() {
    fast_cin();
    sieve();
    
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
