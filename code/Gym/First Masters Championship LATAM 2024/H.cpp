// Problem: H. Hidden Textland Pattern
// Contest: Codeforces - First Masters Championship LATAM 2024
// URL: https://codeforces.com/gym/104990/problem/H
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

const ll INF = LLONG_MAX / 4;
const ld PI = acos(-1);
const int MOD = 1000000007;
const double eps = 1e-9;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    vector<vector<int>> ct(26);
    for (int i = 0; i < n; i++) {
    	ct[s[i]-'a'].pb(i);
    }
    int best = 0;
    for (auto& i : ct) best = max(best, (ll)i.size());
    string goats;
    for (int i = 0; i < 26; i++) {
    	if (ct[i].size() == best) goats += (i + 'a');
    }
    
    string ans;
    for (auto& goat: goats) {
    	string base; base += goat;
    	
    	for (int i = 1; i <= n; i++) {
    		int idx = ct[goat-'a'][0] + i;
    		if (idx >= n) break;
    		
    		char next = s[idx];
    		bool poss = true;
    		for (int j = 0; j < ct[goat-'a'].size(); j++) {
    			idx = ct[goat-'a'][j] + i;
    			if (idx >= n or s[idx] != next) {
    				poss = false;
    				break;
    			}
    		}
    		
    		if (poss) base += next;
    		else break;
    	}
    	
    	if (base.length() > ans.length()) {
    		ans = base;
    	}
    	else if (base.length() == ans.length()) {
    		ans = min(ans, base);
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
