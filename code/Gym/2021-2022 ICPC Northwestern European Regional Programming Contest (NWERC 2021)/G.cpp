// Problem: G. Glossary Arrangement
// Contest: Codeforces - 2021-2022 ICPC Northwestern European Regional Programming Contest (NWERC 2021)
// URL: https://codeforces.com/gym/104064/problem/G
// Memory Limit: 512 MB
// Time Limit: 5000 ms
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
#define int ll
const ld PI = acos(-1);
const int MOD = 1000000007;
const double eps = 1e-9;

vector<string> words;
vector<int> lens;
int n, w;
const int MAXD = 5001;
int dp[MAXD];
pair<int, int> par[MAXD];

int recurse(int idx, int& x) {
	if (idx == n) {
		return 0;
	}
	
	if (dp[idx] != -1) return dp[idx];
	int res = INF;
	
	int cmax = 0;
	for (int i = idx; i < idx + x; i++) {
		if (i == n) break;
		cmax = max(cmax, lens[i]);
		
		int val = recurse(i+1, x) + cmax;
		if (val < res) {
			res = val;
			par[idx] = {i+1, cmax};
		}
	}
	
	// dbg(idx, res);
	
	return dp[idx] = res;
}


int f(int x) {
	
	fill_n(&dp[0], 5001, -1);
	
	recurse(0, x);
	
	if (dp[0] <= w) return dp[0];
	
	return -1;
}

void solve() {
    cin >> n >> w;
    w++;
    
	fill_n(&par[0], 5001, make_pair(-1, -1));
    
    
    for (int i = 0; i < n; i++) {
    	string s;
    	cin >> s;
    	s += ' ';
    	words.pb(s);
    	lens.pb((int)s.length());
    }
    
    int l = 1, r = n;
    int ans = n;
    int turn = 1;
    while (l <= r) {
    	int m = (l + r) / 2;
    	
    	int poss = f(m);
    	// dbg(m, poss);
    	
    	if (poss != -1) {
    		ans = min(ans, m);
    		r = m - 1;
    	}
    	else {
    		l = m + 1;
    	}
    }
    
    // dbg(ans);
    
    int sw = f(ans);
    int si = 0;
    vector<pair<int, int>> path;
    
    while (par[si] != make_pair(-1ll, -1ll)) {
    	path.pb(par[si]);
    	
    	si = par[si].first;
    }
    
    int x = ans;
    int y = (int)(path.size());
    
    cout << x << " " << y << ln;
    
    for (auto& i : path) {
    	cout << i.second - 1 << " ";
    }
    cout << ln;
    
    vector<vector<string>> wordMap(x, vector<string>(y, ""));
    
    int c = 0;
    for (int i = 0; i < y; i++) {
    	for (int j = c, k = 0; j < path[i].first; j++, k++) {
    		// dbg(i, k);
    		// dbg(words[c]);
    		wordMap[k][i] = words[c++];	
    	}
    }
    
    for (int i = 0; i < x; i++) {
    	int c = 0;
    	for (int j = 0; j < y; j++) {
    		// dbg(wordMap[i][j]);
    		// dbg(c, path[j].second);
    		int whitespace = path[j].second;
    		
    		
    		// dbg(whitespace);
    		whitespace -= (int)wordMap[i][j].size();
    		
    		// dbg(whitespace);
    		// cout << ln << ln;
    		string oth = string(whitespace, ' ');
    		cout << wordMap[i][j] << oth;
    		// cout << ln << ln;
    	}
    	cout << ln;
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
