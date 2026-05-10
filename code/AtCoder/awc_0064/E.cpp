// Problem: E - Reduce Inversions with Adjacent Swaps
// Contest: AtCoder - AtCoder Weekday Contest 0064 Beta
// URL: https://atcoder.jp/contests/awc0064/tasks/awc0064_e
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

const int TREE_SIZE = 1 << 20;
int st[TREE_SIZE * 2];

void update(int i) {
	i += TREE_SIZE;
	st[i] = 1;
	i >>= 1;
	
	while (i) {
		st[i] = st[2*i] + st[2*i+1];
		i >>= 1;
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
    int n, k;
    cin >> n >> k;
    
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i].first;
    	a[i].second = i;
    }
    
    sort(a.begin(), a.end());
    
    int inversions = 0;
    for (int i = 0; i < n; i++) {
    	inversions += query(a[i].second + 1, n - 1);
    	
    	update(a[i].second);
    }
    
    cout << max(0ll, inversions - k) << ln;
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
