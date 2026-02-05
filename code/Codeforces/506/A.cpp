// Problem: A. Mr. Kitayuta, the Treasure Hunter
// Contest: Codeforces - Codeforces Round 286 (Div. 1)
// URL: https://codeforces.com/contest/506/problem/A
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

int n, d;
int offset = 245;
int dp[30001][500], gems[30001];

int recurse(int idx, int l) {
	if (l + 245 < d or l - 245 > d) return 0;
	if (idx >= 30001) {
		return 0;
	}
	
	int adj = l - d + 245;
	
	
	if (dp[idx][adj] != -1) return dp[idx][adj];
	
	int res = 0;
	
	if (l > 1) res = max(res, recurse(idx + l - 1, l - 1) + gems[idx]);
	res = max(res, recurse(idx + l, l) + gems[idx]);
	res = max(res, recurse(idx + l + 1,  l + 1) + gems[idx]);
	
	return dp[idx][adj] = res;
}

void solve() {
    cin >> n >> d;
    fill_n(&dp[0][0], 30001*500, -1);
    fill(gems, gems + 30001, 0);
    for (int i = 0; i < n; i++) {
    	int x;
    	cin >> x;
    	gems[x]++;
    }
    
    cout << recurse(d, d) << ln;
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