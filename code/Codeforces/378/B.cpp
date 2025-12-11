// Problem: B. Semifinals
// Contest: Codeforces - Codeforces Round 222 (Div. 2)
// URL: https://codeforces.com/contest/378/problem/B
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

void solve() {
    int n;
    cin >> n;
    vector<pair<int, pair<int, int>>> ranks;
    string a(n, '0'),b(n, '0');
    
    for (int i = 0; i < n; i++) {
    	
    	if (i < n / 2){
    		a[i] = '1';
    		b[i] = '1';
    	}
    	int l, r;
    	cin >> l >> r;
    	ranks.push_back({l, {0, i}});
    	ranks.push_back({r, {1, i}});
    }
    
    sort(ranks.begin(), ranks.end());
    
    for (int i = 0; i < n; i++) {
    	if (ranks[i].second.first) {
    		b[ranks[i].second.second] = '1';
    	}
    	else {
    		a[ranks[i].second.second] = '1';
    	}
    }
    
    cout << a << ln << b << ln;
}

int main() {
    fast_cin();
    
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
