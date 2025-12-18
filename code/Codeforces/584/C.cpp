// Problem: C. Marina and Vasya
// Contest: Codeforces - Codeforces Round 324 (Div. 2)
// URL: https://codeforces.com/contest/584/problem/C
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
    // cater to BE, then if rem to D
    int n, t;
    cin >> n >> t;
    
    int A = n-t, B = n-t;
    vector<int> BE, D;
    string a, b;
    cin >> a >> b;
    for (int i = 0; i < n; i++) {
    	if (a[i] == b[i]) BE.push_back(i);
    	else D.push_back(i);
    }
    
    string ans(n, 'a');

    while (A and B and !BE.empty()) {
    	ans[BE.back()] = a[BE.back()];
    	BE.pop_back();
    	A--;
    	B--;
    }
    

    
    // if still!
    while ((A or B) and !D.empty()) {
    	if (A >= B) {
    		ans[D.back()] = a[D.back()];
    		A--;
    	}
    	else {
    		ans[D.back()] = b[D.back()];
    		B--;
    	}
    	D.pop_back();
    }
    
    
    
    if (A or B) {
    	cout << -1 << ln;
    	return;
    }
    
    while (!BE.empty()) {
    	int idx = BE.back();
    	for (char i = 'a'; i <= 'z'; i++) {
    		if (a[idx] == i or b[idx] == i) continue;
    		ans[idx] = i;
    		break;
    	}
    	BE.pop_back();
    }
    
    while (!D.empty()) {
    	int idx = D.back();
    	for (char i = 'a'; i <= 'z'; i++) {
    		if (a[idx] == i or b[idx] == i) continue;
    		ans[idx] = i;
    		break;
    	}
    	D.pop_back();
    }
    
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
