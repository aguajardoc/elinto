// Problem: C2. A Simple GCD Problem (Hard Version)
// Contest: Codeforces - Codeforces Round 1089 (Div. 2)
// URL: https://codeforces.com/contest/2210/problem/C2
// Memory Limit: 512 MB
// Time Limit: 6000 ms
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

vector<int> p, premarked, a, b;
vector<vector<int>> dp;
int n;
bitset<101> bs;

void sieve() {
	bs.set();
	bs[0] = bs[1] = false;
	
	for (int i = 2; i <= 100; i++) {
		if (!bs[i]) continue;
		for (int j = i * i; j <= 100; j += i) {
			bs[j] = false;
		}
		
		p.pb(i);
	}
}

int recurse(int idx, int p_idx) {
	if (idx == n) {
		return 0;
	}
	
	if (dp[idx][p_idx] != -1) return dp[idx][p_idx];
	
	int res = recurse(idx + 1, 0);
	
	if (!premarked[idx]) {
		int L, R;
		int PRIME;
		if (!p_idx) PRIME = 1;
		else PRIME = p[p_idx-1];
		
		if (!idx) L = 1;
		else L = a[idx-1] * PRIME;
		
		if (idx == n - 1) R = 1;
		else R = a[idx+1];
		
		int OGCDL = gcd(L, a[idx]);
		int OGCDR = gcd(R, a[idx]);
		
		for (int i = 1; i <= 16; i++) {
			int NEW = a[idx] * p[i-1];
			if (NEW > b[idx]) break;
			
			int GCDL = gcd(L, NEW);
			int GCDR = gcd(R, NEW);
			
			if (GCDL == OGCDL and
				GCDR == OGCDR
			) {
				res = max(res, recurse(idx + 1, i) + 1);
			}
		}
	}
	
	return dp[idx][p_idx] = res;
}

void solve() {
    cin >> n;
    a.assign(n, 0);
    b.assign(n, 0);
    premarked.assign(n, 0);
    dp.assign(n + 1, vector<int> (17, -1));
    for (auto& i : a) cin >> i;
    for (auto& i : b) cin >> i;
    
    for (int i = 0; i < n; i++) {
    	int L, R;
    	if (!i) L = 1;
    	else L = a[i-1];
    	
    	if (i == n - 1) R = 1;
    	else R = a[i+1];
    	
    	int LGCD = gcd(L, a[i]);
    	int RGCD = gcd(R, a[i]);
    	int NEW = lcm(LGCD, RGCD);
    	
    	if (NEW < a[i] and NEW <= b[i]) {
    		premarked[i] = true;
    		a[i] = NEW;
    	}
    }
    
    cout << count(premarked.begin(), premarked.end(), 1) + recurse(0, 0) << ln;
    
}

signed main() {
    fast_cin();
    sieve();
    
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
