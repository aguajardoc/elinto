// Problem: D. The Wu
// Contest: Codeforces - Codeforces Round 502 (in memory of Leopoldo Taravilse, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1017/problem/D
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
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> w(n);
    for (auto& i : w) cin >> i;
    
    vector<int> ct(1 << n, 0);
    vector<vector<int>> res(1 << n);
    for (int i = 0; i < m; i++) {
    	string s;
    	cin >> s;
    	reverse(s.begin(), s.end());
    	ct[stoi(s, NULL, 2)]++;
    }
    
    for (int i = 0; i < (1ll << n); i++) {
    	string s;
    	for (int j = 0; j < n; j++) {
    		if (i & (1ll << j)) s += '1';
    		else s += '0';
    	}
    	
    	vector<int> subres(101, 0), pres(102, 0);
    	
    	for (int j = 0; j < (1ll << n); j++) {
    		int R = 0;
    		for (int k = 0; k < n; k++) {
    			if ((i & (1ll << k)) == (j & (1ll << k))) {
    				R += w[k];
    			}
    		}
    		if (R > 100) continue;
    		// dbg(i, j);
    		// dbg(R, ct[j]);
    		subres[R] += ct[j];
    	}
    	// cout << ln;
    	
    	for (int j = 0; j <= 100; j++) {
    		pres[j+1] = pres[j] + subres[j];
    	}
    	pres.erase(pres.begin());
    	
    	res[i] = pres;
    }
    
    while(q--) {
    	string s;
    	cin >> s;
    	reverse(s.begin(), s.end());
    	int x;
    	cin >> x;
    	int num = stoi(s, NULL, 2);
    	cout << res[num][x] << ln;
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
