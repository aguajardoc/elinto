// Problem: 1592 - Database
// Contest: UVa Online Judge
// URL: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4467
// Memory Limit: 32 MB
// Time Limit: 9000 ms
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

struct Entry {
	int r1, r2;
	string c1, c2;
	bool operator<(const Entry& a) {
		if (r1 != a.r1) return r1 < a.r1;
		if (r2 != a.r2) return r2 < a.r2;
		if (c1 != a.c1) return c1 < a.c1;
		return c2 < a.c2;
	}
};

void solve() {
    // For any pair of columns, are there any two rows with the same 
    // values in both columns?
    int n, m;
    while (cin >> n) {
    	cin >> m;
    	
    	// An answer is identified by r1, r2, c1, c2
    	// 1e9 possible quads so obviously not
    	// or maybe??? we have 9 seconds what the fuck?
    	// For each pair of columns, see if any shows twice?
    	// 100 pairs of columns,
    	vector<map<pair<string, string>, set<int>>> cts(m * m);
    	// like get counts for each- no
    	
    	vector<vector<string>> table(n);
    	cin.ignore();
    	for (int i = 0; i < n; i++) {
    		string s;
    		getline(cin, s);
    		s += ',';
    		string cur;
    		for (char& c : s) {
    			if (c == ',') {
    				table[i].pb(cur);
    				cur.clear();
    			}
    			else cur += c;
    		}
    	}
    	
    	bool found = false;
    	for (int k = 0; k < n and !found; k++) {
	    	for (int i = 0; i < m and !found; i++) {
	    		for (int j = i + 1; j < m and !found; j++) {
	    			cts[i*m + j][{table[k][i], table[k][j]}].insert(k);
	    			if (cts[i*m + j][{table[k][i], table[k][j]}].size() > 1) {
	    				cout << "NO" << ln;
	    				for (int x : cts[i*m + j][{table[k][i], table[k][j]}]) {
	    					cout << x+1 << " ";
	    				}
	    				cout << ln;
	    				cout << i + 1 << " " << j + 1 << ln;
	    				found = true;
	    			}
	    		}
	    	}
    	}
    	
    	
    	if (!found)cout << "YES" << ln;
    	
    	
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
