// Problem: C. Mahmoud and Ehab and the wrong algorithm
// Contest: Codeforces - Codeforces Round 473 (Div. 2)
// URL: https://codeforces.com/contest/959/problem/C
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
#define INF 2e18
#define PI 3.14159265358979323846
#define MOD 1000000007

double eps = 1e-9;

void print(vector<pair<int, int>>& x) {
	for (auto& i : x) {
		cout << i.first << " " << i.second << ln;
	}
}

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> ELR, ELW;
    
    for (int i = 2; i <= n; i++) {
    	ELR.push_back({1, i});
    }
    
    ELW.push_back({1, 2});
    ELW.push_back({1, 3});
    ELW.push_back({1, 4});
    ELW.push_back({2, 5});
    ELW.push_back({2, 6});                
    for (int i = 7; i <= n; i++) {
    	ELW.push_back({2, i});
    }
    
    if (n <= 5) {
    	cout << -1 << ln;
    }
    else print(ELW);
    print(ELR);
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
