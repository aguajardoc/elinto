// Problem: 1081. Binary Lexicographic Sequence
// Contest: Timus Online Judge - Winter Mathematical Festival Varna '2001 Informatics Tournament
// URL: https://acm.timus.ru/problem.aspx?space=1&num=1081
// Memory Limit: 64 MB
// Time Limit: 500 ms
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

vector<int> F = {1, 1};

string to_binary(int x, int n) {
	string ans;
	while (x) {
		ans += ((x % 2) + '0');
		x >>= 1;
	}
	
	if (ans.length() > n) return "-1";
	while (ans.length() < n) ans += '0';
	
	reverse(ans.begin(), ans.end());
	
	return ans;
}

void solve() {
    int n, k;
    cin >> n >> k;
    k--;
    
    int res = 0;
    for (int i = 43; i >= 0; i--) {
    	if (k - F[i] >= 0) {
    		k -= F[i];
    		res += (1ll << (i-1));
    	}
    }
    
    cout << to_binary(res, n) << ln;
}

signed main() {
    fast_cin();
    
    while (F.back() < 1e9) {
    	F.pb(F[F.size() - 2] + F[F.size() - 1]);
    }
    
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
