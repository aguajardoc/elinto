// Problem: B. Special Offer! Super Price 999 Bourles!
// Contest: Codeforces - Codeforces Round 135 (Div. 2)
// URL: https://codeforces.com/contest/219/problem/B
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
#define INF 2e18
#define PI 3.14159265358979323846
#define MOD 1000000007

double eps = 1e-9;

void solve() {
    ll p, d;
    cin >> p >> d;
    if (p == (ll)1e18) {
    	if (d) cout << (ll)(1e18) - 1 << ln;
    	else cout << p << ln;
    	return;
    }
    
    ll ans;
    int ct9T = -1;
   	
   	string a = to_string(p); 
    for (int i = 0; i <= a.length(); i++) {
    	string ver = a.substr(0, i);
    	ll nv;
    	if (i == 0) nv = 0;
    	else nv = stoll(ver);
    	
    	string oth = a.substr(i, string::npos);
    	for (auto& i : oth) i = '9';
		
		string combi = ver + oth;
		// dbg(combi);
		while (stoll(combi) > p) {
			nv--;
			if (nv < 0) break;
			ver = to_string(nv);
			combi = ver + oth;
		}
		
		// dbg(combi);
		ll actualGoat = stoll(combi);
		// dbg(actualGoat);
		if (actualGoat < 0 or actualGoat > p) continue;
		ll diff = p  - actualGoat;
		if (diff <= d) {
			// dbg(1);
			int ct9 = 0;
			while (!combi.empty() and combi.back() == '9') {
				ct9++;
				combi.pop_back();
			}
			// dbg(1);
			
			if (ct9 > ct9T) {
				ans = actualGoat;
				ct9T = ct9;
			}
			else if (ct9 == ct9T){
				if (actualGoat > ans) {
					ans = actualGoat;
				}
			}		
		}
		
    }
    
    if (ans < 0) ans = p;
    
    cout << ans << ln;
}

signed main() {
    fast_cin();
    
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out