// Problem: Prefix Sum Queries
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/2166
// Memory Limit: 512 MB
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

const int TREE_SIZE = 1 << 20;
// first = best prefix, second all of it
pair<int, int> st[2*TREE_SIZE];

void update(int i, int x) {
	i += TREE_SIZE;
	st[i] = {x, x};
	i >>= 1;
	
	while(i) {
		st[i].first = max({st[2*i].second + st[2*i+1].first, st[2*i].first});
		st[i].second = st[2*i].second + st[2*i+1].second;
		
		i >>= 1;
	}
}

int query(int l, int r) {
	l += TREE_SIZE;
	r += TREE_SIZE;
	int res = 0;
	pair<int, int> L = {0, 0}, R = {0, 0};
	
	
	while (l <= r) {
		if (l&1) {
			L.first = max(L.second + st[l].first, L.first);
			L.second = L.second + st[l].second;
			l++;
		}
		if (!(r&1)) {
			R.first = max(st[r].first, st[r].second + R.first);
			R.second = R.second + st[r].second;
			r--;
		}
		
		l >>= 1;
		r >>= 1;
	}
	
	return max(L.second + R.first, L.first);
}

void solve() {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
    	int x;
    	cin >> x;
    	update(i, x);
    }
    
    while(q--) {
    	int type;
    	cin >> type;
    	if (type == 1) {
    		int k, u;
    		cin >> k >> u;
    		k--;
    		update(k, u);
    	}
    	else {
    		int l, r;
    		cin >> l >> r;
    		l--, r--;
    		int ans = query(l ,r);
    		ans = max(ans, 0ll);
    		
    		cout << ans << ln;
    	}
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
