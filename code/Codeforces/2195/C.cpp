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

vector<vector<int>> dp;
vector<int> a;
int n;

int recurse(int idx, int last) {
	if (idx == n) return 0;
	
	if (dp[idx][last] != -1) return dp[idx][last];
	
	int res = INF;
	
	// Check if current matches with prev and next
	if (idx == 0) {
		for (int i = 1; i <= 6; i++) {
			res = min(res, recurse(idx + 1, i) + (i != a[idx]));
		}
	}
	else if (idx == n - 1) {
		for (int i = 1; i <= 6; i++) {
			if (last == i or last == 7 - i) continue;
			
			res = min(res, recurse(idx + 1, i) + (i != a[idx]));
		}
	}
	else {
		for (int i = 1; i <= 6; i++) {
			if (last == i or last == 7 - i) continue;
			
			res = min(res, recurse(idx + 1, i) + (i != a[idx]));
		}
	}
	
	return dp[idx][last] = res;
}

void solve() {
    cin >> n;
    a.assign(n, 0);
    dp.assign(n + 1,  vector<int>(7, -1));
    
    for (auto& i : a) cin >> i;
    
    if (n == 1) {
    	cout << 0 << ln;
    	return;
    }
    
    cout << recurse(0, 0) << ln;
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
