// Problem: F. Xor-Paths
// Contest: Codeforces - Codeforces Round 498 (Div. 3)
// URL: https://codeforces.com/contest/1006/problem/F
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

int mat[21][21];
map<int, int> xors[21][21];
int n, m, k, ans = 0;

void dfs(int x, int y, int steps, int dir, int cx) {
	if (x == n or x < 0 or y == m or y < 0) return;
	
	cx ^= mat[x][y];
	if (!steps) {
		if (dir==1) xors[x][y][cx]++; 
		else {
			int tung = k ^ cx ^ mat[x][y];
			
			ans += xors[x][y][tung];
		}
		return;
	}
	
	int nx = x + dir;
	int ny = y + dir;
	
	dfs(nx, y, steps - 1, dir, cx);
	dfs(x, ny, steps - 1, dir, cx);
}

void solve() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		cin >> mat[i][j];
    	}
    }

	int half = (n + m - 2) / 2;
	int rest = n + m - 2 - half;
	dfs(0, 0, half, 1, 0);
	dfs(n - 1, m - 1, rest, -1, 0);
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