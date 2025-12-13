// Problem: B. Jzzhu and Sequences
// Contest: Codeforces - Codeforces Round 257 (Div. 2)
// URL: https://codeforces.com/contest/450/problem/B
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
#define INF 2e18
#define PI 3.14159265358979323846
#define MOD 1000000007

double eps = 1e-9;

vector<vector<int>> A = {{1, 1000000006},
						{1, 0}};
vector<vector<int>> I = {{1, 0},
						{0, 1}};						
						
vector<vector<int>> multiply(vector<vector<int>> A, vector<vector<int>> B) {
	vector<vector<int>> res(2, vector<int> (2, 0));
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				res[i][k] += A[i][j] * B[j][k];
				res[i][k] = ((res[i][k] % MOD) + MOD) % MOD;
			}
		}
	}
	
	return res;
}
				
vector<vector<int>> binexp(vector<vector<int>> A, ll k) {
	vector<vector<int>> res = I;
	
	while (k) {
		if (k & 1) {
			res = multiply(res, A);
		}
		A = multiply(A, A);
		k >>= 1;
	}
	
	return res;
}		

void solve() {
    ll x, y, n;
    cin >> x >> y >> n;
    x = ((x % MOD) + MOD) % MOD;
    y = ((y % MOD) + MOD) % MOD;
    if (n == 1) {
    	cout << x << ln;
    	return;
    }
    A = binexp(A, n-2);
    
    ll res = A[0][0] * y + A[0][1] * x;
    res = ((res % MOD) + MOD) % MOD;
    cout << res << ln;
}

signed main() {
    fast_cin();
    
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
