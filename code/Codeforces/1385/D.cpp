// Problem: D. a-Good String
// Contest: Codeforces - Codeforces Round 656 (Div. 3)
// URL: https://codeforces.com/contest/1385/problem/D
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

vector<int> costs;
int n;
string s;

int recurse(int p, int l, int r, char c='a') {
	if (l == r) {
		return (s[l] != c);
	}
	if (costs[p] != -1)dbg(l, r, costs[p]);
	if (costs[p] != -1) return costs[p];
	
	int res = INF;
	int m = (l + r) / 2;
	
	int LC = 0, RC = 0;
	for (int i = l; i <= m; i++) LC += (s[i] != c);
	for (int i = m+1; i <= r; i++) RC += (s[i] != c);
	
	
	res = min(res, recurse(2*p, l, m, c+1) + RC);
	res = min(res, recurse(2*p+1, m+1, r, c+1) + LC);
	return costs[p] = res;
}

void solve() {
    cin >> n;
    cin >> s;
    costs.assign(4 * n, -1);
    cout << recurse(1, 0, n - 1) << ln;
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
