// Problem: D. Irreducible Anagrams
// Contest: Codeforces - Codeforces Round 616 (Div. 2)
// URL: https://codeforces.com/contest/1291/problem/D
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
    int n = s.length();
    vector<vector<int>> ct(n + 1, vector<int>(26, 0));
    vector<int> roll(26, 0);
    for (int i = 0; i < n; i++) {
    	roll[s[i] - 'a']++;
    	ct[i+1] = roll;
    }
    
    int q;
    cin >> q;
    while(q--) {
    	int l, r;
    	cin >> l >> r;
    	if (l == r) {
    		cout << "Yes" << ln;
    		continue;
    	}
    	
    	vector<int> comm = ct[r];
    	for (int i = 0; i < 26; i++) {
    		comm[i] -= ct[l-1][i];
    	}
    	
    	int active = 0;
    	for (int i = 0; i < 26; i++) {
    		if (comm[i]) active++;
    	}
    	
    	if (active >= 3) {
    		cout << "Yes" << ln;
    	}
    	else if (active == 1) {
    		cout << "No" << ln;
    	}
    	else {
    		if (s[l-1] == s[r-1]) {
    			cout << "No" << ln;
    		}
    		else cout << "Yes" << ln;
    	}
    }
    cout << ln;
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
