// Problem: C. Mahmoud and a Message
// Contest: Codeforces - Codeforces Round 396 (Div. 2)
// URL: https://codeforces.com/contest/766/problem/C
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

int dp[1001][1001];
vector<int> a;
string s;
int n;

int mnsp = INF;
int mxln = 0;

int recurse(int idx, int start, vector<int> inuse, int splits) {
	if (idx == n) {
		mnsp = min(mnsp, splits);
		return 1;
	}
	
	if (dp[idx][start] != -1) return dp[idx][start];
	
	int res = 0;
	
	bool poss = true;
	int nl = idx - start + 1;
	
	if (idx != start) {
		inuse[s[idx] - 'a'] = 1;
		
		for (int i = 0; i < 26; i++) {
			if (inuse[i] and a[i] < nl) poss = false;
		}
		inuse[s[idx] - 'a'] = 0;
	}
	
	if (poss) {
		mxln = max(mxln, nl);
		
		inuse[s[idx] - 'a'] = 1;
		
		res += recurse(idx + 1, start, inuse, splits);
		res %= MOD;
	}
	if (idx != start) {
		vector<int> reuse(26, 0);
		reuse[s[idx] - 'a'] = 1;
		res += recurse(idx + 1, idx, reuse, splits + 1);
		res %= MOD;
	}
	
	
	// dbg(idx, start);
	// dbg(res);
	// cout << ln;
	
	return dp[idx][start] = res;
}


void solve() {
    cin >> n >> s;
    a.assign(26, 0);
    for (auto& i : a) cin >> i;
    vector<int> inuse(26, 0);
    
    fill_n(&dp[0][0], 1001*1001, -1);
    
    cout << recurse(0, 0, inuse, 1) << ln;
    cout << mxln << ln;
    cout << mnsp << ln;
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
