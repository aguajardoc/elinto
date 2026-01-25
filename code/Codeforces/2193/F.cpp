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

vector<vector<int>> dp;
vector<int> mn, mx;
vector<int> idxToX;
int m;

int recurse(int idx, bool L) {
	// dbg(idx);
	if (idx == m-1) {
		return 0;
	}
	
	if (dp[idx][L] != -1) return dp[idx][L];
	int res = 1e16;
	
	int curX = idxToX[idx];
	int nextX = idxToX[idx+1];
	int down = nextX - curX;
	
	// dbg(idxToX[idx+1]);
	int nextLR = mx[idx+1] - mn[idx+1];
	// dbg(idx);
	int curY;
	if (L) {
		curY = mn[idx];
	}
	else curY = mx[idx];
	
	int toLeft = abs(mn[idx+1] - curY);
	int toRight = abs(mx[idx+1] - curY);
	
	int dL = toLeft + down + nextLR;
	int dR = toRight + down + nextLR;
	
	// dbg(idx, L);
	// dbg(dL, dR);
	// dbg(toLeft);
	// dbg(toRight);
	// dbg(down, nextLR);
	
	// dbg(idx);
	// Go left
	res = min(res, recurse(idx + 1, 0) + dL);
	res = min(res, recurse(idx + 1, 1) + dR);
	
	return dp[idx][L] = res;
}

void solve() {
	int n;
    cin >> n;
    vector<int> x, y;
    int ax,ay,bx,by;
    cin >> ax >> ay >> bx >> by;
    x.pb(ax);
    y.pb(ay);
    for (int i = 0; i < n; i++) {
    	int xx;
    	cin >> xx;
    	x.pb(xx);
    }
    for (int i = 0; i < n; i++) {
    	int xx;
    	cin >> xx;
    	y.pb(xx);
    }
    x.pb(bx);
    y.pb(by);
    
    // Coord compression
    vector<int> vals = x;
    sort(vals.begin(), vals.end());
    vals.resize(unique(vals.begin(), vals.end()) - vals.begin());
    vector<int> ccs;
    
    // cout << ln;
    idxToX.assign(n + 3, -1);
    for (auto& i : x) {
    	int idx = lower_bound(vals.begin(), vals.end(), i) - vals.begin();
    	// dbg(i, idx);
    	idxToX[idx] = i;
    	ccs.pb(idx);
    }
    while (!idxToX.empty() and idxToX.back() == -1) idxToX.pop_back();
    
    m = idxToX.size();
    
    mn.assign(m, 1e10);
    mx.assign(m, 0);
    dp.assign(m, vector<int> (2, -1));
    
    // dbg(m);
    // Get mins and maxs
    for (int i = 0; i < n+2; i++) {
    	int cc = ccs[i];
    	
    	// dbg(cc, i);
    	// dbg(x[i]);
    	// dbg(y[i]);
    	mn[cc] = min(mn[cc], y[i]);
    	mx[cc] = max(mx[cc], y[i]);
    }
    
    int ans = recurse(0, 0);
    
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
