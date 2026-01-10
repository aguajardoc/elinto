// Problem: Halt The War
// Contest: SPOJ - Classical
// URL: https://www.spoj.com/problems/CDC12_H/
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

const int TREE_SIZE = 1 << 20;
int st[2 * TREE_SIZE];
int lazy[2 * TREE_SIZE];
int n;

void push(int p, int l, int r) {
	if (!lazy[p]) return;
	
	int m = (l + r) / 2;
	st[2*p] += (m - l + 1) * lazy[p];
	st[2*p+1] += (r - m) * lazy[p];
	
	lazy[2*p] += lazy[p];
	lazy[2*p+1] += lazy[p];
	
	lazy[p] = 0;
}

int query(int p, int l, int r, int i, int j) {
	if (i > r or j < l) return 0;
	if (i <= l and r <= j) return st[p];
	
	push(p, l, r);
	
	int m = (l + r) / 2;
	return (query(2 * p, l, m, i, j) + query(2 * p + 1, m + 1, r, i, j));
}

void update(int p, int l, int r, int i, int j, int val) {
	if (i > r or j < l) return;
	if (i <= l and r <= j) {
		st[p] += (r - l + 1) * val;
		lazy[p] += val;
		return;
	}
	
	push(p, l, r);
	
	int m = (l + r) / 2;
	update(p * 2, l, m, i, j, val);
	update(p * 2 + 1, m + 1, r, i, j, val);
	
	st[p] = st[p * 2] + st[p * 2 + 1];
}

void update(int l, int r, int val) {
	update(1, 0, n - 1, l, r, val);
}

int query(int l, int r) {
	return query(1, 0, n - 1, l, r);
}

void solve(int c) {
    cout << "Scenario #" << c << ":\n";
    int q;
    cin >> n >> q;
    for (int i = 0; i <= 4*n; i++) {
    	st[i] = lazy[i] = 0;
    }
    
    for (int i = 0; i < q; i++) {
    	string type;
    	int x, y;
    	cin >> type >> x >> y;
    	if (type[0] == 'a') {
    		cout << query(x - 1, y - 1) << ln;
    	}
    	else {
    		update(x - 1, y - 1, 1);
    		cout << "OK\n";
    	}
    }
}

signed main() {
    fast_cin();
    
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(i  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
