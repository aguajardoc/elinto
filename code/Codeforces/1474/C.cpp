// Problem: C. Array Destruction
// Contest: Codeforces - Codeforces Round 696 (Div. 2)
// URL: https://codeforces.com/contest/1474/problem/C
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

vector<int> check(int x, vector<int>& a, int n) {
	multiset<int> s(a.begin(), a.end());
	
	vector<int> res;
	for (int i = 0; i < n; i++) {
		auto ite = s.end();
		ite--;
		int y = x - *ite;
		s.erase(ite);
		
		if (!s.count(y)) return {};
		
		res.pb(x - y);
		res.pb(y);
		s.erase(s.find(y));
		x = max(x - y, y);
	}
	
	return res;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(2 * n);
    for (int i = 0; i < 2 * n; i++) {
    	cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    
    for (int i = 0; i < 2 * n - 1; i++) {
    	int x = a[i] + a.back();
    	vector<int> r = check(x, a, n);
    	
    	if (!r.empty()) {
    		cout << "YES" << ln;
    		cout << x << ln;
    		for (int i = 0; i < 2 * n; i+=2) {
    			cout << r[i] << " " << r[i + 1] << ln;
    		}
    		return;
    	}
    }
    
    cout << "NO" << ln;
    
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
