// Problem: A. Fraction and Six
// Contest: Codeforces - Codeforces Round 1131 (Div. 3)
// URL: https://codeforces.com/contest/2278/problem/A
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

void solve() {
    int n, m; cin >> n >> m;
    string s, t; cin >> s >> t;
    map<char, int> ct;
    for (auto& i : s) ct[i]++;
    for (auto& i : t) {
    	ct[i]--;
    }
    
    bool ans = true;
    bool f1 = false, f2 = false, f3 = false;
    for (auto& i : ct) {
    	if (i.second < 0) ans = false;
    	else if (!i.second) continue;
    	
    	if (i.first == 's') {
    		if (i.second != 1) ans = false;
    		else f1 = true;
    	}
    	
    	else if (i.first == 'i') {
    		if (i.second != 1) ans = false;
    		else f2 = true;
    	}
    	
    	else if (i.first == 'x') {
    		if (i.second != 1) ans = false;
    		else f3 = true;
    	}
    	else ans = false;
    }
    
    if (ans and f1 and f2 and f3) cout << "YES" << ln;
    else cout << "NO" << ln;
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
