// Problem: D - Multiple of 2019
// Contest: AtCoder - AtCoder Beginner Contest 164
// URL: https://atcoder.jp/contests/abc164/tasks/abc164_d
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

ll binexp(ll a, ll b) {
	ll res = 1;
	while(b) {
		if (b&1) {
			res = (res * a) % 2019;
		}
		a = (a * a) % 2019;
		
		b >>= 1;
	}
	
	return res;
}

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    
    int cur = 0;
    int p = 1;
    vector<int> ct(2019, 0);
    ct[0] = 1;
    for (int i = n - 1; i >= 0; i--) {
    	cur += (s[i] - '0') * p;
    	cur %= 2019;
    	
		ct[cur]++;
    	p *= 10;
    	p %= 2019;
    }
    
    int ans = 0 ;
    for (int i = 0; i < 2019; i++) {
    	int x = ct[i];
    	ans += (x * (x - 1)) / 2;
    }
    
    cout << ans << ln;
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
