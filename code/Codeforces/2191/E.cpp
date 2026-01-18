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
const int MOD = 998244353;
const double eps = 1e-9;

void solve() {
    int n;
    cin >> n;
    int ans = 0;
    string s;
    cin >> s;
    for (auto& i : s) {
    	if (i == '(') i = '0';
    	if (i == ')') i = '1'; 
    }
    
    vector<int> p(n + 1, 0);
    for (int i = 0; i < n;i++) {
    	p[i+1] = p[i] + (s[i] == '0');
    }
    
    int dp[2][101][101][2][3];
    fill_n(&dp[0][0][0][0][0], 2*101*101*2*3, 0);
    dp[0][0][0][0][0] = 0;
    
    for (int i = 1; i <= n; i++) {
    	int now = i % 2;
    	int last = 1 - now;
    	
    	for (int j = 0; j < i; j++) {
    		for (int k = 0; k <= j; k++) {
    			for (int l = 0; l <= 1; l++) {
    				for (int e = 0; e <= 2; e++) {
    					int c = 0;
    					if (s[i-1] == '0') c = 1;
    					else c = -1;
    					
    					int trig = 0;
    					if (l == 1 and s[i-1] == '0') trig = 1;
    					if (e == 1 and s[i-1] == '0') trig = 1;
    					
    					
    					int addtake = 0;
    					if (k-c == 0 and l == 1 and trig and e==1) addtake = j - 2;
    					int addnot = 0;
    					if (k == 0 and l == 1 and e == 2) addnot = j - 2;
    					
    					int take = 0;
    					if (j-1>=0 and k-c >= 0 and l-trig >=0 and e >= 1)take = dp[last][j-1][k-c][l-trig][e-trig] + addtake;
    					int nottake = dp[last][j][k][l][e];
    					
    					dp[now][j][k][l][e] += take;
    					dp[now][j][k][l][e] %= MOD;
    					dp[now][j][k][l][e] += nottake;
    					dp[now][j][k][l][e] %= MOD;
    				}
    			}
    		}
    	}
    	
    	fill_n(&dp[last][0][0][0][0], 101*101*3*2, 0);
    }
    
    for (int i = 0; i <= n; i++) {
    	ans += dp[n%2][i][0][1][2];
    	dbg(i, ans);
    	ans %= MOD;
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
