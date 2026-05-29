// Problem: C. Chipmunk Theo and Equality
// Contest: Codeforces - Codeforces Round 1099 (Div. 2)
// URL: https://codeforces.com/contest/2231/problem/C
// Memory Limit: 512 MB
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

const ll INF = LLONG_MAX / 4;
const ld PI = acos(-1);
const int MOD = 1000000007;
const double eps = 1e-9;

void brute(vector<int>& a, int n) {
	for (int i = 0; i < n; i++) {
		int x = a[i];
		
		set<int> passed;
		passed.insert(x);
		
		while(true) {
			if (x % 2) x++;
			else x >>= 1;
			if (!passed.insert(x).second) break;
		}
		
		int k = passed.size();
		dbg(i, k);
	}
	
	cout << ln;
}

void brute2() {
	int mx = 0;
	for (int i = 1; i <= 1e4; i++) {
		int x = i;
		
		set<int> passed;
		passed.insert(x);
		
		while(true) {
			if (x % 2) x++;
			else x >>= 1;
			if (x == i) break;
			// if (!passed.insert(x).second) break;
		}
		
		int k = passed.size();
		mx = max(mx, k);
	}
	
	dbg(mx);
}

void fill_map(int x, map<int, int>& wash) {
	wash[x] = 0;
		
	int its = 0;
	while (true) {
		if (x%2)x++;
		else x>>=1;
		its++;
		if (wash.count(x)) break;
		wash[x] = its;
	}
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i : a) cin >> i;
    sort(a.begin(), a.end());
    
    // get ones that first can do, then just check those
    map<int, int> wash;
    fill_map(a[0], wash);
    
    vector<pair<int, int>> where;
    for (auto& [x, y] : wash) {
    	where.pb({x, y});
    }
    
    int k = where.size();
    
    vector<int> touched(k, 1), current(k, 0);
    for (int i = 1; i < n; i++) {
		int x = a[i];
		current.assign(k, 0);
		
		int magic = 85;
		vector<pair<int, int>> found(magic);
		
		
		int its = 0;
		while (its < 85) {
			found[its] = {x, its};
			if (x%2)x++;
			else x>>=1;
			its++;
		}
		
		sort(found.begin(), found.end());
		// for (auto& i : found) {
			// dbg(i.first, i.second);
		// }
		
		int idx = 0;
		for (int j = 0; j < k; j++) {
			// dbg(where[j].first);
			// if (idx < magic) dbg(found[idx].first);
			while (idx < magic and where[j].first > found[idx].first) idx++;
			if (idx == magic) break;
			
			// dbg(idx, j);
			// dbg(found[idx].first);
			// dbg(where[j].first);
// 			
			// dbg(found[idx].second);
			// dbg(where[j].second);
			
			if (found[idx].first == where[j].first) {
				current[j] = 1;
				where[j].second += found[idx].second;
			}
		}
		
		for (int j = 0; j < k; j++) {
			touched[j] &= current[j];
		}
	}
	
	int ans = INF;
	for (int i = 0; i < k; i++) {
		if (!touched[i]) continue;
		ans = min(ans, where[i].second);
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
