// Problem: B. Non-square Equation
// Contest: Codeforces - Codeforces Round 144 (Div. 2)
// URL: https://codeforces.com/contest/233/problem/B
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

int getSum(int x) {
	string s = to_string(x);
	int d = 0;
	for (auto& i : s) {
		d += (i - '0');
	}
	
	return d;
}

void solve() {
    ll n;
    cin >> n;
    
    int ans = INF;
    for (int i = 1; i <= 200; i++) {
    	int sq = i * i + 4 * n;
    	int check1 = sqrt(sq);
    	if (check1 * check1 != sq) continue;
    	
    	int num = -i + check1;
    	if (num % 2) continue;
    	
    	int x = num / 2;
    	
    	int sd = getSum(x);
    	if (sd != i) continue;
    	
    	ans = min(ans, x);
    }
    
    cout << (ans == INF ? -1:ans) << ln;
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
