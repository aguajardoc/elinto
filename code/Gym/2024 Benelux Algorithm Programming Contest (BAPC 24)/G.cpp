// Problem: G. Grocery Greed
// Contest: Codeforces - 2024 Benelux Algorithm Programming Contest (BAPC 24)
// URL: https://codeforces.com/gym/105492/problem/G
// Memory Limit: 1024 MB
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

int getDiff(string x) {
	int cents = stoi(x.substr(x.length() - 1, 1));
	
	if (cents >= 5) cents -= 5;
	if (cents == 3) return -1;
	if (cents == 4) return -2;
	
	return cents;
}

void trim(vector<ld>& a) {
	for (auto& i : a) {
		i *= 20;
		i = round(i);
		i /= 20;
	}
}

void solve() {
    int n;
    cin >> n;
    
    vector<ld> w1, w2, a;
    
    for (int i = 0; i < n; i++) {
    	string x;
    	cin >> x;
    	int d = getDiff(x);
    	if (d == -1) w1.pb(stold(x));
    	else if (d == -2) w2.pb(stold(x));
    	else a.pb(stold(x));
    }
    
    while (!w1.empty() and !w2.empty()) {
    	a.pb(w1.back() + w2.back());
    	w1.pop_back();
    	w2.pop_back();
    }
    
    while (w1.size() >= 2) {
    	ld x = w1.back();
    	w1.pop_back();
    	ld y = w1.back();
    	w1.pop_back();
    	
    	a.pb(x+y);
    }
    
    while (w2.size() >= 3) {
    	ld x = w2.back();
    	w2.pop_back();
    	ld y = w2.back();
    	w2.pop_back();
    	ld z = w2.back();
    	w2.pop_back();
    	
    	a.pb(x+y+z);
    }
    
    trim(a);
    
    
    ld ans = 0;
    for (auto& i : a) ans += i;
    // dbg(ans);
    for (auto& i : w1) ans += i;
    // dbg(ans);
    for (auto& i : w2) ans += i;
    
    cout << fixed << setprecision(2) << ans << ln;
    
    
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
