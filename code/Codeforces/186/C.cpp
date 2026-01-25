// Problem: C. Plant
// Contest: Codeforces - Codeforces Round 118 (Div. 2)
// URL: https://codeforces.com/contest/186/problem/C
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

using Matrix = array<array<int, 2>, 2>;

Matrix A;

Matrix mult(Matrix A, Matrix B) {
	Matrix ans;
	ans[0][0] = 0;
	ans[0][1] = 0;
	ans[1][0] = 0;
	ans[1][1] = 0;
	
	for (int i = 0; i < 2; i++) 
	for (int j = 0; j < 2; j++) 
	for (int k = 0; k < 2; k++) {
		ans[i][j] += A[i][k] * B[k][j];
		ans[i][j] %= MOD;
	}
	
	return ans;
}

Matrix binexp(Matrix A, int k) {
	Matrix res;
	res[0][0] = 1;
	res[0][1] = 0;
	res[1][0] = 0;
	res[1][1] = 1;
	
	while (k) {
		if (k & 1) {
			res = mult(res, A);
		}
		
		A = mult(A, A);
		k >>= 1;
	}
	
	return res;
}

void solve() {
    int n;
    cin >> n;
    
    A[0][0] = 2;
    A[0][1] = 1;
    A[1][0] = 0;
    A[1][1] = 4;
    
    Matrix res = binexp(A, n);
    
    // dbg(res[0][0]);
    // dbg(res[0][1]);
    // dbg(res[1][0]);
    // dbg(res[1][1]);
    
    cout << (res[0][0] + res[0][1]) % MOD << ln;
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
