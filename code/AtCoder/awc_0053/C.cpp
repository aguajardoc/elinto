// Problem: C - Coverage Area of Radio Towers
// Contest: AtCoder - AtCoder Weekday Contest 0053 Beta
// URL: https://atcoder.jp/contests/awc0053/tasks/awc0053_c
// Memory Limit: 1024 MB
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
    int n;
    cin >> n;
    vector<int> vals;
    vector<vector<int>> str(n);
    for (int i = 0; i < n; i++) {
    	int x, l, r, c;
    	cin >> x >> l >> r >> c;
    	vals.pb(x-l);
    	vals.pb(x+r);
    	
    	str[i] = {x-l, x+r, c};
    }
    
    sort(vals.begin(), vals.end());
    vals.resize(unique(vals.begin(), vals.end()) - vals.begin());
    
    for (auto& i : str) {
    	i[0] = lower_bound(vals.begin(), vals.end(), i[0]) - vals.begin();
    	i[1] = lower_bound(vals.begin(), vals.end(), i[1]) - vals.begin();
    }
    
    vector<int> psum(vals.size() + 1, 0);
    
    for (auto& i : str) {
    	psum[i[0]] += i[2];
    	psum[i[1]+1] -= i[2];
    }
    int cur = 0;
    int mx = 0;
    for (int i = 0; i < psum.size(); i++) {
    	cur += psum[i];
    	mx = max(mx, cur);
    }
    
    cout << mx << ln;
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
