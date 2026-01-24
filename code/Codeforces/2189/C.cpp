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

vector<vector<int>> ans;

bool check(vector<int>& a, int n) {
	// if (a.back() != 3) return false;
	// for (int i = 0; i <n - 1; i++) {
		// bool poss = false;
		// for (int j = i; j < n; j++) {
			// if ((a[i] ^ a[j]) == (i + 1)) poss = true;
		// }
// 		
		// if (!poss) return false;
	// }
	
	for (int i = 1; i <n - 1; i++) {
		bool poss = false;
		for (int j = i; j < n; j++) {
			if ((a[i] ^ a[j]) == (i + 1)) poss = true;
		}
		
		if (!poss) return false;
	}
	
	// for (auto& i : a) {
    	// // for (auto& j : i) {
    		// cout << i - 1 << " ";
    	// // }
    	// cout << ln << flush;
    // }
	return true;
}

void recurse(int idx, int n, vector<int>& cur) {
	
	if (idx == n) {
		if (check(cur, n)) ans.pb(cur);
		return;
	}
	
	for (int i = 1; i <= n; i++) {
		if (find(cur.begin(), cur.end(), i) != cur.end()) continue;
		
		cur.pb(i);
		recurse(idx + 1, n, cur);
		cur.pop_back();
	}
}

void solve() {
    int n;
    cin >> n;
    ans.clear();
    vector<int> c;
    recurse(0, n, c);
    
    for (auto& i : ans) {
    	for (auto& j : i) {
    		cout << j - 1 << " ";
    	}
    	cout << ln;
    }
    
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
