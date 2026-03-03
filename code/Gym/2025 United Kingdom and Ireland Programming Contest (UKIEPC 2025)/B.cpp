// Problem: B. Brickwork
// Contest: Codeforces - 2025 United Kingdom and Ireland Programming Contest (UKIEPC 2025)
// URL: https://codeforces.com/gym/106157/problem/B
// Memory Limit: 1024 MB
// Time Limit: 5000 ms
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

const int TREE_SIZE = 1 << 21;
int st[2 * TREE_SIZE];

void update(int i, int x) {
	i += TREE_SIZE;
	st[i] += x;
	i >>= 1;
	while(i) {
		st[i] = st[2 * i] + st[2 *i + 1];
		i >>= 1;
	}
}

int query(int l, int r) {
	l += TREE_SIZE;
	r += TREE_SIZE;
	int res = 0;
	
	while (l <= r) {
		if (l&1) res += st[l++];
		if (!(r&1)) res += st[r--];
		
		l >>= 1;
		r >>= 1;
	}
	
	return res;
}

struct Event {
	int x, type, y1, y2;
	
	bool operator<(const auto& other) {
		if (x != other.x) return x < other.x;
		return type < other.type;
	}
};

void solve() {
    int n;
    cin >> n;
  	
  	int mnx = INF, mxx = -INF;
  	int mny = INF, mxy = -INF;
  	int area = 0;
  	// iterate in sorted x order
  	// add y vals
  	vector<int> vals;
  	vector<Event> rects;
  	
  	for (int i = 0; i < n; i++) {
  		int x,y,w,h;
  		cin >> x >> y>> w >> h;
  		
  		mnx = min(mnx, x);
  		mxx = max(mxx, x+w);
  		
  		mny = min(mny, y);
  		mxy = max(mxy, y+h);
  		
  		area += w * h;
  		
  		rects.pb({x, 1, y, y + h});
  		rects.pb({x+w, -1, y, y + h});
  		
  		vals.pb(y);
  		vals.pb(y + h);
  	}
  	
  	sort(vals.begin(), vals.end());
  	vals.resize(unique(vals.begin(), vals.end()) - vals.begin());
  	
  	sort(rects.begin(), rects.end());
  	for (auto& i : rects) {
  		i.y1 = lower_bound(vals.begin(), vals.end(), i.y1) - vals.begin();
  		i.y2 = lower_bound(vals.begin(), vals.end(), i.y2) - vals.begin();
  	}
  	
  	int ra = (mxx - mnx) * (mxy - mny);

  	if (area != ra) {
  		cout << "no" << ln;
  		return;
  	}
  	
  	sort(rects.begin(), rects.end());
  	
  	for (auto& i : rects) {
  		// Process and check if good
  		update(i.y1, i.type);
  		update(i.y2 - 1, i.type);
  		
  		if (i.type == 1) {
  			if (query(i.y1, i.y2 - 1) > 2) {
  				cout << "no" << ln;
  				return;
  			}
  		}
  	}
  	
  	cout << "yes" << ln;
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
