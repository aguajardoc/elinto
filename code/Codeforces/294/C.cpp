// Problem: C. Shaass and Lights
// Contest: Codeforces - Codeforces Round 178 (Div. 2)
// URL: https://codeforces.com/contest/294/problem/C
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

int res = 0;
vector<int> newOrder;

bool check(vector<int> order, string s) {
	for (auto& i : order) {
		// cout << i << " ";
		if (i == 0) {
			if (s[i + 1] != '1') return false;
		}
		else if (i == (int)s.length() - 1) {
			if (s[i - 1] != '1') return false;
		}
		else {
			if (s[i - 1] != '1' and s[i + 1] != '1') return false;
		}
		
		s[i] = '1';
	}
	
	// cout << ln;
	
	return true;
}

void print(vector<int>& a) {
	for (auto& i : a) {
		cout << i << " ";
	}
	cout << ln;
}

void recurse(int idx, int& n, vector<int>& order, string& s) {
	if (idx == n) {
		res += check(order, s);
		return;
	}
	
	for (int i = 0; i < n; i++) {
		if (!count(order.begin(), order.end(), newOrder[i])) {
			order.pb(newOrder[i]);
			recurse(idx + 1, n, order, s);
			order.pop_back();
		}
	}
}

int brute(string s) {
	res = 0;
	vector<int> ord;
	int n = s.length();
	for (int i = 0; i < n; i++) {
		if (s[i] == '0') {
			newOrder.pb(i);
		}
	}
	n = newOrder.size();
	recurse(0, n, ord, s);
	return res;
}

vector<int> ynum(1001, 1), yden(1001, 1);

void inity() {
	int divEven = 1, divOdd = 3;
	for (int i = 2; i <= 1000; i++) {
		if (i % 2 == 0) {
			ynum[i] = 1;
			yden[i] = divEven++;
		}
		else {
			ynum[i] = 2;
			yden[i] = divOdd;
			divOdd += 2;
		}
		
		ynum[i] %= MOD;
		yden[i] %= MOD;
		
		// if (i <= 11) {
			// dbg(ynum[i],yden[i]);
		// }
	}
}

void initx(vector<int>& x, string& s) {
	if (s[0] == '0') {
    	auto it = s.find('1');
    	x.pb(it);
    }
    if (s.back() == '0') {
    	reverse(s.begin(), s.end());
    	auto it = s.find('1');
    	x.pb(it);
    }
}

void initys(vector<int>& y, string& s) {
	int cons = 0;
	// get all consecutive 0 counts
	auto it = s.find('1');
	for (int i = it; i < s.length(); i++) {
		if (s[i] == '1') {
			if (cons) {
				y.pb(cons);
				cons = 0;
			}
		}
		else {
			cons++;
		}
	}
}

vector<int> factorial = {1, 1};

ll binexp(ll a, ll b) {
	ll res = 1;
	while(b) {
		if (b & 1) {
			res = (res * a) % MOD;
		}
		
		a = (a * a) % MOD;
		b >>= 1;
	}
	return res;
}

void solve() {
    int n, m;
    cin >> n >> m;
    string s(n, '0');
    int z = n - m;
    for (int i = 0; i < m; i++) {
    	int x;
    	cin >> x;
    	s[x-1]= '1';
    }
    
    // cout << brute(s) << ln;
    
    vector<int> x;
    initx(x, s);
    
    vector<int> y;
    initys(y, s);
    
    // get answer (wtf)
    ll ans = factorial[z];
    // dbg(ans);
    
    // int num = 1, den = 1;
    // for (int i = 1; i <= 11; i++) {
    	// num *= ynum[i];
    	// den *= yden[i];
    	// dbg(i);
    	// dbg(num, den);
    // }
    
    for (auto& i : y) {
    	
    	int num = 1, den = 1;
    	for (int j = 1; j <= i; j++) {
    		num *= ynum[j];
    		num %= MOD;
    		den *= yden[j];
    		den %= MOD;
    	}
    	ans *= num;
    	ans %= MOD;
    	ans *= binexp(den, MOD - 2);
    	ans %= MOD;
    	
    	// dbg(i, ans);
    	// dbg(num, den);
    }
    
    for (auto& i : x) {
    	ans *= binexp(factorial[i], MOD - 2);
    	ans %= MOD;
    }
    
    cout << ans << ln;
}

signed main() {
    fast_cin();
    inity();
    
    for (int i = 2; i <= 1000; i++) {
    	factorial.pb(factorial.back() * i);
    	factorial.back() %= MOD;
    }
    
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
