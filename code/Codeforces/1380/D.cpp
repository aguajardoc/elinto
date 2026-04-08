// Problem: D. Berserk And Fireball
// Contest: Codeforces - Educational Codeforces Round 91 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1380/problem/D
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

int n, m, x, k, y;
vector<int> a, b;

void solve() {
    cin >> n >> m >> x >> k >> y;
    a.assign(n, 0);
    b.assign(m, 0);
    
    for (auto& i : a) cin >> i;
    for (auto& i : b) cin >> i;
    
    // |b| must be at most |a|
    if (m > n) {
    	cout << -1 << ln;
    	return;
    }
    
    // b's elements must show up in the same order in a
    int idx_b = 0;
    vector<pair<int, int>> segments;
    int start = -1;
    for (int i = 0; i < n; i++) {
    	if (idx_b < m and a[i] == b[idx_b]) {
    		if (start != -1) {
    			segments.pb({start, i-1});
    			start = -1;
    		}
    		idx_b++;
    	}
    	else {
    		if (start == -1) start = i;
    	}
    }
    if (start != -1) {
    	segments.pb({start, n - 1});
    }
    
    if (idx_b != m) {
    	cout << -1 << ln;
    	return;
    }
    
    int ans = 0;
    
    for (auto& [L, R] : segments) {
    	int D = (R - L + 1);
    	int mx = 0;
    	for (int i = L; i <= R; i++) mx = max(mx, a[i]);
    	int idx_l = max(0ll, L - 1);
    	int idx_r = min(n - 1, R + 1);
    	
    	bool op2_poss = (a[idx_l] > mx or a[idx_r] > mx);
    	
    	if (D < k) {
    		if (op2_poss) {
    			ans += D * y;
    		}
    		else {
    			cout << -1 << ln;
    			return;
    		}
    	}
    	else {
    		// op 2 poss?
    		int op1 = x * (D/k) + y * (D%k);
    		int op2 = y * (D - k) + x;
    		if (op2_poss) {
    			op2 = min(op2, y * D);
    		}
    		
    		ans += min(op1, op2);
    	}
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
