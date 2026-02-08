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

void updateAdd(multiset<int>& mind, int x, multiset<int>& nums) {
	
	nums.insert(x);
	auto itL = nums.lower_bound(x);
	if (itL != nums.begin()) {
		itL--;
		mind.insert(x - *itL);
	}
	auto itR = nums.upper_bound(x);
	if (nums.count(x) > 1) itR = nums.lower_bound(x);
	if (itR != nums.end()) {
		mind.insert(*itR - x);
	}
	
	// Remove connection between before and after if existent
	if (itL != nums.begin() and itR != nums.end()) {
		if (mind.count(*itR-*itL)) mind.erase(mind.find(*itR - *itL));
	}
}

void updateDelete(multiset<int>& mind, int x, multiset<int>& nums) {
	// Add conn between before and after if existent
	// Remove conn with me and before and after
	auto itL = nums.lower_bound(x);
	if (itL != nums.begin()) {
		itL--;
		if (mind.count(x-*itL)) mind.erase(mind.find(x - *itL));
	}
	auto itR = nums.upper_bound(x);
	if (nums.count(x) > 1) itR = nums.lower_bound(x);
	if (itR != nums.end()) {

		if (mind.count(*itR - x)) mind.erase(mind.find(*itR - x));
	}
	
	if (itL != nums.begin() and itL != nums.end() and itR != nums.end()) {
		mind.insert(*itR - *itL);
	}
	
	nums.erase(nums.find(x));
}

void solve() {
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    for (auto& i : a) cin >> i;
    
    multiset<int> mind;
    multiset<int> nums;
    
    int r = -1;
    int ans = 0;
    int its = 0;
    for (int l = 0;its <= 1e7 and r < n and l < n; l++) {
    	while (its <= 1e7 and r < n and (mind.empty() or *mind.begin() >= d)) {
    		ans += r - l + 1;
    		// dbg(l, r, ans);
    		its++;
    		updateAdd(mind, a[++r], nums);
    	}
    	
    	// dbg(l, r, ans);
    	
    	updateDelete(mind, a[l], nums);
    	its++;
    }
    
    cout << ans << ln;
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
