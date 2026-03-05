// Problem: A. Bitwise Operation Wizard
// Contest: Codeforces - Codeforces Round 930 (Div. 1)
// URL: https://codeforces.com/contest/1936/problem/A
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

char query(int a, int b, int c, int d) {
	cout << "? " << a << " " << b << " " << c << " " << d << endl;
	char r;
	cin >> r;
	return r;
}

void answer(int a, int b) {
	cout << "! " << a << " " << b << endl;
}

void solve() {
    int n;
    cin >> n;
    // Find max
    int mx = 0;
    for (int i = 0; i < n; i++) {
    	char r = query(mx, mx, i, i);
    	if (r == '<') {
    		mx = i;
    	}
    }
    
    // Get candidates
    // All that have the largest or with mx
    int oth = 0;
    vector<int> cands;
    for (int i = 0; i < n; i++) {
    	char r = query(mx, oth, mx, i);
    	
    	if (r == '<') {
    		oth = i;
    		cands = {i};
    	}
    	if (r == '=') {
    		cands.pb(i);
    	}
    }
    
    // Get min of candidates
    int mn = 0;
    for (int i = 0; i < cands.size(); i++) {
    	char r = query(cands[mn], cands[mn], cands[i], cands[i]);
    	
    	if (r == '>') {
    		mn = i;
    	}
    }
    
    answer(mx, cands[mn]);
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
