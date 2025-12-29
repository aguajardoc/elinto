// Problem: B. Sereja and Mirroring
// Contest: Codeforces - Codeforces Round 243 (Div. 2)
// URL: https://codeforces.com/contest/426/problem/B
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

vector<vector<int>> getBase(vector<vector<int>>& mat, int n, int m, int x, int start) {
	vector<vector<int>> res(x, vector<int> (m, 0));
	for (int i = start; i < start + x; i++) {
		for (int j = 0; j < m; j++) {
			res[i - start][j] = mat[i][j];
		}
	}
	
	return res;
}

vector<vector<int>> mir(vector<vector<int>>& base, int n, int m) {
	vector<vector<int>> mir = base;
	for (int i = 0; i < n / 2; i++) {
		for (int j = 0; j < m; j++) {
			swap(mir[i][j], mir[n - 1 - i][j]);
		}
	}
	
	return mir;
}


void solve() {
    int x = 1;
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> mat(n, vector<int> (m, 0));
    for (auto& i : mat) for (auto& j : i) cin >> j;
    
    for (int i = 1; i <= 100; i++) {
    	if(n % i) continue;
    	if (__builtin_popcountll(n / i) == 1) {
    		x = i;
    		break;
    	}
    }
    
    for (int i = 0; x <= n; i++, x <<= 1) {
    	vector<vector<int>> base = getBase(mat, n, m, x, 0);
    	vector<vector<int>> mirror = mir(base, x, m);
    	bool poss = true;
    	
    	for (int j = 0, k = 0; j < n; j += x, k++) {
    		if (k % 2) {
    			if (mirror != getBase(mat, n, m, x, j)) {
    				poss = false;
    			}
    		}
    		else {
    			if (base != getBase(mat, n, m, x, j)) {
    				poss = false;
    			}
    		}
    	}
    	
    	if (poss) {
    		cout << x << ln;
    		return;
    	}
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
