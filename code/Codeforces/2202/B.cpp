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

vector<vector<vector<int>>> dp;
string x;
int n;

bool recurse(int idx, int l, int r) {
	if (idx == n) return 1;
	
	if (dp[idx][l][r] != -1) return dp[idx][l][r];
	bool res = false;
	if (x[idx] == 'a') {
		if (l == 0) {
			res |= recurse(idx + 1, 1, r);
		}
		if (r == 0) {
			res |= recurse(idx + 1, l, 1);
		}
	}
	else if (x[idx] == 'b') {
		if (l == 1) {
			res |= recurse(idx + 1, 0, r);
		}
		if (r == 1) {
			res |= recurse(idx + 1, l, 0);
		}
	}
	else {
		res |= recurse(idx + 1, 1 - l, r);
		res |= recurse(idx + 1, l, 1 - r);
	}
	
	return dp[idx][l][r] = res;
}

void solve() {
    cin >> n >> x;
    dp.assign(n + 1, vector<vector<int>> (2, vector<int> (2, -1)));
    cout << (recurse(0, 0, not (n % 2)) ? "YES":"NO") << ln; 
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
