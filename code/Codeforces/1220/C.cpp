// Problem: C. Substring Game in the Lesson
// Contest: Codeforces - Codeforces Round 586 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1220/problem/C
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
#define INF 2e18
#define PI 3.14159265358979323846
#define MOD 1000000007

double eps = 1e-9;

void solve() {
    string s;
    cin >> s;
    set<char> x;
    int n = s.length();
    
    for (int i = 0; i < n; i++) {
    	bool cur = false;
    	if (s[i] != 'a') {
	    	for (char y = s[i] - 1; y >= 'a'; y--) {
	    		if (x.count(y)) cur = true;
	    	}
    	}
    	
    	if (cur) cout << "Ann" << ln;
    	else cout << "Mike" << ln;
    	
    	x.insert(s[i]);
    }
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
