// Problem: C. Dwarves, Hats and Extrasensory Abilities
// Contest: Codeforces - Codeforces Round 516 (Div. 1, by Moscow Team Olympiad)
// URL: https://codeforces.com/contest/1063/problem/C
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

int query(int x, int y) {
	cout << x << " " << y << endl;
	string s;
	cin >> s;
	return (s == "white");
}

void solve() {
    int n;
    cin >> n;
    
    int original_color = query(1, 1);
    n--;
    
    if (n == 0) {
    	cout << "2 2 2 0" << ln;
    	return;
    }
    
    int cur = 5e8+1, add = 5e8;
    
    // Query until different
    while (n-- > 0) {
    	int r = query(cur, 1);
    	
    	if (r != original_color) break;
    	
    	add >>= 1;
    	cur += add;
    }
    
    // If different, bound to cur - add and cur
    int l = cur - add, r = cur;
    int last_original = cur-add;
    while (l <= r and n-- > 0) {
    	int m = (l + r) >> 1;
    	if (m == cur - add) m++;
    	else if (m == cur) m--;
    	
    	int q = query(m, 1);
    	
    	if (q == original_color) {
    		// Lean to right
    		last_original = max(last_original, m);
    		l = m + 1;
    	}
    	else {
    		// Lean left
    		r = m - 1;
    	}
    }
    
    cout << last_original << " " << 2 << " " << last_original+1 << " " << 0 << ln;
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
