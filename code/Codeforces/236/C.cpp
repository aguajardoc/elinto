// Problem: C. LCM Challenge
// Contest: Codeforces - Codeforces Round 146 (Div. 2)
// URL: https://codeforces.com/contest/236/problem/C
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

int brute(int n) {
	int mx = 0;
	int a, b, c;
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++)
	for (int k = 1; k <= n; k++) {
		int l = lcm(i, lcm(j, k));
		
		if (l > mx) {
			mx = l;
			a = i, b = j, c = k;
		}
	}
	
	dbg(a,b,c);
	
	return mx;
}

void solve() {
    int n;
    cin >> n;
    
    if (n == 1) {
    	cout << 1 << ln;
    }
    else if (n == 2) {
    	cout << 2 << ln;
    }
    else if (n == 3) {
    	cout << 6 << ln;
    }
    else {
    	if (n % 2) {
    		cout << lcm(n, lcm(n-1, n - 2)) << ln;
    	}
    	else if (n% 6) cout << lcm(n, lcm(n-1, n - 3)) << ln;
    	else cout << lcm(n-1, lcm(n-2, n-3)) << ln;
    }
    
    
    // int brut = brute(n);
//     
    // cout << brut << ln;
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
