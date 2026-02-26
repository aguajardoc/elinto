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

int sod(int x) {
	string s = to_string(x);
	int ans = 0;
	for (auto& i : s) {
		ans += (i - '0');
	}
	
	return ans;
}

vector<vector<vector<int>>> dp; // amm dig, sum lz
int n;
string x;
// sod of sum == sum

int recurse(int idx, int sum, bool lz) {
	if (sum >= 30) return INF;
	if (idx == n) {
		if (sod(sum) == sum) return 0;
		else return INF;
	}
	
	if (dp[lz][idx][sum] != -1) return dp[lz][idx][sum];
	
	int res = INF;
	char og = x[idx];
	for (char a = '0'; a <= '9'; a++) {
		if (a == '0' and !lz) continue;
		int cost = (a != og);
		res = min(res, recurse(idx + 1, sum + (a - '0'), 1) + cost);
	}
	
	return dp[lz][idx][sum] = res;
}

void solve() {
    cin >> x;
    n = x.length();
    
    dp.assign(2, vector<vector<int>>(n + 1, vector<int> (31, -1)));
    
    cout << recurse(0, 0, 0) << ln;
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
