// Problem: C. Thor
// Contest: Codeforces - Codeforces Round 366 (Div. 2)
// URL: https://codeforces.com/contest/705/problem/C
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

void print(set<pair<int, int>>& notis) {
	cout << "current notis: \n";
	for (auto& [x, y] : notis) {
		cout << "time: " << x << " value: " << y << ln;
	}
	cout << ln;
}

void solve() {
    int n, q;
    cin >> n >> q;
    set<pair<int, int>> notis, notis2;
    vector<vector<int>> queries(3);
    vector<int> typeIdx(q);
    for (int i = 0; i < q; i++) {
    	int x, y;
    	cin >> x >> y;
    	x--, y--;
    	queries[x].push_back(y);
    	typeIdx[i] = x;
    }
    
    int ct[3];
    ct[0] = ct[1] = ct[2] = 0;
    
    for (int i = 0; i < q; i++) {
    	int type = typeIdx[i];
    	
    	// print(notis);
    	
    	if (type == 0) {
    		int y = queries[type][ct[0]];
    		notis2.insert({y, ct[0]});
    		notis.insert({ct[0]++, y});
    	}
    	if (type == 1) {
    		int y = queries[type][ct[1]++];
    		while (!notis2.empty() and notis2.lower_bound(make_pair(y, -1)) != notis2.end() and notis2.lower_bound(make_pair(y, -1))->first == y) {
				int p1 = notis2.lower_bound(make_pair(y, -1))->first;
				int p2 = notis2.lower_bound(make_pair(y, -1))->second;
				notis.erase({p2, p1});
    			notis2.erase({p1, p2});
    		}
    	}
    	if (type == 2) {
    		int y = queries[type][ct[2]++];
    		while (!notis.empty() and notis.begin()->first <= y) {
				int p1 = notis.begin()->first;
				int p2 = notis.begin()->second;
				notis2.erase({p2, p1});
    			notis.erase(notis.begin());
    		}
    	}
    	
    	    	// print(notis);
    	
    	cout << notis.size() << ln;
    }
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
