// Problem: B. Prime Matrix
// Contest: Codeforces - TC Tec 2026 Contest 1 (Avanzado)
// URL: https://codeforces.com/group/eZBA1VtmXM/contest/690676/problem/B
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

bitset<1000100> bs;
vector<int> p;

void sieve() {
	bs.set();
	bs[0] = bs[1] = false;
	
	for (int i = 2; i <= 1000000; i++) {
		if (!bs[i]) continue;
		for (int j = i * i; j <= 1000000; j+= i) {
			bs[j] = false;
		}
		
		p.pb(i);
	}
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		cin >> mat[i][j];
    	}
    }
    
    int ans = INF;
    
    // do all rows
    for (int i = 0; i < n; i++) {
    	int local = 0;
    	for (int j = 0; j < m; j++) {
    		local += (*lower_bound(p.begin(), p.end(), mat[i][j])) - mat[i][j];
    	}
    	
    	ans = min(ans, local);
    }
    
    
    // do all cols
    for (int i = 0; i < m; i++) {
    	int local = 0;
    	for (int j = 0; j < n; j++) {
    		local += (*lower_bound(p.begin(), p.end(), mat[j][i]))- mat[j][i];
    		
    		// dbg(i, j, local);
    	}
    	
    	// dbg(i, local);
    	
    	ans = min(ans, local);
    }
    
    cout << ans << ln;
}

signed main() {
    fast_cin();
    sieve();
    
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
