// Problem: C. Needle in a Haystack
// Contest: Codeforces - Codeforces Round 1069 (Div. 2)
// URL: https://codeforces.com/contest/2175/problem/C
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
    string s, t;
    cin >> s >> t;
    int n = s.length();
    int m = t.length();
    
    int a = 0, b = 0;
    vector<int> ct(26, 0), ct2 = ct;
    for (int i = 0; i < n; i++) {
    	ct[s[i] - 'a']++;
    }
    for (int i = 0; i < m; i++) {
    	ct2[t[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
    	ct2[i] -= ct[i];
    	if (ct2[i] < 0) {
    		cout << "Impossible" << ln;
    		return;
    	}
    }
    
    string nt;
    for (int i = 0; i < m; i++) {
    	while (a != 27 and !ct2[a]) a++;
    	if (a != 27 and b != n) {
    		if (a < (s[b] - 'a')) {
	    		nt += (a + 'a');
	    		ct2[a]--;
	    		while (!ct2[a]) a++;
    		}
    		else nt += s[b++];
    	}
    	else if (a != 27) {
    		nt += (a + 'a');
	    	ct2[a]--;
	    	while (!ct2[a]) a++;
    	}
    	else {
    		nt += s[b++];
    	}
    }
    
    cout << nt << ln;
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
