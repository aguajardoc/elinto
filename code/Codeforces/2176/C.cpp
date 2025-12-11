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

void solve() {
    ll n;
    cin >> n;
    vector<ll> odds, evens;
    for (ll i =0; i < n ; i++) {
    	ll x;
    	cin >> x;
    	if (x % 2) odds.push_back(x);
    	else evens.push_back(x);
    }
    
    if (odds.empty()) {
    	for (ll i = 0; i < n; i++) {
    		cout << 0 << " ";
    	}
    	cout << ln;
    	return;
    }
    
    sort(odds.begin(), odds.end());   
    
    if (evens.empty()) {
    	ll bo = odds.back();
    	for (ll i = 0; i < n; i++) {
    		if (i % 2) cout << 0 << " ";
    		else cout << bo << " ";
    	}
    	cout <<ln;
    	return;
    }
    sort(evens.begin(), evens.end());
    
    
    vector<ll> ans;
    ll res = 0;
    ll l1 = 0, l2 = 0;
    bool flag = false;
    bool perm0 = false;
    if (odds.size() % 2 == 0) perm0 = true;
    for (ll i = 0; i < n; i++) {
    	if (perm0 and i == n - 1) l1 = 0;
    	
    	if (i == 0) {
    		res += odds.back();
    	}
    	else {
    		if (evens.empty()) {
    			if (!flag) {
    				cout << l1 << " ";
    			}
    			else cout << l2 << " ";
    			
    			flag = not flag;
    			
    			continue;
    		}
    		else{
    		 		res += evens.back();
    		 		evens.pop_back();
    		}   
    	}
    	cout << res << " ";
    	l1 = l2;
    	l2 = res;
    }
    cout << ln;
}

int main() {
    fast_cin();
    
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
