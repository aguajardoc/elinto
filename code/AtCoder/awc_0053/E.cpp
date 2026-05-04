// Problem: E - Magic Road
// Contest: AtCoder - AtCoder Weekday Contest 0053 Beta
// URL: https://atcoder.jp/contests/awc0053/tasks/awc0053_e
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
const int MOD = 998244353;
const double eps = 1e-9;

#define Matrix vector<vector<int>>

int n, m, K;

Matrix mul(Matrix A, Matrix B) {
	Matrix res(n, vector<int> (n, 0));
	
	for (int k = 0; k < n; k++)
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++) {
		res[i][j] += A[i][k] * B[k][j];
		res[i][j] %= MOD;
	}
	
	return res;
}

Matrix I;

Matrix binexp(Matrix A, ll b) {
	Matrix res = I;
	while(b) {
		if (b&1) {
			res = mul(res, A);
		}
		A = mul(A, A);
		b >>= 1;
	}
	
	return res;
}

void solve() {
    cin >> n >> m >> K;
    I.assign(n, vector<int> (n, 0));
    for (int i = 0; i < n; i++) {
    	I[i][i] = 1;
    }
    
    Matrix ans(n, vector<int> (n, 0));
    for (int i = 0; i < m; i++) {
    	int u, v, w;
    	cin >> u >> v >> w;
    	u--, v--;
    	ans[u][v] = w;
    }
    
    ans = binexp(ans, K);
    
    cout << ans[0][n-1] << ln;
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
