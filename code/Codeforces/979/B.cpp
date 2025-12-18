// Problem: B. Treasure Hunt
// Contest: Codeforces - Codeforces Round 482 (Div. 2)
// URL: https://codeforces.com/contest/979/problem/B
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

ll getAns(string s, int n) {
	// get char with most appearances
	int ogn = n;
	map<char, int> ct;
	for (auto& i : s) {
		ct[i]++;
	}
	
	char best;
	int app =0;
	for (auto& i : ct) {
		if (i.second > app) {
			best = i.first;
			app = i.second;
		}
	}
	
	// do all ops possible until ribbon ends
	int ans = app;
	for (auto& i : s) {
		if (!n) break;
		if (i != best) {
			n--;
			ans++;
		}
	}
	
	// if remaining ops % 2 == 0, keep, else -=1
	if (ogn == 1 and ct.size() == 1) ans--;
	// dbg(ans);
	return ans;
}

void solve() {
    int n;
    cin >> n;
    string kuro, shiro, katie;
    cin >> kuro >> shiro >> katie;
    
    vector<pair<int, string>> res = {{getAns(kuro,n), "Kuro"},
    								{getAns(shiro,n), "Shiro"},
    								{getAns(katie,n), "Katie"}};
    								
    sort(res.rbegin(), res.rend());
    if (res[1].first == res[0].first) cout << "Draw" << ln;
    else cout << res[0].second << ln;
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
