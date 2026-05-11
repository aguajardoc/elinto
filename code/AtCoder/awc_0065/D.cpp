// Problem: D - Total Sales Within Delivery Range
// Contest: AtCoder - AtCoder Weekday Contest 0065 Beta
// URL: https://atcoder.jp/contests/awc0065/tasks/awc0065_d
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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> pre(1002, vector<int> (1002, 0)), psum = pre;
    
    for (int i = 0; i < n; i++) {
    	int x, y, c;
    	cin >> x >> y >> c;
    	
    	pre[x][y+1] += c;
    }
    
    for (int i = 0; i <= 1001; i++) {
    	int cur = 0;
    	for (int j = 0; j <= 1001; j++) {
    		cur += pre[i][j];
    		psum[i][j] = cur;
    	}
    }
    
    for (int i = 0; i < m; i++) {
    	int p, q, k;
    	cin >> p >> q >> k;
    	
    	bool phase = 0;
    	int res = 0;
    	for (int x = p - k, l = q, r = q; x <= p + k; x++) {
    		if (x >= 0 and x <= 1001) {
    			int L = max(l, 0ll);
    			int R = min(r+1, 1001ll);
    			
    			res += psum[x][R] - psum[x][L];
    		}
    		
    		if ((r - l) >= 2 * k) {
    			phase = 1;
    		}
    		if (!phase) {
    			l--;
    			r++;
    		}
    		else {
    			l++;
    			r--;
    		}
    	}
    	
    	cout << res << ln;
    }
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
