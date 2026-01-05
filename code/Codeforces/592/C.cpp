// Problem: C. The Big Race
// Contest: Codeforces - Codeforces Round 328 (Div. 2)
// URL: https://codeforces.com/contest/592/problem/C
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

__int128 gcd(__int128 a, __int128 b, __int128& x, __int128& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    __int128 x1, y1;
    __int128 d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

void print(__int128 x) {
	string s;
	// dbg((ll)x);
	while (x) {
		// dbg((int)(x % 10));
		s += ((x % 10) + '0');
		x /= 10;
	}
	reverse(s.begin(), s.end());
	if (s.empty()) s = "0";
	cout << s;
}

__int128 lcm(__int128 w, __int128 b) {
	__int128 x, y;
	__int128 hcf = gcd(w, b, x, y);
	__int128 num = w * b;
	__int128 ans = num / hcf;
	
	return ans;
}

void solve() {
    ll t, w, b;
    cin >> t >> w >> b;
    
    if (w == 1 and b == 1) {
    	cout << "1/1" << ln;
    	return;
    }
    
    __int128 num = 0;
    if (w == 1 or b == 1) {
    	num = (__int128)t/(max(w, b));
    }
    else {
    	__int128 wb = lcm((__int128)w, (__int128)b);
    	__int128 k = (__int128)t / wb; 
    	
    	__int128 prelim = __int128(k - 1) * min(w, b);
    	__int128 prelim2 = prelim + min((__int128)min(w, b), t - k * wb + 1);
    	num = min(w, b) - 1 + prelim2;
    }
    __int128 den = t;
    
    __int128 x, y;
    __int128 hcf = gcd(num, den, x, y);
    
    num /= hcf;
    den /= hcf;
	
	print(num);cout <<"/"; print(den); cout << ln;
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
