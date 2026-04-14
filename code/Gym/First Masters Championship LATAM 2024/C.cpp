// Problem: C. Counting Relative Lists
// Contest: Codeforces - First Masters Championship LATAM 2024
// URL: https://codeforces.com/gym/104990/problem/C
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

#define Matrix vector<vector<ll>>

int n, m;

Matrix mat, I;

Matrix mul(Matrix A, Matrix B) {
	Matrix res(m, vector<ll> (m, 0));
	
	for (int k = 0; k < m; k++) {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				res[i][j] += A[i][k] * B[k][j];
				res[i][j] %= MOD;
			}
		}
	}
	
	return res;
}

Matrix binexp(Matrix A, int b) {
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
    cin >> n >> m;
    mat.assign(m, vector<ll> (m, 0));
    I.assign(m, vector<ll> (m, 0));
    for (int i = 0; i < m; i++) {
    	I[i][i] = 1;
    }
    for (int i = 1; i <= m; i++) {
    	for (int j = 1; j <= m; j++) {
    		if (gcd(i, j) == 1) {
    			mat[i-1][j-1] = 1;
    		}
    	}
    }
    
    Matrix res = binexp(mat, n);
    ll ans = 0;
    for (int i = 0; i < m; i++) {
    	ans += res[i][0];
    	ans %= MOD;
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
