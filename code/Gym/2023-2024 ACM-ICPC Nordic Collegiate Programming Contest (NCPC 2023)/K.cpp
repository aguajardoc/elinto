// Problem: K. Karl Coder
// Contest: Codeforces - 2023-2024 ACM-ICPC Nordic Collegiate Programming Contest (NCPC 2023)
// URL: https://codeforces.com/gym/105427/problem/K
// Memory Limit: 512 MB
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

int query(int i) {
	cout << "buf[" << i-1 << "]" << endl;
	int r;
	cin >> r;
	return r;
}

void solve() {
    int L = 2, R = 4;
    map<int, int> stored;
    while (true) {
    	int x = query(R);
    	stored[R] = x;
    	if (x == 0) break;
    	L = R;
    	R *= 2;
    }
    
    int n = 2;
    while (L <= R) {
    	int m = (L + R) / 2;
    	
    	int fm;
    	if (__builtin_popcountll(m) == 1)  {
    		fm = stored[m];
    	}else fm = query(m);
    	
    	if (fm) {
    		n = max(n, m);
    		L = m + 1;
    	}
    	else {
    		R = m - 1;
    	}
    }
    
    cout << "strlen(buf) = " << n << endl;
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
