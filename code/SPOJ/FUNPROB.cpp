// Problem: Yanu in Movie theatre
// Contest: SPOJ - Classical
// URL: https://www.spoj.com/problems/FUNPROB/
// Memory Limit: 1536 MB
// Time Limit: 506 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ld long double

void solve() {
    long long n, m;
    while(cin >> n) {
    	cin >> m;
    	if (n == 0 and m == 0) break;
    	
    	ld res;
    	if (n > m) res = 0;
    	else {
    		res = (ld)(m - n + 1) / (ld)(m + 1);
    	}
		cout << fixed << setprecision(6) << res << endl;
    }
}

signed main() {
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
