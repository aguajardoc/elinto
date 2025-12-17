// Problem: C. Crazy Town
// Contest: Codeforces - Codeforces Round 284 (Div. 2)
// URL: https://codeforces.com/contest/499/problem/C
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
#define ld long double
#define pb push_back
#define INF 2e18
#define PI 3.14159265358979323846
#define MOD 1000000007

double eps = 1e-9;

vector<ll> generate(int n, vector<vector<ll>>& a, int x, int y) {
	vector<ll> sign(n, 0);
	for (int i = 0; i < n; i++) {
    	ll val = a[i][0] * x + a[i][1] * y + a[i][2];
    	if (val < 0) val = -1;
    	if (val > 0) val = 1;
    	sign[i] = val;
    }
    
    return sign;
}

ll getDiff(vector<ll>& a, vector<ll>& b) {
	int n = a.size();
	int d = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] != b[i]) d++;
	}
	return d;
}

void solve() {
    ll x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    
    ll n;
    cin >> n;
    vector<vector<ll>> eqs(n, vector<ll> (3, 0));
    for (auto& i : eqs){
    	cin >> i[0] >> i[1] >> i[2];
    }
    
    vector<ll> sign = generate(n, eqs, x1, y1);
    vector<ll> sx2y2 = generate(n, eqs, x2, y2);    
  
    ll sto = getDiff(sign, sx2y2); 
    
    cout << sto << ln;
}

signed main() {
    fast_cin();
    
    ll t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
