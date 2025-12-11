// Problem: B. Towers
// Contest: Codeforces - Codeforces Round 274 (Div. 2)
// URL: https://codeforces.com/contest/479/problem/B
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
    int n, k;
    cin >> n >> k;
    set<pair<int, int>> st;
    for (int i = 0; i < n; i++) {
    	int x;
    	cin >> x;
    	st.insert({x, i + 1});
    }
    
    if (n == 1) {
    	cout << 0 << " " << 0 << ln;
    	return;
    }
    
    vector<pair<int, int>> ops;
    int instability = (st.rbegin()->first - st.begin()->first);
    int minops = 0;
    int opsyet = 0;
    while(k-- and instability) {
    	opsyet++;
    	pair<int, int> smallest = *st.begin();
    	pair<int, int> largest = *st.rbegin();
    	
    	ops.push_back({largest.second, smallest.second});
    	smallest.first++;
    	largest.first--;    	
    	st.erase(*st.begin());
    	st.erase(*st.rbegin());    	
    	st.insert(smallest);
    	st.insert(largest);
    	if ((st.rbegin()->first - st.begin()->first) < instability) {
    		instability = (st.rbegin()->first - st.begin()->first);
    		minops = opsyet;
    	}
    }

    cout << instability << " " << opsyet << ln;
	for (int i = 0; i < opsyet; i++) {
    	cout << ops[i].first << " " << ops[i].second << ln;
    }
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
