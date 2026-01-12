// Problem: Maximum Sum
// Contest: SPOJ - Classical
// URL: https://www.spoj.com/problems/KGSS/
// Memory Limit: 1536 MB
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

const int TREE_SIZE = 1<<20;
pair<int, int> st[2 * TREE_SIZE];

void update(int i, int x) {
	int idx = i;
	i += TREE_SIZE;
	st[i] = {x, 0};
	i >>= 1;
	while(i) {
		pair<int, int> left = st[2 * i];
		pair<int, int> right = st[2 * i+1];
		
		vector<int> y = {left.first, left.second, right.first, right.second};
		sort(y.rbegin(), y.rend());
		
		st[i] = {y[0], y[1]};
		
		i>>=1;
	}
}

pair<int, int> query(int l, int r) {
	l += TREE_SIZE;
	r += TREE_SIZE;
	pair<int, int> res = {-1, -1};
	while (l <= r) {
		if(l&1) {
			
			pair<int, int> left = res;
			pair<int, int> right = st[l];
			
			vector<int> y = {left.first, left.second, right.first, right.second};
			sort(y.rbegin(), y.rend());
			
			res = {y[0], y[1]};
			
			l++;
		}
		if(!(r&1)) {
			
			pair<int, int> left = res;
			pair<int, int> right = st[r];
			
			vector<int> y = {left.first, left.second, right.first, right.second};
			sort(y.rbegin(), y.rend());
			
			res = {y[0], y[1]};
			
			
			r--;
		}
		
		l >>= 1;
		r >>= 1;
	}
	
	return res;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
    	int x;
    	cin >> x;
    	update(i, x);
    }
    
    int q;
    cin >> q;
    while(q--) {
    	char type; int l, r;
    	cin >> type >> l >> r;
    	
    	if (type == 'Q') {
    		l--, r--;
    		pair<int, int> A1 = query(l, r);
    		
    		cout << A1.first + A1.second << ln;
    	}
    	else {
    		l--;
    		update(l, r);
    	}
    	
    	// pair<int, int> test = query(0, n - 1);
    	// cout << test.first << " " << test.second << ln;
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
