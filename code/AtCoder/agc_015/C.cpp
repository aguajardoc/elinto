// Problem: C - Nuske vs Phantom Thnook
// Contest: AtCoder - AtCoder Grand Contest 015
// URL: https://atcoder.jp/contests/agc015/tasks/agc015_c
// Memory Limit: 256 MB
// Time Limit: 4000 ms
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
// #define int ll
#define ld long double
#define pb push_back

const ll INF = LLONG_MAX / 4;
const ld PI = acos(-1);
const int MOD = 1000000007;
const double eps = 1e-9;

int query(vector<vector<int>>& A, int x1, int y1, int x2, int y2) {
	return (A[x2][y2] - A[x2][y1-1] - A[x1-1][y2] + A[x1-1][y1-1]);
}

void print(vector<vector<int>>& X, int n, int m) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << X[i][j] << " ";
		}
		cout << ln;
	}
	cout << ln;
}

void solve() {
    int n, m, q;
    vector<vector<int>> A(2010, vector<int>(2010, 0)), V = A, N = A, E = A, S = A, W = A;
    
    cin >> n >> m >> q;
    
    for (int i = 0; i < n; i++) {
    	string s;
    	cin >> s;
    	for (int j = 0; j < m; j++) {
    		if (s[j] == '1') A[i+1][j+1] = 1;
    	}
    }
    
    for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= m; j++) {
    		V[i][j] = V[i-1][j] + V[i][j-1] - V[i-1][j-1] + A[i][j];
    		N[i][j] = N[i-1][j] + N[i][j-1] - N[i-1][j-1] + (A[i][j] and A[i-1][j]);
    		E[i][j] = E[i-1][j] + E[i][j-1] - E[i-1][j-1] + (A[i][j] and A[i][j+1]);
    		S[i][j] = S[i-1][j] + S[i][j-1] - S[i-1][j-1] + (A[i][j] and A[i+1][j]);
    		W[i][j] = W[i-1][j] + W[i][j-1] - W[i-1][j-1] + (A[i][j] and A[i][j-1]);
    	}
    }
    
    // print(A, n, m);
    // print(V, n, m);
    // print(N, n, m);
    // print(E, n, m);
    // print(S, n, m);
    // print(W, n, m);
    
    while(q--) {
    	int x1, y1, x2, y2;
    	cin >> x1 >> y1 >> x2 >> y2;
    	
    	int ans = 	query(V, x1, y1, x2, y2) - (
    	        	query(N, x1+1, y1, x2, y2) +
    	        	query(E, x1, y1, x2, y2-1) +
    	        	query(S, x1, y1, x2-1, y2) +
    	        	query(W, x1, y1+1, x2, y2)
    	        	) / 2;
    	        	
    	cout << ans << ln;
    }
    
    
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
