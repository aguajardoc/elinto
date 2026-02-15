// Problem: C. Unfair Poll
// Contest: Codeforces - Codeforces Round 392 (Div. 2)
// URL: https://codeforces.com/contest/758/problem/C
// Memory Limit: 256 MB
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


void solve() {
    int n, m, k, x, y;
    cin >> n >> m >> k >> x >> y;
    
    if (n == 1) {
    	int its = k / m;
    	
    	int surp = k % m;
    	
    	int mn = its;
    	int mx = its;
    	
    	if (surp > 0) mx++;
    	
    	int res = its;
    	if (surp >= y) res++;
    	
    	cout << mx << " " << mn << " " << res;
    	return;
    }
    
    int CR = k / m;
    int FC = CR / (2 * n - 2);
    int S = k % (m * (2 * n - 2));
    int MN = FC;
    int MX = 2 * FC;
    
    if (n == 2) {
    	MX = FC;
    }
    
    int ATPOS;
    if (x == 1) {
    	ATPOS = MN;
    	if (S >= y) ATPOS++;
    }
    else if (x == n) {
    	ATPOS = MN;
    	if (S >= (n - 1) * m + y) ATPOS++;
    }
    else {
    	ATPOS = MX;
    	int TS = S;
    	int TN = x;
    	if (S > n * m) {
    		ATPOS++;
    		TS -= (n * m);
    		TN = n - x;
    	}
    	
    	int needed = (TN - 1) * m + y;
    	
    	if (TS >= needed) ATPOS++;
    }
    
    if (S >= n * m) MN++;
    
    if (n == 2 or FC == 0) {
    	if (S > 0) MX++;
    }
    else {
    	if (S > m) MX++;
    }
    
    if (S > n * m) MX++;
    
    cout << MX << " " << MN << " " << ATPOS;
    
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
