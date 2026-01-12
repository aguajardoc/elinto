// Problem: 466 - Mirror, Mirror
// Contest: UVa Online Judge
// URL: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=407
// Memory Limit: 32 MB
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

vector<string> rotate(vector<string> a, int times) {
	int n = a.size();
	
	// Transform to rings
	vector<vector<string>> rings;
	for (int i = 0, j = 0; i < n/2 + n % 2; i++, j++) {
		vector<string> ring;
		string curring;
		// Left to right top
		for (int k = i; k < n - i; k++) {
			curring += a[i][k];
		}
		ring.pb(curring);
		curring.clear();
		// Top to bottom right
		for (int k = i; k < n - i; k++) {
			curring += a[k][n - i - 1];
		}
		ring.pb(curring);
		curring.clear();
		// Right to left bottom
		for (int k = i; k < n - i; k++) {
			curring += a[n - i - 1][n - k - 1];
		}
		ring.pb(curring);
		curring.clear();
		// Bottom to top left
		for (int k = i; k < n - i; k++) {
			curring += a[n - k - 1][i];
		}
		ring.pb(curring);
		curring.clear();
		
		// Rotate ring
		for (int k = 0; k < times; k++) {
			vector<string> newring = ring;
			for (int l = 0; l < 4; l++) {
				newring[(l+1)%4] = ring[l];
			}
			ring = newring;
		}
		
		rings.pb(ring);
	}
		
	// Recombine to vector
	for (int i = 0, j = 0; i < n/2 + n % 2; i++, j++) {
		vector<string> ring = rings[i];
		
		// Left to right top
		for (int k = i; k < n - i; k++) {
			// dbg(i,k);
			a[i][k] = ring[0][k-i];
		}
		
		// Top to bottom right
		for (int k = i; k < n - i; k++) {
			// dbg(k,n-i-1);
			a[k][n-i-1] = ring[1][k-i];
		}
		
		// Right to left bottom
		for (int k = i; k < n - i; k++) {
			// dbg(n-1-i,n-k-1);
			a[n - i - 1][n - k - 1] = ring[2][k-i];
		}
		
		// Bottom to top left
		for (int k = i; k < n - i; k++) {
			// dbg(n-k-1,i);
			a[n - k - 1][i] = ring[3][k-i];
		}
	}
	
	return a;
}

vector<string> transform(vector<string> a) {
	int n = a.size();
	for (int i = 0; i < n / 2; i++) {
		for (int j = 0; j < n; j++) {
			swap(a[i][j], a[n - i - 1][j]);
		}
	}
	
	return a;
}

void print(vector<string> a) {
	for (auto& i : a) {
		cout << i << ln;
	}
	cout << ln;
}

void solve() {
    int n;
    int c = 1;
    
    vector<string> ans = {" was preserved.",
    	                 " was rotated 90 degrees.",
                         " was rotated 180 degrees.",
                         " was rotated 270 degrees.",
                         " was reflected vertically.",
                         " was reflected vertically and rotated 90 degrees.",
                         " was reflected vertically and rotated 180 degrees.",
                         " was reflected vertically and rotated 270 degrees.",
                         " was improperly transformed."};
    
    while(cin >> n) {
    	vector<string> mat(n), goal(n);
    	for (int i = 0; i < n; i++) {
    		cin >> mat[i] >> goal[i];
    	}
    	
    	// print(mat);
    	// print(rotate(mat, 1));
    	
    	int option = 0;
    	if (mat == goal) option = 0;
    	else if (rotate(mat, 1) == goal) option = 1;
    	else if (rotate(mat, 2) == goal) option = 2;
    	else if (rotate(mat, 3) == goal) option = 3;
    	else if (transform(mat) == goal) option = 4;
    	else if (rotate(transform(mat), 1) == goal) option = 5;
    	else if (rotate(transform(mat), 2) == goal) option = 6;
    	else if (rotate(transform(mat), 3) == goal) option = 7;
    	else option = 8;
    	
    	cout << "Pattern " << c++ << ans[option] << ln;
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
