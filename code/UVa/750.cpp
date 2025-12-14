// Problem: 750 - 8 Queens Chess Problem
// Contest: UVa Online Judge
// URL: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=691
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
#define INF 2e18
#define PI 3.14159265358979323846
#define MOD 1000000007

double eps = 1e-9;

vector<vector<int>> soln;

bool allowed(vector<vector<int>>& mat, int x, int y) {
	// Check horizontal and vertical
	for (int i = 0; i < 8; i++) {
		if (mat[x][i]) return false;
		if (mat[i][y]) return false;
	}
	
	// Check diagonals
	for (int i = x, j = y; i < 8 and j < 8; i++, j++) {
		if (mat[i][j]) return false;
	}
	for (int i = x, j = y; i < 8 and j >= 0; i++, j--) {
		if (mat[i][j]) return false;
	}
	for (int i = x, j = y; i >= 0 and j < 8; i--, j++) {
		if (mat[i][j]) return false;
	}
	for (int i = x, j = y; i >= 0 and j >= 0; i--, j--) {
		if (mat[i][j]) return false;
	}
	
	return true;
}

bool validSol(vector<vector<int>>& mat) {
	int ct = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (mat[i][j]) ct++;
			if (!allowed(mat, i, j)) return false;
		}
	}
	
	return ct == 8;
}

vector<int> createAns(vector<vector<int>>& mat) {
	vector<int> res(8, 0);
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (mat[i][j]) {
				res[j] = i + 1;
			}
		}
	}
	return res;
}

void print(vector<vector<int>>& mat) {
	for (auto&  i : mat) {
		for (auto& j : i ) {
			cout << j << " ";
		}
		cout << ln;
	}
	cout << ln;
}

void backtrack(int x, int y, vector<vector<int>>& cm, int placed) {
	if (y == 8) {
		y = 0, x++;
	}
	if (x == 8) {
		if (placed == 8) {
			soln.push_back(createAns(cm));
		}
		return;
	}
	
	// If can place place
	if (allowed(cm, x, y)){
		cm[x][y] = 1;
		backtrack(x, y + 1, cm, placed + 1);
		cm[x][y] = 0;
	}
	// Skip
	backtrack(x, y + 1, cm, placed);
}

void printSolution(vector<vector<int>>& sols) {
	for (int i = 0; i < sols.size(); i++) {
		if (i + 1 >= 10) {
			cout << i + 1;
		}
		else cout << " " << i + 1;
		cout << "     ";
		for (auto& j : sols[i]) {
			cout << " " << j;
		}
		cout << ln;
	}
}

void solve() {
    int n, m;
    cin >> n >> m;
    soln.clear();
    vector<vector<int>> mat;
    mat.assign(8, vector<int> (8, 0));
    mat[n-1][m-1] = 1;
    backtrack(0, 0, mat, 1);
    sort(soln.begin(), soln.end());
    cout << "SOLN       COLUMN" << ln;
    cout << " #      1 2 3 4 5 6 7 8" << ln;
    cout << ln;
    printSolution(soln);
}

signed main() {
    fast_cin();
    
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
        if (t) cout << ln;
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
