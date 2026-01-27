// Problem: D. Three Logos
// Contest: Codeforces - Codeforces Round 322 (Div. 2)
// URL: https://codeforces.com/contest/581/problem/D
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

void print(vector<string>& a) {
	cout << a.size() << ln;
	for (auto& i : a) {
		cout << i << ln;
	}
}

void solve() {
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >>y2 >> x3 >> y3;
	int tot = (x1*y1) + (x2*y2)+ (x3*y3);
	int n = sqrt(tot);
	
	if (n * n != tot) {
		cout << -1 << ln;
		return;
	}
	
	vector<string> mat(n, string(n, '.'));
	vector<vector<int>> rots = {{1, 0, 0},
	                            {0, 1, 0},
	                            {0, 0, 1},
	                            {1, 1, 0},
	                            {1, 0, 1},
	                            {0, 1, 1},
	                            {1, 1, 1},
	                            {0, 0, 0}};
	
	// Check all possibilities of swapping x and y
	for (int x = 0; x < 8; x++) {
		
	// Perform swaps
	if (rots[x][0]) swap(x1, y1);
	if (rots[x][1]) swap(x2, y2);
	if (rots[x][2]) swap(x3, y3);
	
	// dbg(x1,x2,x3);
	
	// All same width (n)
	if (y1 == y2 and y1 == y3 and y1 == n) {
		int i = 0;
		for (; i < x1; i++) {
			for (int j = 0; j < n; j++) {
				mat[i][j] = 'A';
			}
		}
		
		for (; i < x1+x2; i++) {
			for (int j = 0; j < n; j++) {
				mat[i][j] = 'B';
			}
		}
		
		for (; i < x1+x2+x3; i++) {
			for (int j = 0; j < n; j++) {
				mat[i][j] = 'C';
			}
		}
		
		print(mat);
		return;
	}
	
	// All same length (n)
	if (x1 == x2 and x1 == x3 and x1 == n) {
		int i = 0;
		for (; i < y1; i++) {
			for (int j = 0; j < n; j++) {
				mat[j][i] = 'A';
			}
		}
		
		for (; i < y1+y2; i++) {
			for (int j = 0; j < n; j++) {
				mat[j][i] = 'B';
			}
		}
		
		for (; i < y1+y2+y3; i++) {
			for (int j = 0; j < n; j++) {
				mat[j][i] = 'C';
			}
		}
		
		print(mat);
		return;
	}
	
	// 1 width = n, 2 same length, w1+w2=L
	if (y1 == n and (x2 == x3 and y2 + y3 == n)) {
		// Up to x1 do A
		for (int i = 0; i < x1; i++) {
			for (int j = 0; j < n; j++) {
				mat[i][j] = 'A';
			}
		}
		
		// From x1 to n do rest
		for (int i = x1; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (j < y2) {
					mat[i][j] = 'B';
				}
				else mat[i][j] = 'C';
			}
		}
		
		print(mat);
		return;
	}
	
	if (y2 == n and (x1 == x3 and y1 + y3 == n)) {
		// Up to x2 do B
		for (int i = 0; i < x2; i++) {
			for (int j = 0; j < n; j++) {
				mat[i][j] = 'B';
			}
		}
		
		// From x2 to n do rest
		for (int i = x2; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (j < y1) {
					mat[i][j] = 'A';
				}
				else mat[i][j] = 'C';
			}
		}
		
		print(mat);
		return;
	}
	
	if (y3 == n and (x1 == x2 and y1 + y2 == n)) {
		// Up to x3 do C
		for (int i = 0; i < x3; i++) {
			for (int j = 0; j < n; j++) {
				mat[i][j] = 'C';
			}
		}
		
		// From x3 to n do rest
		for (int i = x3; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (j < y1) {
					mat[i][j] = 'A';
				}
				else mat[i][j] = 'B';
			}
		}
		
		print(mat);
		return;
	}
	
	
	// 1 length = n, 2 same width, L1+L2=W
	if (x1 == n and (y2 == y3 and x2 + x3 == n)) {
		// Up to y1 do A
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < y1; j++) {
				mat[i][j] = 'A';
			}
		}
		
		// From y1 to n do rest
		for (int i = 0; i < n; i++) {
			for (int j = y1; j < n; j++) {
				if (i < x2) {
					mat[i][j] = 'B';
				}
				else mat[i][j] = 'C';
			}
		}
		
		print(mat);
		return;
	}
	
	if (x2 == n and (y1 == y3 and x1 + x3 == n)) {
		// Up to y2 do B
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < y2; j++) {
				mat[i][j] = 'B';
			}
		}
		
		// From y2 to n do rest
		for (int i = 0; i < n; i++) {
			for (int j = y2; j < n; j++) {
				if (i < x1) {
					mat[i][j] = 'A';
				}
				else mat[i][j] = 'C';
			}
		}
		
		print(mat);
		return;
	}
	
	if (x3 == n and (y1 == y2 and x1 + x2 == n)) {
		// Up to y3 do C
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < y3; j++) {
				mat[i][j] = 'C';
			}
		}
		
		// From y3 to n do rest
		for (int i = 0; i < n; i++) {
			for (int j = y3; j < n; j++) {
				if (i < x1) {
					mat[i][j] = 'A';
				}
				else mat[i][j] = 'B';
			}
		}
		
		print(mat);
		return;
	}
	
	// Unperform swaps
	if (rots[x][0]) swap(x1, y1);
	if (rots[x][1]) swap(x2, y2);
	if (rots[x][2]) swap(x3, y3);
	}
	
	cout << -1 << ln;
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
