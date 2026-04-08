// Problem: D. Minimax Problem
// Contest: Codeforces - Educational Codeforces Round 80 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1288/problem/D
// Memory Limit: 512 MB
// Time Limit: 5000 ms
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
// #define int ll
#define ld long double
#define pb push_back

const ll INF = LLONG_MAX / 4;
const ld PI = acos(-1);
const int MOD = 1000000007;
const double eps = 1e-9;

const int MAXN = 300001;
const int MAXM = 9;
const int MAX2M = 257;

int n, m;
int a[MAXN][MAXM];
int masks[MAX2M];
pair<int, int> ans;

bool f(int x) {
	fill_n(&masks[0], MAX2M, -1);
	for (int i = 0; i < n; i++) {
		int mask = 0;
		int complement = 0;
		vector<int> dont_care;
		for (int j = 0; j < m; j++) {
			if (a[i][j] >= x) {
				mask |= (1 << j);
				dont_care.pb(j);
			}
			else {
				complement |= (1 << j);
			}
		}
		if (mask == ((1 << m) - 1)) {
			ans = {i + 1, i + 1};
			return true;
		}
		
		masks[mask] = i;
		
		// Check if complement available
		int y = dont_care.size();
		for (int j = 0; j < (1 << y); j++) {
			int new_mask = complement;
			
			for (int k = 0; k < y; k++) {
				if (j & (1 << dont_care[k])) {
					new_mask |= (1 << dont_care[k]);
				}
			}
			
			if (masks[new_mask] != -1) {
				ans = {i + 1, masks[new_mask] + 1};
				return true;
			}
		}
	}
	
	return false;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		cin >> a[i][j];
    	}
    }
    
    int l = 0, r = 1e9 + 67;
    int res = -1;
    while (l <= r) {
    	int M = (l + r) / 2;
    	bool fm = f(M);
    	
    	if (fm) {
    		res = max(res, M);
    		l = M + 1;
    	}
    	else r = M - 1;
    }
    f(res);
    
    cout << ans.first << " " << ans.second << ln;
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
