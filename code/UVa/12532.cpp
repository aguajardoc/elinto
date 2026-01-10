// Problem: 12532 - Interval Product
// Contest: UVa Online Judge
// URL: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3977
// Memory Limit: 32 MB
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

const int TREE_SIZE = (1 << 20);

int st[2*TREE_SIZE];

void update(int v, int x) {
	v += TREE_SIZE;
	if (x > 0) st[v] = 1;
	else if (x == 0) st[v] = 0;
	else st[v] = -1;
	
	v >>= 1;
	while (v) {
		st[v] = st[2 * v] * st[2 * v + 1];
		v >>= 1;
	}
}

int query(int u, int v) {
	u += TREE_SIZE;
	v += TREE_SIZE;
	int res = 1;
	while (u <= v) {
		if (u&1) res *= st[u++];
		if (!(v&1)) res *= st[v--];
		
		u >>= 1;
		v >>= 1;
	}
	
	return res;
}

void solve() {
    int n, k;
    while (cin >> n){
    	cin >> k;
    	for (int i = 0; i < n ; i++) {
    		int x;
    		cin >> x;
    		update(i, x);
    	}
    	
    	string ans;
    	
    	for (int i = 0; i < k; i++) {
    		char t;
    		int x, y;
    		cin >> t >> x >> y;
    		
    		if (t == 'C') {
    			update(x - 1, y);
    		}
    		else {
    			int res = query(x - 1, y - 1);
    			if (res == 0) ans += '0';
    			if (res == -1) ans += '-';
    			if (res == 1) ans += '+';
    		}
    	}
    	
    	cout << ans << ln;
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
