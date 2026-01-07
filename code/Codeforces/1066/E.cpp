// Problem: E. Binary Numbers AND Sum
// Contest: Codeforces - Codeforces Round 515 (Div. 3)
// URL: https://codeforces.com/contest/1066/problem/E
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
const int MOD = 998244353;
const double eps = 1e-9;

void solve() {
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    if(n > m) {
    	string surp(n - m, '0');
    	t = surp + t;
    }
    else {
    	string surp(m - n, '0');
    	s = surp + s;
    }
    
    int N = max(n, m);
    
	vector<int> res(N, 0);
	int cur = 0;
	for (int i = 0; i < N; i++) {
		if (t[i] == '1') cur++;
		if (s[i] == '1') res[i] = cur;
	}
	
	reverse(res.begin(), res.end());
	int ans = 0;
	int pow = 1;
	for (int i = 0; i < res.size(); i++) {
		ans += pow * res[i];
		
		pow *= 2;
		pow %= MOD;
		ans %= MOD;
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
