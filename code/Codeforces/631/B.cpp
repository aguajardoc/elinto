// Problem: B. Print Check
// Contest: Codeforces - Codeforces Round 344 (Div. 2)
// URL: https://codeforces.com/contest/631/problem/B
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
#define INF 2e18
#define PI 3.14159265358979323846
#define MOD 1000000007

double eps = 1e-9;

void print(vector<vector<int>>& a) {
	for (auto& i : a) {
		for (auto& j : i) {
			cout << j << " ";
		}
		cout << ln;
	}
	cout << ln;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    map<pair<int, int>, pair<int, int>> leadingOperation;
    for (int i = 0; i < k; i++) {
    	int l, r, a;
    	cin >> l >> r >> a;
    	leadingOperation[{l, r - 1}] = {i, a};
    }
    vector<vector<int>> realOperations;
    for (auto& i : leadingOperation) {
    	realOperations.push_back({i.second.first, i.first.first, i.first.second, i.second.second});
    }
    
    sort(realOperations.begin(), realOperations.end());
    vector<vector<int>> mat(n, vector<int> (m, 0));
    
    for (auto& i : realOperations) {
    	int isCol = i[1];
    	int element = i[2];
    	int value = i[3];
    	
    	
    	if (isCol == 2) {
    		for (int j = 0; j < n; j++) {
    			mat[j][element] = value;
    		}
    	}
    	else {
    		for (int j = 0; j < m; j++) {
    			mat[element][j] = value;
    		}
    	}
    }
    
    
    print(mat);
}

signed main() {
    fast_cin();
    
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
