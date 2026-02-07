// Problem: B. Array GCD
// Contest: Codeforces - AIM Tech Round (Div. 1)
// URL: https://codeforces.com/contest/623/problem/B
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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

// Usage: sieve(); p -> list of primes up to N
const int N = 100000;
bitset<N + 1> bs;
vector<int> p;

void sieve() {
    bs.set();
    bs[0] = bs[1] = false;

    for (long long i = 2; i <= N; i++) {
        if (!bs[i]) continue;
        for (long long j = i * i; j <= N; j += i) bs[j] = false;
        p.push_back(i);
    }
}

int dp[2][3];
int n, a, b;
int x[1000001];

vector<int> getFacs(int y) {
	vector<int> facs;
	for (int i = 0; i < p.size() and p[i] * p[i] <= y; i++) {
		bool flag = false;
		while(y % p[i] == 0) {
			y /= p[i];
			flag = true;
		}
		
		if (flag) facs.pb(p[i]);
	}
	
	if (y>1) facs.pb(y);
	
	return facs;
}

void solve() {
    cin >> n >> a >> b;
    for (auto& i : x)cin >> i;
    
    set<int> facs;
    for (int i = -1; i <= 1; i++) {
    	vector<int> f0 = getFacs(x[0] + i);
    	vector<int> fn = getFacs(x[n-1] + i);
    	
    	for (auto& j : f0) facs.insert(j);
    	for (auto& j : fn) facs.insert(j);
    }
    
    
    int ans = INF;
    for (auto& i : facs) {
    	fill_n(&dp[0][0], 2*3, 0);
    	
    	for (int j = 1; j <= n; j++) {
    		int now = j % 2;
    		int last = 1 - now;
    		bool good = (gcd(x[j-1], i) != 1);
			bool goodChange = ((gcd(x[j-1] + 1, i) != 1) or (gcd(x[j-1] - 1, i) != 1));
		
		
			if (good) {
				dp[now][0] = dp[last][0];
				dp[now][1] = min(dp[last][0] + a, dp[last][1] + a);
				dp[now][2] = min(dp[last][1], dp[last][2]);
			}
			else if (goodChange) {
				dp[now][0] = dp[last][0] + b;
				dp[now][1] = min(dp[last][0] + a, dp[last][1] + a);
				dp[now][2] = min(dp[last][1] + b, dp[last][2] + b);
			}
			else {
				dp[now][0] = INF;
				dp[now][1] = min(dp[last][0] + a, dp[last][1] + a);
				dp[now][2] = INF;
			}
			
			fill(dp[last], dp[last] + 3, 0);
		}
		
		for (int j = 0; j < 3; j++) {
			ans = min(ans, dp[n%2][j]);
		}
	}
    
    cout << ans << ln;
}

signed main() {
    fast_cin();
    sieve();
    
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
