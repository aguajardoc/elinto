// Problem: L. Legendary Sort
// Contest: Codeforces - 2026 ICPC Gran Premio de Mexico 1ra Fecha
// URL: https://codeforces.com/gym/106495/problem/L
// Memory Limit: 256 MB
// Time Limit: 500 ms
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

const int TREE_SIZE = 1 << 19;
int inv[2 * TREE_SIZE], val[2 * TREE_SIZE];
vector<int> a;

void update_val(int i, int j) {
	swap(a[i], a[j]);
	i += TREE_SIZE;
	j += TREE_SIZE;
	swap(val[i], val[j]);
	i >>= 1;
	j >>= 1;
	while (i) {
		val[i] = val[2*i] + val[2*i+1];
		i >>= 1;
	}
	
	while (j) {
		val[j] = val[2*j] + val[2*j+1];
		j >>= 1;
	}
}

void add_val(int i, int v) {
	i += TREE_SIZE;
	val[i] = v;
	i >>= 1;
	
	while (i) {
		val[i] = val[2*i] + val[2*i+1];
		i >>= 1;
	}
}

int query_val(int i, int j) {
	i += TREE_SIZE;
	j += TREE_SIZE;
	int res = 0;
	
	while(i <= j) {
		if (i&1) res += (val[i++]);
		if (!(j&1)) res += (val[j--]);
		
		i >>= 1;
		j >>= 1;
	}
	
	return res;
}

void add_inv(int i, int v) {
	i += TREE_SIZE;
	inv[i] = v;
	i >>= 1;
	
	while (i) {
		inv[i] = inv[2*i] + inv[2*i+1];
		i >>= 1;
	}
}

void update_inv(int i, int j) {
	i += TREE_SIZE;
	j += TREE_SIZE;
	
	if (a[i - TREE_SIZE] < a[j - TREE_SIZE]) {
		swap(inv[i], inv[j]);
		inv[i]++;
	}
	else {
		swap(inv[i], inv[j]);
		inv[j]--;
	}
	
	i >>= 1;
	j >>= 1;
	while (i) {
		inv[i] = inv[2*i] + inv[2*i+1];
		i >>= 1;
	}
	
	while (j) {
		inv[j] = inv[2*j] + inv[2*j+1];
		j >>= 1;
	}
}

int query_inv(int i, int j) {
	i += TREE_SIZE;
	j += TREE_SIZE;
	int res = 0;
	
	while(i <= j) {
		if (i&1) res += (inv[i++]);
		if (!(j&1)) res += (inv[j--]);
		
		i >>= 1;
		j >>= 1;
	}
	
	return res;
}

void solve() {
    int n, q;
    cin >> n >> q;
    a.assign(n, 0);
    vector<pair<int, int>> order(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	add_val(i, a[i]);
    	
    	order[i] = {a[i], i};
    }
    
    sort(order.begin(), order.end());
    vector<int> inversions(n);
    for (int i = 0; i < n; i++) {
    	int cur = query_inv(order[i].second + 1, n - 1);
    	add_inv(order[i].second, 1);
    	
    	inversions[order[i].second] = cur;
    }
    
    for (int i = 0; i < n; i++) {
    	add_inv(i, inversions[i]);
    }
    
    while (q--) {
    	int t, x;
    	cin >> t >> x;
    	if (t == 1) {
    		x--;
    		update_inv(x, x+1);
    		update_val(x, x+1);
    	}
    	else {
    		if (x == 0) {
    			cout << query_inv(0, n - 1) << ln;
    		}
    		else {
    		int res = query_inv(0, n - 1) + 
    				(
    					x * (n + 1) - 
    					2 * query_val(0, x-1)
    				);
    				
    				cout << res << ln;
    		}
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
