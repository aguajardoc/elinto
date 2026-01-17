// Problem: D. Spider's Web
// Contest: Codeforces - Codeforces Round 133 (Div. 2)
// URL: https://codeforces.com/contest/216/problem/D
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
    vector<vector<int>> AP(n);
    for (int i = 0; i < n; i++) {
    	int m;
    	cin >> m;
    	AP[i] = vector<int> (m, 0);
    	for (int j = 0; j < m; j++) {
    		cin >> AP[i][j];
    	}
    	
    	sort(AP[i].begin(), AP[i].end());
    }
    
    int ans = 0;
    
    for (int i = 0; i < n; i++) {
    	int L = i - 1;
    	L = ((L % n) + n) % n;
    	int R = (i + 1) % n;
    	
    	for (int j = 0; j < (int)AP[i].size() - 1; j++) {
    		// How many in AP[L] from j to j + 1
    		int LQ = AP[i][j];
    		int RQ = AP[i][j+1];
    		
    		int LC = distance(lower_bound(AP[L].begin(), AP[L].end(), LQ), upper_bound(AP[L].begin(), AP[L].end(), RQ));
    		int RC = distance(lower_bound(AP[R].begin(), AP[R].end(), LQ), upper_bound(AP[R].begin(), AP[R].end(), RQ));
    		
    		if (LC != RC) ans++;
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
