// Problem: 196 - Spreadsheet
// Contest: UVa Online Judge
// URL: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=132
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

struct Cell {
	int x, y;
	bool operator<(const Cell& oth) const {
		if (x != oth.x) return x < oth.x;
        return y < oth.y;
	}
};

Cell cell2coord(string s) {
	string col; string row;
	for (auto& i : s) {
		if (isdigit(i)) row += i;
		else col += i;
	}
	int r = stoll(row) - 1;
	int c = 0;
	reverse(col.begin(), col.end());
	int x = 1;
	for (int i = 0; i < col.size(); i++) {
		c += x * (col[i] - 'A' + 1);
		x *= 26;
	}
	c--;

	return {r, c};
}

int dfs(int x, int y, map<Cell, vector<Cell>>& AL, vector<vector<int>>& mat, vector<vector<int>>& visited) {
	// fetch current value in matrix
	int val = mat[x][y];
	
	// add dependencies
	for (auto& v : AL[{x, y}]) {
		if (visited[v.x][v.y]) {
			// means it already has the value i need
			val += mat[v.x][v.y];
		}
		else {
			// means i need to go with its dependencies
			val += dfs(v.x, v.y, AL, mat, visited);
		}
	}
	
	visited[x][y] = true;
	// dbg(val, x, y);
	return mat[x][y] = val;
}

void solve() {
    int r, c;
    cin >> c >> r;
    
    map<Cell, vector<Cell>> AL;
    vector<vector<int>> mat(r, vector<int>(c, 0));
    cin.ignore();
    for (int i = 0; i < r; i++) {
    	string s;
    	getline(cin, s);
    	s += ' ';
    	
    	string cur;
    	int idx = 0;
    	for (auto& j : s) {
    		if (j == ' ') {
    			if (cur.empty()) continue;
    			
    			if (cur[0] == '=') {
    				vector<Cell> dependencies;
    				cur += '+';
    				string curd;
    				Cell u = {i, idx};
    				for (auto& jj : cur) {
    					if (jj == '=') continue;
    					if (jj == '+') {
    						AL[u].push_back(cell2coord(curd));

    						curd.clear();
    					}
    					else {
    						curd += jj;
    					}
    				}
    			}
    			else {
    				mat[i][idx] = stoll(cur);
    			}
    			
				idx++;
    			cur.clear();
    		}
    		else cur += j;
    	}
    }
    
    vector<vector<int>> visited(r, vector<int> (c, 0));
    
    for (int i = 0; i < r; i++) {
    	for (int j = 0; j < c; j++) {
    		if (!visited[i][j])
    		// if (AL.count({}))
    		dfs(i, j, AL, mat, visited);
    	}
    }
    
    for (int i = 0; i < r; i++) {
    	for (int j = 0; j < c; j++) {
    		cout << mat[i][j] << " \n"[j == c - 1];
    	}
    }
    // cout << ln;
}

signed main() {
    fast_cin();
    
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
