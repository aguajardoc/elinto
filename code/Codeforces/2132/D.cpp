// Problem: D. From 1 to Infinity
// Contest: Codeforces - Codeforces Round 1043 (Div. 3)
// URL: https://codeforces.com/contest/2132/problem/D
// Memory Limit: 256 MB
// Time Limit: 1500 ms
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

vector<int> digct = {9};

int getRes(int x) {
	string left = to_string(x);
	string right = left;
	for (auto& i : left) i = '0';
	
	int ans = 0;
	int teni = 1;
	while (teni <= x) teni*= 10;
	teni /= 10;
	
	int n = left.size();
	for (int i = 0; i < n; i++, teni/=10) {
		int leftn = 0;
		if (i)leftn = stoll(left.substr(0, i), NULL, 10);
		int d = (right[i] - '0');
		
		left[i] = right[i];
		right[i] = '0';
		
		int rightn = stoll(right, NULL, 10);
		for (int j = 1; j <= 9; j++) {
			// If before digit: 10^i * left + 1
			if (j < d) {
				ans += j * ((teni) * (leftn  + 1));
			}
			// If cur: 
			else if (j == d) {
				ans += j * (teni * leftn + rightn + 1);
			}
			else {
				ans += j * (teni * leftn);
			}
			
			// dbg(j, ans);
		}
	}
	
	
	return ans;
}

void solve() {
    int k;
    cin >> k;
    
    // Get previous power of 10
    int pow = 1;
    int i = 0;
    while (digct[i] <= k) {
    	pow *= 10;
    	i++;
    }
    // dbg(i, pow);
    
    // Get remaining digit count
    int rem = k;
    if (i) rem = (k - digct[i-1]);
    // Get remaining number count
    int R = pow + rem / (i + 1) - 1;
    int extra = rem % (i + 1);
    // dbg(R, extra);
    // Get full answer up to R
    int ans = getRes(R);
    
    string s = to_string(R + 1);
    for (int j = 0; j < extra; j++) {
    	ans += (s[j] - '0');
    }
    
    cout << ans << ln;
}

signed main() {
    fast_cin();
    int cur = 10;
    for (int i = 1; i < 17; i++, cur *= 10) {
    	digct.pb(digct.back() + 9ll * (i + 1ll) * cur);
    }
    
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
