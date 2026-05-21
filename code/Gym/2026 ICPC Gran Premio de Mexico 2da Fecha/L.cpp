// Problem: L. Landau's Fourth Problem
// Contest: Codeforces - 2026 ICPC Gran Premio de Mexico 2da Fecha
// URL: https://codeforces.com/gym/106540/problem/L
// Memory Limit: 512 MB
// Time Limit: 11000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
// #pragma GCC optimize("Ofast,unroll-loops")
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
// #define int ll
#define ld long double
#define pb push_back

const ll INF = LLONG_MAX / 4;
const ld PI = acos(-1);
const int MOD = 1000000007;
const double eps = 1e-9;

typedef unsigned long long ull;
ull modmul(ull a, ull b, ull M) {
    ll ret = a * b - M * ull(1.L / M * a * b);
    return ret + M * (ret < 0) - M * (ret >= (ll)M);
}

// Usage: a^b % m
ull binexp(ull a, ull b, ull m = 1000000007) {
    ull res = 1;
    a = modmul(a, 1, m);
    while (b) {
        if (b & 1) {
        	res = modmul(res, a, m);
        }

		a = modmul(a, a, m);
        b >>= 1;
    }

    return res;
}

bool check_composite(ll n, ll a, ll d, ll s) {
    ll x = binexp(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (ll r = 1; r < s; r++) {
    	x = modmul(x, x, n);
        if (x == n - 1)
            return false;
    }
    return true;
};

bool MillerRabin(ll n) { // returns true if n is prime, else returns false.
    if (n < 2)
    return false;
        
    if (n % 2 == 0) return n == 2;
    if (n % 5 == 0) return n == 5;
    if (n % 13 == 0) return n == 13;
    if (n % 17 == 0) return n == 17;
    if (n % 29 == 0) return n == 29;
    if (n % 37 == 0) return n == 37;
    if (n % 41 == 0) return n == 41;
    if (n % 53 == 0) return n == 53;
    if (n % 61 == 0) return n == 61;
    if (n % 73 == 0) return n == 73;
    if (n % 89 == 0) return n == 89;
    if (n % 97 == 0) return n == 97;

    ll r = 0;
    ll d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    }
    
    if (check_composite(n, 5, d, r))
        return false;
    
    return true;
}

struct Query {
	int x, idx;
	bool operator<(const auto& oth) {
		if (x != oth.x) return x < oth.x;
		return idx < oth.idx;
	}
};

int ans[4000001];

void solve() {
    int n;
    cin >> n;
    
    vector<Query> q(n);
    int mx = 0;
    for (int i = 0; i < n; i++) {
    	int x;
    	cin >> x;
    	q[i] = {x, i};
    	mx = max(mx, x);
    }
    
    sort(q.begin(), q.end());
    vector<int> ans(n, 0);
    
    int idx = 0;
    int res = 0;
    for (ll i = 1; i <= mx; i++) {
    	if (MillerRabin(i * i + 1)) res++;
    	
    	while (idx < n and q[idx].x == i) {
    		ans[q[idx].idx] = res;
    		idx++;
    	}
    }
    
    for (int i = 0; i < n; i++) {
    	cout << ans[i] << ln;
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
