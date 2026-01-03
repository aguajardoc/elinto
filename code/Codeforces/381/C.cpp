// Problem: C. Sereja and Prefixes
// Contest: Codeforces - Codeforces Round 223 (Div. 2)
// URL: https://codeforces.com/contest/381/problem/C
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
    int m;
    cin >> m;
    
    vector<pair<int, int>> addition;
    vector<vector<int>> cpoints;
    vector<int> start;
    int time = 0;
    
    for (int i = 0; i < m; i++) {
    	int type;
    	cin >> type;
    	if (type == 1) {
    		int ele;
    		cin >> ele;
    		time++;
    		addition.pb({time, ele});
    		
    		if (start.size() <= 1e5) start.pb(ele);    		
    	}
    	else {
    		int len, times;
    		cin >> len >> times;
    		cpoints.pb({time, len, times});
    		time += len * times;
    		// first copy, length of each, times copied
    		
    		while (start.size() <= 1e5 and times) {
    			for (int j = 0; j < len and start.size() <= 1e5; j++) {
    				start.pb(start[j]);
    			}
    			times--;
    		}
    	}
    }
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
    	int x;
    	cin >> x;
    	
    	// if exactly an addition, print it
    	auto it = lower_bound(addition.begin(), addition.end(), make_pair(x, -1ll));
    	if (it->first == x) {
    		cout << it->second << " ";
    		continue;
    	}
    	
    	// else, it is the product of a copy!
    	vector<int> search = {x, -1, -1};
    	auto it2 = upper_bound(cpoints.begin(), cpoints.end(), search);
    	it2--;
    	// should be guaranteed to exist...
    	auto iit = it2->begin();
    	
    	int diff = x - (*iit);
    	iit++;
    	int len = *iit;
    	iit++;
    	int c = *iit;
    	diff--;
    	
    	diff %= len;
    	
    	cout << start[diff] << " ";
    	
    }
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
