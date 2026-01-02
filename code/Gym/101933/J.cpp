// Problem: J. Jumbled String
// Contest: Codeforces - 2018-2019 ACM-ICPC Nordic Collegiate Programming Contest (NCPC 2018)
// URL: https://codeforces.com/gym/101933/problem/J
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

int unsq(int x) {
	int ans = 1e9;
	int l = 0, r = 1e5;
	while (l <= r) {
		int m = (l + r) / 2;
		int fm = (m * (m - 1)) / 2;
		
		if (fm >= x) {
			r = m - 1;
			ans = min(ans, m);
		}
		else {
			l = m + 1;
		}
	}
	
	return ans;
}

string construct(int z, int o, int b, int c) {
	int n = z + o;
	string s;
	for (int i = 0; i < o; i++) s += '1';
	for (int i = 0; i < z; i++) s += '0';
	
	int cb = 0, cc = b + c;
	int idx = o - 1;
	int idx2 = n - 1;
	while (cc > c) {
		// cc > c
		int d = cc - c;
		// dbg(d, idx2 - idx);
		if (idx2 - idx <= d) {
			swap(s[idx], s[idx2]);
			cc -= (idx2 - idx);
		}
		else {
			idx++;
		}
		idx--;
		idx2--;
	}
	
	return s;
}

bool verify(string s, int b, int c) {
	int oi = 0, io = 0;
	int n = s.length();
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (s[i] == '0' and s[j] == '1') oi++;
			if (s[i] == '1' and s[j] == '0') io++;
		}
	}
	
	return (oi == b and io == c);
}

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a == 0 and d == 0) {
    	string ans;
    	if (b == 0 and c == 0) {
    		ans = "0";
    	}
    	else if (b == 0 and c == 1) {
    		ans = "10";
    	}
    	else if (b == 1 and c == 0) {
    		ans = "01";
    	}
    	else {
    		ans = "impossible";
    	}
    	cout << ans << ln;
    	return;
    }
    
    
    // get z/o
    int z = unsq(a);
    int o = unsq(d);
    if (a == 0 and (b + c))z++;
    if (d == 0 and (b + c))o++;
    
    // verify z/o
    if ((a != ((z * (z - 1)) / 2)) or (d != ((o * (o - 1)) / 2))) {
    	cout << "impossible" << ln;
    	return;
    }
    
    // verify b and c
    if (b + c != z * o) {
    	cout << "impossible" << ln;
    	return;
    }
    
    // construct string
    string ans = construct(z, o, b, c);
    
    // verify res (dbg)
    // bool valid = verify(ans, b, c);
//     
    // if (valid) cout << "valid!\n";
    // if (!valid) cout << "invalid!\n";
    
    // print
    cout << ans << ln;
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