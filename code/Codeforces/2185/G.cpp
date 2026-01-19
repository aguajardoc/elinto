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

int getMex(map<int, int>& a) {
	int cur = 0;
	for (auto& i : a) {
		if (i.first != cur) break;
		cur++;
	}
	
	return cur;
}

int getMissmex(map<int, int>& a, int& mv) {
	int tolerance = 1;
	int cur = 0;
	for (auto& i : a) {
		if (i.first != cur) {
			if (tolerance) {
				tolerance--;
				mv = cur;
				cur++;
				
				// dbg(i.first, cur);
				
				if (i.first != cur) {
					break;
				}
				else {
					cur++;
					continue;
				}
			}
			else {
				break;
			}
		}
		cur++;
	}
	
	if (mv == -1) {
		mv = cur;
		cur++;
	}
	
	return cur;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n);
    // Get count of each num in each array
    vector<map<int, int>> ct(n);
    for (int i = 0; i < n; i++) {
    	int m;
    	cin >> m;
    	for (int j = 0; j < m; j++) {
    		int x;
    		cin >> x;
    		a[i].pb(x);
    		ct[i][x]++;
    	}
    }
    
    // Get mex
    // Get sum of mexes
    vector<int> mexes(n);
    int mexSum = 0;
    for (int i = 0; i < n; i++) {
    	mexes[i] = getMex(ct[i]);
    	mexSum += mexes[i];
    	// dbg(mexes[i]);
    }
    // Get mex ignoring one
    // Get ignored element
    // Get count of ignored element
    // Get sum of (mex ignoring one) for each ignored element
    // Get sum of differences for each ignored element
    vector<int> missmex(n), missing(n), diff(n);
    map<int, int> ctmissing;
    map<int, int> missum;
    map<int, int> missdiff;
    for (int i = 0; i < n; i++) {
    	int mv = -1;
    	missmex[i] = getMissmex(ct[i], mv);
    	missing[i] = mv;
    	ctmissing[mv]++;
    	missum[mv] += missmex[i];
    	missdiff[mv] += missmex[i] - mexes[i];
    	diff[i] = missmex[i] - mexes[i];
    	
    	// dbg(missmex[i], mexes[i]);
    	// dbg(mv);
    }
    // dbg(missdiff[0]);
    
    // Iterate over all
    int ans = 0;
    for (int i = 0; i < n; i++) {
    	int m = a[i].size();
    	
    	for (int j = 0; j < m; j++) {
    		// Add effect on itself
    		if (a[i][j] < mexes[i]) {
	    		if (ct[i][a[i][j]] == 1) {
	    			ans += a[i][j] * (n - 1);
	    		}
	    		else {
	    			ans += mexes[i] * (n - 1);
	    		}
    		}
    		else {
    			ans += mexes[i] * (n - 1);
    		}
    		
    		// dbg(i, j);
    		// dbg(ans);
    		
    		// Add effect on others
    		int affected = ctmissing[a[i][j]];
    		int sumMiss = missdiff[a[i][j]];
    		// ans += sumMiss;
    		ans += mexSum * (n - 1) + sumMiss - mexes[i] * (n - 1);
    		
    		// dbg(sumMiss);
    		// dbg(ans);
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
