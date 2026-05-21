// Problem: B. Digit String
// Contest: Codeforces - Educational Codeforces Round 190 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2230/problem/B
// Memory Limit: 512 MB
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
    
    int ct[5] = {0, 0, 0, 0, 0};
    
    for (auto& i : s) {
    	ct[i-'0']++;
    }
    
    int ans = ct[4];
    string t;
    for (auto& i : s) {
    	if (i != '4') t+=i;
    }
    
    vector<pair<int, int>> comps;
    int ones = 0, twos = 0;
    
    for (auto& i : t) {
    	if (i == '2') {
    		if (ones) {
    			comps.pb({ones, 0});
    			ones = 0;
    		}
    		twos++;
    	}
    	else {
    		if (twos and !comps.empty()) {
    			comps.back().second = twos;
    			twos = 0;
    		}
    		if (twos) twos = 0;
    		ones++;
    	}
    }
    
    if (twos and !comps.empty() and comps.back().second == 0) {
    	comps.back().second = twos;
    	twos = 0;
    }
    else if (!comps.empty() and comps.back().second == 0) comps.pop_back();
    
    
    // for (auto& i : comps) {
    	// cout << i.first << " " << i.second << ln;
    // }
    // cout << ln;
    if(comps.empty()) {
    	cout << ans << ln;
    	return;
    }
    
    int m = comps.size();
    
    vector<int> pa(m + 1, 0), pb = pa;
    
    for (int i = 0; i < m; i++) {
    	pa[i+1] = pa[i] + comps[i].first;
    	pb[i+1] = pb[i] + comps[i].second;
    }
    
    int mn = INF;
    
    for (int i = 0; i <= m; i++) {
    	mn = min(mn, 
    		pa[i] + pb[m] - pb[i]
    	);
    }
    
    ans += mn;
    cout << ans << ln;
    
    
}

signed main() {
    fast_cin();
    
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
