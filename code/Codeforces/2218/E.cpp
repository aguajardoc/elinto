// Problem: The 67th XOR Problem
// Contest: Codeforces
// URL: https://m1.codeforces.com/contest/2218/problem/E
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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

string bin(int x) {
	string s;
	while (x) {
		if (x%2) {
			s += '1';
		}
		else s += '0';
		
		x /= 2;
	}
	reverse(s.begin(), s.end());
	
	return s;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int ans = 0;
    for (auto& i : a) cin >> i;
    
    for (int i = 0; i < n; i++) {
    	for (int j = i+1; j < n; j++) {
    		ans = max(ans, a[i] ^ a[j]);
    	}
    }
    
    cout << ans << ln;
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
