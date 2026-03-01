// Problem: H. Heating Up
// Contest: Codeforces - 2021-2022 ICPC Northwestern European Regional Programming Contest (NWERC 2021)
// URL: https://codeforces.com/gym/104064/problem/H
// Memory Limit: 512 MB
// Time Limit: 3000 ms
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
int st[2][2 * TREE_SIZE];

void update(int i, int x, int tree) {
	i += TREE_SIZE;
	st[tree][i] = x;
	
	i >>= 1;
	
	while (i) {
		st[tree][i] = max(st[tree][2*i], st[tree][2*i + 1]);
		
		i >>= 1;
	}
}

int query(int l, int r, int tree) {
	l += TREE_SIZE;
	r += TREE_SIZE;
	int res = 0;
	
	while (l <= r) {
		if (l&1) res = max(res, st[tree][l++]);
		if (!(r&1)) res = max(res, st[tree][r--]);
		
		l >>= 1;
		r >>= 1;
	}
	
	return res;
}

int BS(int L, int R, int x, int tree, int n) {
	int l = L, r = R;
	int ans = INF;
	
	// int tql = query(L, L, tree);
	// int tqr = query(R, R, tree);
	// dbg(tql, tqr);
	
	while (l <= r) {
		int m = (l + r) / 2;
		
		int num = query(L, m, tree);
		// dbg(num, m);
		
		if (num == x) {
			ans = min(ans, m);
			r = m - 1;
		}
		else {
			l = m + 1;
		}
	}
	
	if (ans == INF) return INF;
	return ans - L;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int mx = 0;
    int mxid = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	sum += a[i];
    	if (a[i] > mx) {
    		mx = a[i];
    		mxid = i;
    	}
    }
    
    vector<int> altered;
    for (int i = mxid + 1; i < mxid + n; i++) {
    	altered.push_back(a[i%n]);
    }
    
    // Build segtrees
    vector<int> sorted = a;
    sort(sorted.rbegin(), sorted.rend());
    
    vector<int> R = altered;
    reverse(R.begin(), R.end());
    vector<int> L = altered;
    
    for (int i = 0; i < n - 1; i++) {
    	update(i, L[i], 0);
    	update(i, R[i], 1);
    }
    
    vector<int> prefL(n, 0), prefR = prefL;
    for (int i = 0; i < n - 1; i++) {
    	prefL[i + 1] = prefL[i] + L[i];
    	prefR[i + 1] = prefR[i] + R[i];
    }
    
    // compute answer!
    int cur = mx;
    int ele = mx;
    int finale = cur + ele;
    
    int RL = 0, RR = 0;
    
    for (int i = 1; i < n; i++) {
    	// Element to find
    	int next = sorted[i];
    	
    	// Check step count for each
    	// dbg(i, next);
    	int STEPL = BS(RL, n - 2 - RR, next, 0, n - 1);
    	int STEPR = BS(RR, n - 2 - RL, next, 1, n - 1);
    	
    	
    	// dbg(STEPL, STEPR);
    	
    	// If none found it, we've used it already
    	if (STEPL == INF and STEPR == INF) continue;
    	
    	// Calculate cost for each route
    	int idxNL = RL + STEPL;
    	int idxNR = RR + STEPR;
    	
    	// dbg(prefL[idxNL]);
    	// dbg(prefL[RL]);
    	
    	int COSTL = prefL[idxNL] - prefL[RL];
    	int COSTR = prefR[idxNR] - prefR[RR];
    	
    	// dbg(COSTL, COSTR);
    	
    	// Execute algo
    	if (COSTL < COSTR) {
    		for (int j = 0; j <= STEPL; j++) {
    			cur += L[RL];
    			ele = L[RL];
    			// dbg(cur, ele);
    			finale = max(finale, cur + ele);
    			RL++;
    		}
    	}
    	else {
    		for (int j = 0; j <= STEPR; j++) {
    			cur += R[RR];
    			ele = R[RR];
    			// dbg(cur, ele);
    			finale = max(finale, cur + ele);
    			RR++;
    		}
    	}
    	
    	// dbg(finale);
    	
    	// cout << ln;
    }    
    
    int ans = finale - sum;
    ans = max(ans, 0ll);
    
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
