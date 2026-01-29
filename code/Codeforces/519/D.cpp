// Problem: D. A and B and Interesting Substrings
// Contest: Codeforces - Codeforces Round 294 (Div. 2)
// URL: https://codeforces.com/contest/519/problem/D
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
    vector<int> x(26);
    for (auto& i : x) cin >> i;
    string s;
    cin >> s;
    int n = s.length();
    vector<int> pref(n + 1, 0);
    for (int i = 0; i < n; i++) {
    	pref[i+1] = pref[i] + (x[s[i] - 'a']);
    }
    
    // Get all locs of all letters
    vector<vector<int>> locs(26);
    for (int i = 0; i < n; i++) {
    	int idx = s[i] - 'a';
    	locs[idx].pb(i);
    }
    
    // For every letter, get idx of every two occs, and sum
    int ans = 0;
    for (int i = 0; i <  26; i++) {
    	map<int, int> st, en;
    	int local = 0;
    	for (int j = 0; j < (int)locs[i].size() - 1; j++) {
    		int l = locs[i][j] + 1;
    		int r = locs[i][j+1] - 1;
    		
    		int start = pref[l];
    		int ending = pref[r+1];
    		
    		st[start]++;
    		en[ending]++;
    		
    		local += st[ending];
    	}
    	
    	ans += local;
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