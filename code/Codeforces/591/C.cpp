// Problem: C. Median Smoothing
// Contest: Codeforces - Codeforces Round 327 (Div. 2)
// URL: https://codeforces.com/contest/591/problem/C
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

void process(int start, int n, vector<int>& ans) {
	
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i : a) cin >> i;
    
    int sti = -1;
    vector<int> ans(n, 0);
    
    // find blocks of cons 1's
    vector<int> cstarts, cends, altstarts, altends;
    for (int i = 0; i < n; i++) {
    	if (a[i] == 0) continue;
    	int start = i;
    	while (i < n and a[i] == 1) {
    		i++;
    	}
    	i--;
    	if (start == i and (i != 0 and i != n - 1)) continue;
    	// dbg(start, i);
    	cstarts.push_back(start);
    	cends.push_back(i);
    }
    
    // find blocks of alternating
    for (int i = 0; i < n; i++) {
    	if (a[i] == 1) continue;
    	int start = i;
    	int x = 0;
    	while (i < n and a[i] == x) {
    		i++;
    		x = 1 - x;
    	}
    	i--;
    	// dbg(start, i);
    	altstarts.push_back(start);
    	altends.push_back(i - (a[i] == 1));
    }
    
    int res = 0; 
    for (int i = 0; i < n; i++) {
    	// if i is altstart, intervene
    	auto it = lower_bound(altstarts.begin(), altstarts.end(), i);
    	if (it != altstarts.end() and *it == i) {	
    		// intervene
    		auto itB = lower_bound(cends.begin(), cends.end(), i - 1);
    		bool bside = (itB != cends.end() and *itB == i - 1);
    		
    		int j = *lower_bound(altends.begin(), altends.end(), i);
    		auto itE = lower_bound(cstarts.begin(), cstarts.end(), j + 1);
    		
    		bool eside = (itE != cstarts.end() and *itE == j + 1);
    		// dbg(i, j);
    		if (bside and eside) {
    			// all turn to ones in (j - i) / 2 + 1 turns
    			res = max(res, (j - i) / 2 + 1);
    			for (; i < j; i++) {
    				ans[i] = 1;
    			}
    			ans[i] = 1;
    		}
    		else if (bside) {
    			// turn first (j - i) / 2 to 1's, others to 0's
    			int x = (j - i) / 2;
    			res = max(res, (j - i) / 2);
    			for (int k = 0; k < x; k++, i++) {
    				ans[i] = 1;
    			}
    			for (; i < j; i++) {
    				ans[i] = 0;
    			}
    			ans[i] = 0;
    		}
    		else if (eside) {
    			// turn last (j - i) / 2 to 1's 
    			int x = (j - i) / 2;
    			res = max(res, x);
    			i = j;
    			for (int k = 0;  k < x; k++, j--) {
    				ans[j] = 1;
    			}
    		}
    		else {
    			// none, therefore, all 0s in (j - i) / 2 moves
    			res = max(res, (j - i) / 2);
    			i = j;
    		}
    	}
    	else {
    		// just place it.
    		ans[i] = a[i];
    	}
    }
    
    cout << res << ln;
    for (auto& i : ans) {
    	cout << i << " ";
    }
    cout << ln;
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
