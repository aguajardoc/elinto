// Problem: B. Knife's Pill Farm
// Contest: Codeforces - Codeforces Round 1121 (Div. 2)
// URL: https://codeforces.com/contest/2264/problem/B
// Memory Limit: 256 MB
// Time Limit: 1500 ms
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
    vector<int> a(n); for (auto& i : a) cin >> i;
    int ans = 0;
    int sm1 = 0;
    multiset<int> mne;
    for (int i = 0; i < m - 1; i++) {
        mne.insert(a[i]);
        sm1 += a[i];
    }
    
    ans = -sm1 + m * a[m-1];
    
    for (int i = m-1; i < n-1; i++) {
        sm1 += a[i];
        mne.insert(a[i]);
        sm1 -= *mne.rbegin();
        mne.erase(mne.find(*mne.rbegin()));
        
        ans = max(ans, -sm1 + m * a[i+1]);
    }
    
    cout << ans << ln;
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
