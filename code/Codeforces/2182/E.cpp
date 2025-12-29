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

struct Person {
	int x, y, z;
	bool operator<(const auto& oth) {
		return z < oth.z;
	}
};

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    
    multiset<int> boxes;
    vector<Person> rec(n);
    for (int i = 0; i < m;i++) {
    	int x;
    	cin >> x;
    	boxes.insert(x);
    }
    
    for (int i = 0; i < n;i++) {
    	cin >> rec[i].x >> rec[i].y >> rec[i].z;
    	k -= rec[i].y;
    	rec[i].z -= rec[i].y;
    }
    
    sort(rec.rbegin(), rec.rend());
    vector<int> recrem;
    
    int f = 0;
    for (int i = 0; i < n; i++) {
    	auto it = boxes.lower_bound(rec[i].x);
    	
    	if (it != boxes.end()) {
    		// buy with y
    		f++;
    		boxes.erase(it);
    	}
    	else {
    		recrem.pb(rec[i].z);
    	}
    }
    
    // get cheapest
    sort(recrem.begin(), recrem.end());
    
    for (int i = 0; i  < recrem.size(); i++) {
    	if (k - recrem[i] >= 0) {
    		k -= recrem[i];
    		f++;
    	}
    }
    
    cout << f << ln;
    
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
