// Problem: E. Rock, Paper, Scissors
// Contest: Codeforces - Codeforces Round 674 (Div. 3)
// URL: https://codeforces.com/contest/1426/problem/E
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

void solve() {
    int n;
    cin >> n;
    int a[3], b[3];
    for (int i = 0; i < 3; i++) {
    	cin >> a[i];
    }
    for (int i = 0; i < 3; i++) {
    	cin >> b[i];
    }
    
    int mx = 0;
    for (int i = 0; i < 3; i++) {
    	mx += min(a[i], b[(i + 1) % 3]);
    }
    
    int mn = 0;
    
    for (int i = 0; i < 3; i++) {
    	int forced = 0;
    	int fi = a[i];
    	for (int j = 0; j < 3; j++) {
    		if ((i + 1) % 3 != j){
    			forced+=min(fi, b[j]);
    			fi -= min(fi, b[j]);
    		}
    	}
    	
    	// dbg(forced);
    	int wins = min(fi, b[(i + 1) % 3]);
    	// dbg(wins);
    	mn = max(mn, wins);
    }
    
    cout << mn << " " << mx << ln;
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
