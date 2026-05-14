// Problem: D - Splitting a Rope
// Contest: AtCoder - AtCoder Weekday Contest 0066 Beta
// URL: https://atcoder.jp/contests/awc0066/tasks/awc0066_d
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

int n, k;
vector<int> a;

bool f(int x) {
	int seg = 0;
	int cur = 0;
	
	for (int i = 0; i < n; i++) {
		if (a[i] > x) return false;
		if (cur + a[i] > x) {
			seg++;
			cur = a[i];
		}
		else cur += a[i];
	}
	seg++;
	
	return (seg <= k);
}

void solve() {
    cin >> n >> k;
    
    a.assign(n, 0);
    for (auto& i : a) cin >> i;
    
    int l = 0, r = 1e15;
    int ans = INF;
    
    while (l <= r) {
    	int m = (l + r) / 2;
    	
    	int fm = f(m);
    	
    	if (fm) {
    		ans = min(ans, m);
    		r = m - 1;
    	}
    	else {
    		l = m + 1;
    	}
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
