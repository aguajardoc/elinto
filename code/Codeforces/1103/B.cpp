// Problem: B. Game with modulo
// Contest: Codeforces - Codeforces Round 534 (Div. 1)
// URL: https://codeforces.com/contest/1103/problem/B
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

char query(int x, int y) {
	cout << "? " << x << " " << y << endl;
	char r;
	cin >> r;
	return r;
}

void solve() {
    string s;
    while (cin >> s and s == "start") {
    	int x = 1;
    	int y = 0;
    	int a = 0;
    	
    	while (x <= 2e9 and query(x, y) == 'x') {
    		x <<= 1;
    		if (!y) y = 1;
    		else y <<= 1;
    	}
    	
    	if (x > 2e9) {
    		cout << "! " << 1 << endl;
    		continue;
    	}
    	
    	int L = y, R = x;
    	while (L <= R) {
    		int M = (L + R) / 2;
    		char fm = query(M, y);
    		
    		if (fm == 'x') {
    			a = max(a, M);
    			L = M + 1;
    		}
    		else {
    			R = M - 1;
    		}
    	}
    	
    	cout << "! " << a + 1 << endl;
    }
}

signed main() {
    // fast_cin();
    
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
