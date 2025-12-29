// Problem: C2. Balanced Removals (Harder)
// Contest: Codeforces - Codeforces Global Round 5
// URL: https://codeforces.com/contest/1237/problem/C2
// Memory Limit: 512 MB
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

void solve() {
    int n;
    cin >> n;
    map<int, map<int, set<pair<int, int>>>> xyz;
    for (int i = 0; i < n; i++) {
    	int x, y, z;
    	cin >> x >> y >> z;
    	xyz[x][y].insert({z, i + 1});
    }
    
    vector<pair<int, int>> ans;
    vector<vector<int>> remaining;
    
    for (auto& x : xyz) {
    	vector<vector<int>> rem2d;
    	for (auto& y : x.second) {
    		pair<int, int> np = {1e9, 1e9};
    		
    		for (auto& z : y.second) {
    			if (np.first == 1e9) {
    				np.first = z.second;
    			}
    			else {
    				np.second = z.second;
    				ans.pb(np);
    				np = {1e9, 1e9};
    			}
    		}
    		
    		// dbg(x.first, y.first, y.second.rbegin()->first);
    		if (np.first != 1e9) {
    			rem2d.push_back({x.first, y.first, y.second.rbegin()->first, y.second.rbegin()->second});
    		}
    	}
    	
    	sort(rem2d.begin(), rem2d.end());
    	if ((int)rem2d.size() % 2) {
    		remaining.push_back(rem2d.back());
    		rem2d.pop_back();
    	}
    	
    	for (int i = 0; i < rem2d.size(); i += 2) {
    		ans.pb({rem2d[i][3], rem2d[i + 1][3]});
    	}
    	
    	rem2d.clear();
    }
    
    sort(remaining.begin(), remaining.end());
    
    for (int i = 0; i < remaining.size(); i += 2) {
    	ans.push_back({remaining[i][3], remaining[i + 1][3]});
    }
    
    for (auto& [x, y] : ans) {
    	cout << x << " " << y << ln;
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
