// Problem: D. R2D2 and Droid Army
// Contest: Codeforces - Codeforces Round 291 (Div. 2)
// URL: https://codeforces.com/problemset/problem/514/D
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

const int TREE_SIZE = 1 << 20;
int st[5][2*TREE_SIZE];

void update(int m, int i, int x) {
	i += TREE_SIZE;
	st[m][i] = x;
	i >>= 1;
	while (i) {
		st[m][i] = max(st[m][2*i], st[m][2*i + 1]);
		
		i >>= 1;
	}
}

int query(int m, int l, int r) {
	l += TREE_SIZE;
	r += TREE_SIZE;
	int res = 0;
	while (l <= r) {
		if (l&1) res = max(res, st[m][l++]);
		if (!(r&1)) res = max(res, st[m][r--]);
		l>>=1;
		r>>=1; 
	}
	
	return res;
}

vector<int> ansv;

bool f(int x, int m, int n, int shots) {
	int minsum = 1e9;
	for (int i = 0; i < n; i++) {
		int j = i + x - 1;
		if (j >= n) continue;
		
		int local = 0;
		vector<int> lans;
		for (int k = 0; k < m; k++) {
			int y = query(k, i, j);
			local += y;
			lans.pb(y);
		}
		
		if (local < minsum) {
			ansv = lans;
			minsum = local;
		}
	}
	
	return (minsum <= shots);
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		int x;
    		cin >> x;
    		update(j, i, x);
    	}
    }
    
    int ans = 0;
    int l = 1, r = n;
    while (l <= r) {
    	int mid = (l + r) / 2;
    	
    	bool fm = f(mid, m, n, k);
    	
    	if (fm) {
    		ans = max(ans, mid);
    		l = mid + 1;
    	}
    	else {
    		r = mid - 1;
    	}
    }
    
    f(ans, m, n, k);
    
    for (auto& i : ansv) {
    	cout << i << " ";
    }
    cout << ln;
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
