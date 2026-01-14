// Problem: E. Enemy is weak
// Contest: Codeforces - Codeforces Beta Round 57 (Div. 2)
// URL: https://codeforces.com/problemset/problem/61/E
// Memory Limit: 256 MB
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
#define int ll
#define ld long double
#define pb push_back

const ll INF = LLONG_MAX / 4;
const ld PI = acos(-1);
const int MOD = 1000000007;
const double eps = 1e-9;

const int TREE_SIZE = 1 << 20;

int st[2*TREE_SIZE];

void update(int i, int x) {
	i += TREE_SIZE;
	st[i] = x;
	i>>=1;
	while(i) {
		st[i] = st[2*i] + st[2*i+1];
		i>>=1;
	}
}

int query(int l, int r) {
	l += TREE_SIZE;
	r += TREE_SIZE;
	int res = 0;
	while (l <= r) {
		if (l&1) res += st[l++];
		if (!(r&1)) res += st[r--];
		
		l >>= 1;
		r >>= 1;
	}
	
	return res;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i : a) cin >> i;
    
    vector<int> vals = a;
    sort(vals.begin(), vals.end());
    for (auto& i : a) {
    	i = distance(vals.begin(), lower_bound(vals.begin(), vals.end(), i));
    }
    
    vector<int> pairs(n), triplets(n);
    for (int i = n - 1; i >= 0; i--) {
    	// Get how many are less than me
    	int x = query(0, a[i]);
    	pairs[i] = x;
    	
    	update(a[i], 1);
    }
    
    for (int i = 0; i < n; i++) update(i, 0);
    
    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
    	int x = query(0, a[i]);
    	// dbg(x);
    	ans += x;
    	
    	update(a[i], pairs[i]);
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
