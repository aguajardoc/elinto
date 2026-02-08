// Problem: 348 - Optimal Array Multiplication Sequence
// Contest: UVa Online Judge
// URL: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=284
// Memory Limit: 32 MB
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

int dp[12][12], split[12][12];
vector<int> a;

int recurse(int l, int r) {
	if (l + 1 == r) return 0;
	
	if (dp[l][r] != -1) return dp[l][r];
	
	int res = INF;
	
	for (int k = l + 1; k < r; k++) {
		int local = recurse(l, k) + recurse(k, r) + a[l] * a[k] * a[r];
		if (local < res) {
			res = local;
			split[l][r] = k; 
		}
	}
	
	return dp[l][r] = res;
}

void print(int l, int r) {
	if (r == l + 1) {
		cout << "A" << r;
		return;
	}
	
	cout << "("; 
	print(l, split[l][r]);
	cout << " x ";
	print(split[l][r], r);
	cout << ")";
}

void solve() {
    int n;
    int tc = 1;
    while (cin >> n and n) {
    	a.assign(n + 1, 0);
    	vector<pair<int, int>> x(n);
    	fill_n(&dp[0][0], 12*12, -1);
    	fill_n(&split[0][0], 12*12, -1);
    	for (int i = 0; i < n; i++) {
    		int b, c;
    		cin >> x[i].first >> x[i].second;
    		a[i] = x[i].first;
    	}
    	a.back() = x.back().second;
    	cout << "Case " << tc++ << ": ";
    	recurse(0, n);
    	print(0, n);
    	cout << ln;
    }
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
