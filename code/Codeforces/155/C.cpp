// Problem: C. Hometask
// Contest: Codeforces - Codeforces Round 109 (Div. 2)
// URL: https://codeforces.com/contest/155/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
    string s;
    cin >> s;
    int n;
    cin >> n;
    vector<string> banned(n);
    for (auto& i : banned) {
    	cin >> i;
    }
    int ans =0 ;
    // get components???
    s += '$';
    int m = s.length();
    // traverse once per banned, get ranges
    vector<vector<pair<int, int>>> ranges(n);
    
    for (int i = 0; i < n; i++) {
    	int start = -1;
    	int end = start;
    	for (int j = 0; j < m; j++) {
    		if (s[j] == banned[i][0] or s[j] == banned[i][1]) {
    			if (start == -1) {
    				start = j;
    				end = start;
    			}
    			else {
    				end++;
    			}
    		}
    		else {
    			if (start == -1) continue;
    			
    			// dbg(start, end);
    			ranges[i].pb({start, end});
    			start = -1;
    		}
    		// dbg(start, end);
    	}
    	
    	
    	// for each range, get min
    	for (auto& j : ranges[i]) {
    		int st = j.first;
    		int t = j.second;
    		map<char, int> ct;
    		
    		for (int k = st; k <= t; k++) {
    			ct[s[k]]++;
    		}
    		
    		int res = 0;
    		if (ct.size() < 2) {
    			continue;
    		}
    		
    		res += min(ct.begin()->second, ct.rbegin()->second);
    		ans += res;
    	}
    }
    
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
