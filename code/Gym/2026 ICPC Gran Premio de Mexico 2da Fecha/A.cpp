// Problem: A. A simple problem
// Contest: Codeforces - 2026 ICPC Gran Premio de Mexico 2da Fecha
// URL: https://codeforces.com/gym/106540/problem/A
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
const int MOD = 998244353;
const double eps = 1e-9;

vector<int> dp;
int n, m;

set<int> bads;

int recurse(int idx) {
	if (idx == m) {
		return 1;
	}
	
	if (dp[idx] != -1) return dp[idx];
	
	int res = 0;
	for (int j = 1; j <= n; j++) {
		if (idx + j > m) break;
		
		if (bads.count(j)) continue;
		
		res += recurse(idx + j);
		res %= MOD;
	}
	
	return dp[idx] = res;
}

void solve() {
    cin >> n >> m;
    bads.clear();
    dp.assign(m + 1, -1);
    
    string s;
    cin >> s;
    
    for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= n-i; j++) {
    		// string up to i + string up to j == up to i + j
    		if (s[(j-1) % n] == s[(i+j-1) % n]) {
    			// dbg(i, j);
    			bads.insert(i + j);
    		}
    		else break;
    	}	
    }
    
    cout << recurse(0) << ln;
}

signed main() {
    fast_cin();
    
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
