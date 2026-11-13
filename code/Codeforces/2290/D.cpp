// Problem: D. Letters Down
// Contest: Codeforces - Codeforces Round 1134 (Div. 4)
// URL: https://codeforces.com/contest/2290/problem/D
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

void solve() {
    int n; cin >> n;
    string s;
    cin >> s;
    string T; T = s; reverse(T.begin(), T.end());
    if (s == T) {
    	cout << 0 << ln;
    	return;
    }
    
    int ans = 0;
    for (char i = 'z'; i >= 'a'; i--) {
    	bool changed = false;
    	for (int j = 0; j < n/2; j++) {
    		if (s[j] != s[n - j - 1]) {
    			if (s[j] == i) {
    				s[j]--; changed = 1;
    			}
    			else if (s[n-j-1] == i) {
    				s[n-j-1]--; changed = 1;
    			}
    		}
    	}
    	
    	ans += changed;
    	
    	string t; t = s; reverse(t.begin(), t.end());
    	if (t == s) {
    		cout << ans << ln;
    		return;
    	}
    }
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
