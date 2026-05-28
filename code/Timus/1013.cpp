// Problem: 1013. K-based Numbers. Version 3
// Contest: Timus Online Judge
// URL: https://acm.timus.ru/problem.aspx?space=1&num=1013
// Memory Limit: 64 MB
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

using Matrix = array<array<__int128_t, 2>, 2>;
__int128_t n, k, m;

Matrix A, I;

Matrix mul(Matrix A, Matrix B) {
	Matrix res;
	res[0][0] = 0;
	res[0][1] = 0;
	res[1][0] = 0;
	res[1][1] = 0;
	
	for (int k = 0; k < 2; k++) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				A[i][k] %= m;
				B[k][j] %= m;
				__int128_t C = A[i][k] * B[k][j];
				C %= m;
				res[i][j] += C;
				res[i][j] %= m;
			}
		}
	}
	
	return res;
}

Matrix binexp(Matrix a, ll b) {
	Matrix res = I;
	while(b) {
		if (b&1) {
			res = mul(res, a);
		}
		
		a = mul(a, a);
		b >>= 1;
	}
	
	return res;
}


void solve() {
	int N, K, M;
	cin >> N >> K >> M;
    n = N, k = K, m = M;
    
    A[0][0] = k - 1;
    A[0][1] = k - 1;
    A[1][0] = 1;
    A[1][1] = 0;
    
    I[0][0] = 1;
    I[1][1] = 1;
    
    Matrix ans = binexp(A, n);
    
    int res = ans[0][0];
    
    cout << res << ln;
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
