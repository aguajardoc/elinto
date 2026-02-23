// Problem: B. Buggy Blinkers
// Contest: Codeforces - 2024 Benelux Algorithm Programming Contest (BAPC 24)
// URL: https://codeforces.com/gym/105492/problem/B
// Memory Limit: 1024 MB
// Time Limit: 4000 ms
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

struct Node {
	int v[4];
};

int turnDir[4][4] = {{0, 2, -1, 1},
                     {1, 0, 2, -1},
                     {-1, 1, 0, 2},
                     {2, -1, 1, 0}};

int opp(int x) {
	return (x + 2) % 4;
}

void solve() {
    int n, k;
    cin >> n >> k;
    
    vector<Node> AL(n);
    
    for (int i = 0; i < n; i++) {
    	int n, e, s, w;
    	cin >> n >> e >> s >> w;
    	AL[i].v[0] = n - 1;
    	AL[i].v[1] = e - 1;
    	AL[i].v[2] = s - 1;
    	AL[i].v[3] = w - 1;
    }
    
    // v, k, dir, turnang
    static int dist[5001][21][5][3];
	fill_n(&dist[0][0][0][0], 5001*21*5*3, INF);
	
	dist[0][0][0][0] = 0;
	dist[0][0][1][0] = 0;
	dist[0][0][2][0] = 0;
	dist[0][0][3][0] = 0;
	queue<vector<int>> q;
	q.push({0, 0, 0, 0});
	q.push({0, 0, 1, 0});
	q.push({0, 0, 2, 0});
	q.push({0, 0, 3, 0});
	
	while (!q.empty()) {
		int u = q.front()[0];
		int b = q.front()[1];
		int d = q.front()[2];
		int turn = q.front()[3];
		
		q.pop();
		
		// dbg(u, b, d, turn);
		
		// Currently going in direction d, changing to i
		// Currently turning to turn, new turn at nt
		for (int i = 0; i < 4; i++) {
			int v = AL[u].v[i];
			if (v < 0) continue;
			if (v == u) continue;
			
			// if (d == opp(i) or nt == -1) continue;
			int arrival = 0;
			for (int j = 0; j < 4; j++) {
				if (AL[v].v[j] == u) arrival = opp(j);
			}
			
			int nk = b;
			int nt = turnDir[d][i];
			if (turn != nt and nt) nk++;
			if (nk > k) continue;
			if (nt == -1) continue;
			if (dist[v][nk][arrival][nt] != INF) continue;
			
			// dbg(u,b,d,turn);
			// dbg(v, nk, arrival, nt);
			// cout << flush;
			
			dist[v][nk][arrival][nt] = dist[u][b][d][turn] + 1;
			q.push({v, nk, arrival, nt});
		}
	}
	
	int ans = INF;
	for (int kk = 0; kk <= k; kk++) {
		for (int dd = 0; dd < 4; dd++) {
			for (int tt = 0; tt < 3; tt++) {
				ans = min(ans, dist[n - 1][kk][dd][tt]);
			}
		}
	}
	
	if (ans == INF) cout << "impossible\n";
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
