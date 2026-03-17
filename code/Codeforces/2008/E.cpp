// Problem: E. Alternating String
// Contest: Codeforces - Codeforces Round 970 (Div. 3)
// URL: https://codeforces.com/contest/2008/problem/E
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
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    vector<vector<int>> odd(26, vector<int> (n+1, 0)), even = odd;
    for (int i = 0; i < 26; i++) {
    	for (int j = 0; j < n; j++) {
    		if (j % 2){
    			odd[i][j+1] = odd[i][j] + (s[j] != (i + 'a'));
    			even[i][j+1] = even[i][j];
    		}
    		else {
    			even[i][j+1] = even[i][j] + (s[j] != (i + 'a'));
    			odd[i][j+1] = odd[i][j];
    		}
    	}
    }
    
    int ans = INF;
    if (n % 2 == 0) {
    	int L = INF, R = INF;
    	for (int i = 0; i < 26; i++) {
    		L = min(L, odd[i][n]);
    		R = min(R, even[i][n]);
    	}
    	
    	cout << L + R << ln;
    	return;
    }
    
    for (int i = 0; i < n; i++) {
    	int L = INF, R = INF;
    	for (int j = 0; j < 26; j++) {
    		L = min(L, odd[j][i] + even[j][n] - even[j][i+1]);
    		R = min(R, even[j][i] + odd[j][n] - odd[j][i+1]);
    	}
    	
    	// dbg(L, R);
    	
    	ans = min(ans, 1 + L + R);
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
