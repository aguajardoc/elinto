// Problem: D. Ehab and another another xor problem
// Contest: Codeforces - Codeforces Round 525 (Div. 2)
// URL: https://codeforces.com/contest/1088/problem/D
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

int query(int c, int d) {
	cout << "? " << c << " " << d << endl;
	int r;
	cin >> r;
	return r;
}

void solve() {
    int larger = query(0, 0);
    int curA = 0, curB = 0;
    
    for (int i = 29; i >= 0; i--) {
    	int F = query((curA | (1 << i)), curB);
    	int S = query(curA, (curB | (1 << i)));
    	
    	if (F != S) {
    		if (S == 1) {
    			curA |= (1 << i);
    			curB |= (1 << i);
    		}
    	}
    	else {
    		if (larger == 1) {
    			curA |= (1 << i);
    		}
    		else curB |= (1 << i);
    		
    		larger = F;
    	}
    }
    
    cout << "! " << curA << " " << curB << ln;
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
