// Problem: C. Sad powers
// Contest: Codeforces - Codeforces Round 471 (Div. 2)
// URL: https://codeforces.com/problemset/problem/955/C
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

ll binexp(ll a, ll b) {
	ll res = 1;
	while(b) {
		if (b & 1) {
			bool r = __builtin_mul_overflow(a, res, &res);
			if (r) return MOD * MOD;
		}
		int fakeA = a;
		bool r = __builtin_mul_overflow(a, a, &fakeA);
		if (!r) a = a * a;
		b >>= 1;
	}
	return res;
}

bool isPrime(int x) {
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) return false;
	}
	return true;
}

vector<int> values;

void precalc(int L, int R) {
	int ans = 0;
    if (L == 1) {
    	L++;
    	values.pb(1);
    }

    
    // if its so easy to hardcode, why make it possible??? ew??
    vector<int> banned = {32768, 14348907, 30517578125, 470184984576, 4747561509943, 35184372088832, 1000000000000000, 4177248169415651, 15407021574586368, 51185893014090757, 155568095557812224, 437893890380859375, 2097152, 10460353203, 34359738368, 476837158203125, 21936950640377856, 50031545098999707, 558545864083284007, 8589934592, 5559060566555523, 36028797018963968, 549755813888, 2251799813685248, 144115188075855872};
    set<int> used;

    // bf for the rest
    for (ll p = 3; p <= 59; p++) {
    	if (!isPrime(p)) continue;
    	int x = 2;
    	ll res = 1;
    	while (res < R) {
    		res = binexp(x, p);
    		x++;
    		
    		if (res >= L and res <= R) {
    			// check its not a pow of 2
    			int y = sqrt((ll)res);
    			if ((y * y) == res) continue;
    			
    			// check its not a pow of anything else
    			if (find(banned.begin(), banned.end(), res) != banned.end()) {
    				if (!used.insert((ll)res).second) continue;
    			}
    			
    			values.pb(res);
    			ans++;
    		}
    	}
    }
    
    sort(values.begin(), values.end());
}

void solve() {
    int L, R;
    cin >> L >> R;
    int ans = 0;
    if (L == 1) {
    	L++;
    	ans++;
    }
    
    // p = 2
    int l = 0, r = 2e9;
    int fi = 1e10;
    while (l <= r) {
    	int m = (l + r) / 2;
    	
    	int fm = m * m;
    	
    	if (fm >= L) {
    		fi = min(fi, m);
    		r = m - 1;
    	} 
    	else {
    		l = m + 1;
    	}
    }
    
    int la = fi;
    l = 0, r = 2e9;
    while (l <= r) {
    	int m = (l + r) / 2;
    	
    	int fm = m * m;
    	
    	if (fm <= R) {
    		la = max(la, m);
    		l = m + 1;
    	} 
    	else {
    		r = m - 1;
    	}
    }
    	
    if (fi * fi >= L and fi * fi <= R and la * la >= L and la * la <= R) {
    	ans += la - fi + 1;
    }
    
    
    // Add from other powers
    auto itL = lower_bound(values.begin(), values.end(), L);
    auto itR = upper_bound(values.begin(), values.end(), R);
    itR--;
    
    // dbg(*itL, *itR);
    // dbg(ans);
    if (*itL >= L and *itL <= R and *itR >= L and *itR <= R) ans += distance(itL, itR) + 1;
    cout << ans << ln;
}

signed main() {
    fast_cin();
    precalc(1, 1000000000000000000);
    
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
