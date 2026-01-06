// Problem: 128 - Software CRC
// Contest: UVa Online Judge
// URL: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=64
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
const int MOD = 34943;
const double eps = 1e-9;

string base16(int x) {
	string ans;
	while (x) {
		int d = x % 16;
		if (d < 10) {
			ans += (d + '0');
		}
		else {
			d -= 10;
			ans += (d + 'A');
		}
		x /= 16;
	}
	while (ans.size() < 4) ans.pb('0');
	reverse(ans.begin(), ans.end());
	
	return ans;
}

void solve() {
    string s;
    while (true) {
    	getline(cin, s);
    	if (s[0] == '#') return;
    	
    	ll mult = (1 << 16);
    	ll ans = 0;
    	int n = s.length();
    	for (int i = n - 1; i >= 0; i--) {
    		ans += s[i] * mult;
    		ans %= MOD;
    		mult *= 256;
    		mult %= MOD;
    	}
    	
    	int res = (MOD - ans) % MOD;
    	string r = base16(res);
    	cout << r.substr(0, 2) << " " << r.substr(2,2) << ln;
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
