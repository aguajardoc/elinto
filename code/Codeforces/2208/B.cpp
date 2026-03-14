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
    int n, k, p, m;
    cin >> n >> k >> p >> m;
    p--;
    
    deque<pair<int, int>> dq;
    for (int i = 0; i < n; i++) {
    	int x;
    	cin >> x;
    	dq.push_back({x, 0});
    	if (i == p) dq.back().second = 1;
    }
    
    int ans = 0;
    while (m) {
    	// Always either play minimum, or my card
    	
    	bool seen = false;
    	int pos = -1;
    	
    	// get elems from dq
    	int mn = INF;
    	int idxmn = -1;
    	vector<pair<int, int>> v;
    	for (int i = 0; i < k; i++) {
    		
    		v.push_back(dq.front());
    		int e = v.back().first;
    		int idx = i;
    		
    		if (e < mn) {
    			mn = e;
    			idxmn = idx;
    		}
    		
    		
    		
    		if (dq.front().second == 1) {
    			if (dq.front().first <= m) {
    				m -= dq.front().first;
    				ans++;
    				seen = true;
    				pos = i;
    			}
    			else pos = -67;
    			
    		}
    		
    		dq.pop_front();
    	}
    	
    	if (pos == -67) break;
    	
    	if (seen) {
    		for (int i = k - 1; i >= 0; i--) {
    			if (i == pos) {
    				dq.push_back(v[i]);
    			}
    			else {
    				dq.push_front(v[i]);
    			}
    		}
    	}
    	else {
    		if (mn <= m) {
    			m -= mn;
    			pos = idxmn;
    		}
    		else {
    			break;
    		}
    		
    		for (int i = k - 1; i >= 0; i--) {
    			if (i == pos) {
    				dq.push_back(v[i]);
    			}
    			else {
    				dq.push_front(v[i]);
    			}
    		}
    	}
    	
    	  
    }
    
    
    cout << ans << ln;
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
