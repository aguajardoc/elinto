// Problem: C. To Add or Not to Add
// Contest: Codeforces - Codeforces Round 143 (Div. 2)
// URL: https://codeforces.com/contest/231/problem/C
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
int n, k;
vector<int> a, d, sak;

int f(int i, int j) {
	int res = d[j];
	// dbg(res);
	res += (a[i] - a[0]) * j; 
	// dbg(res);
	if (i) res -= a[i] * (i - 1);
	// dbg(res);
	if (i) res += sak[i - 1];
	// dbg(res);
	return res;
}

pair<int, int> binarySearch(int i) {
	int l = i, r = n - 1;
	int res = 1;
	int val = a.back();
	while (l <= r) {
		int m = (l + r) / 2;
		
		int fm = f(i, m);
		if (fm <= k) {
			int up = m - i + 1;
			if (up > res) {
				// dbg(i, m);
				// dbg(up, a[i]);
				res = up;
				val = a[i];
			}
			else if (up == res and a[m] < val) {
				val = a[i];
			}
			
			l = m + 1;
		}
		else {
			r = m - 1;
		}
	}
	
	return {res, val};
}

void debug() {
	for (int i = 0; i  < n;i++) {
		for (int j = i; j < n; j++) {
			dbg(i, j);
			dbg(f(i, j));
			cout << ln;
		}
		cout << ln;
	}
}

void solve() {
    cin >> n >> k;
    a.assign(n, 0);
    d.assign(n, 0);
    sak.assign(n, 0);
    for (auto& i : a) cin >> i;
    sort(a.rbegin(), a.rend());
    for (int i = 1; i < n; i++) {
    	d[i] = d[i - 1]  + (a[0] - a[i]);
    }
    for (int i = 1; i < n; i++) {
    	sak[i] = sak[i - 1] + a[i];
    }
    
    // debug();
    
    int ans = 1;
    int val = a.back();
    for (int i = 0; i < n; i++) {
    	pair<int, int> res = binarySearch(i);
    	
    	if (res.first > ans) {
    		ans = res.first;
    		val = res.second;
    	}
    	else if (res.first == ans and res.second < val) {
    		val = res.second;
    	}
    }
    
    cout << ans << " " << val << ln;
    
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
