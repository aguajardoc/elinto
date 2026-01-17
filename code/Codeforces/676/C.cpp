// Problem: C. Vasya and String
// Contest: Codeforces - Codeforces Round 354 (Div. 2)
// URL: https://codeforces.com/contest/676/problem/C
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

int get(vector<int>& p, int n, int k) {
	int res = 0;
	int r = 0;
	for (int l = 0; r <= n; l++) {
		while (r <= n and p[r] - p[l] <= k) {
			res = max(res, r - l);
			r++;
		}
	}
	
	return res;
}

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> prefa(n + 1, 0), prefb(n + 1, 0);
    for (int i = 1; i <= n; i++) {
    	prefa[i] = prefa[i-1] + (s[i-1] == 'a');
    	prefb[i] = prefb[i-1] + (s[i-1] == 'b');
    }
    
    // tp on both?
    int ans = max(get(prefa, n, k), get(prefb, n, k));
    
    cout << ans << ln;
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
