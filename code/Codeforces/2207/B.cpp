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

void print(vector<int>& a) {
	for (auto& i : a) {
		cout << i << " ";
	}
	cout << ln;
}

void solve() {
    int n, m, l;
    cin>> n >> m >> l;
    vector<int> a(n);
    for (auto& i : a) cin >> i;
    
    vector<int> anim(min(m, n + 1), 0);
    // dbg(anim.size());
    int idx = 0;
    for (int t = 1; t <= l; t++) {
    	// Choose to add
    	if (idx == n) {
    		// Do max always
    		auto it = max_element(anim.begin(), anim.end());
    		(*it)++;
    	}
    	else {
    		// Do min always
    		auto it = min_element(anim.begin(), anim.end());
    		(*it)++;
    	}
    	
    	// Kill
    	if (idx < n and a[idx] == t) {
    		// Kill maximum
    		auto it = max_element(anim.begin(), anim.end());
    		idx++;
    		
    		if (n - idx == (int)anim.size() - 2) {
    			anim.erase(it);
    		}
    		else (*it) = 0;
    	}
    	
    	// dbg(t);
    	// print(anim);
    	// cout << ln;
    }
    
    // cout << "THIS IS THE ASNWER" << ln;
    cout << *max_element(anim.begin(), anim.end()) << ln;
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
