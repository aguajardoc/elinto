// Problem: I - Drone Delivery and Altitude Control
// Contest: AtCoder - AtCoder Weekday Contest 0200 Beta
// URL: https://atcoder.jp/contests/awc0200/tasks/awc0200_i
// Memory Limit: 1024 MB
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

const ll INF = (ll)(LLONG_MAX / 4);
const ld PI = acos(-1);
const int MOD = 1000000007;
const double eps = 1e-9;

struct State {
	ll u, h, d, U, V;
	
	bool operator>(const auto& oth) const {
		if (d != oth.d) return d > oth.d;
		if (u != oth.u) return u < oth.u;
		return h < oth.h;
	}
};

ll dist[1001][12][12][12];

void solve() {
    int n, m, k, g, s, t;
    cin >> n >> m >> k >> g >> s >> t;
    vector<int> p(n), q(n);
    for (int i = 0; i < n; i++) {
    	cin >> p[i] >> q[i];
    }
    vector<int> a(m), b(m), l(m), r(m), c(m), h(m), d(m);
    
    vector<vector<pair<int, int>>> AL(n);
    for (int i = 0; i < m; i++) {
    	cin >> a[i] >> b[i] >> l[i] >> r[i] >> c[i] >> h[i] >> d[i];
    	a[i]--, b[i]--;
    	AL[a[i]].pb({b[i], i});
    }
    
    ll ans = INF;
	priority_queue<State, vector<State>, greater<State>> pq;
	pq.push({0, s, 0, s, s});
	fill_n(&dist[0][0][0][0], 1001*12*12*12, INF);
	dist[0][s][s][s] = 0;
	
	while (!pq.empty()) {
		State u = pq.top();
		pq.pop();
		
		// dbg(u.u, u.h, u.d);
		
		if (dist[u.u][u.h][u.U][u.V] < u.d) continue;
		
		for (auto & [v, ei] : AL[u.u]) {
			if (u.h >= l[ei] and u.h <= r[ei]) {
				ll w = c[ei] + d[ei] * (ll)abs((int)u.h - (int)h[ei]);
				
				if (u.d + w >= dist[v][u.h][u.U][u.V]) continue;
				
				dist[v][u.h][u.U][u.V] = u.d + w;
				pq.push({v, u.h, dist[v][u.h][u.U][u.V], u.U, u.V});
			}
		}
		
		if (u.h < k) {
			ll nh = u.h+1;
			ll change = (nh > u.V);
			ll w = p[u.u] + g * change;
			
			if (u.d + w < dist[u.u][nh][u.U][u.V+change]) {
				dist[u.u][nh][u.U][u.V+change] = u.d + w;
				pq.push({u.u, nh, dist[u.u][nh][u.U][u.V+change], u.U, u.V+change});
			}
		}
		
		if (u.h > 0) {
			ll nh = u.h-1;
			ll change = (nh < u.U);
			ll w = q[u.u] + g * change;
			
			
			if (u.d + w < dist[u.u][nh][u.U-change][u.V]) {
				dist[u.u][nh][u.U-change][u.V] = u.d + w;
				pq.push({u.u, nh, dist[u.u][nh][u.U-change][u.V], u.U-change, u.V});
			}
		}
	}
	
	for (int U = 0; U <= k; U++) {
		for (int V = U; V <= k; V++) {
			ans = min(ans, dist[n-1][t][U][V]);
		}
	}
    
    
    if (ans == INF) cout << "NA" << ln;
    else cout << ans << ln;
    
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
