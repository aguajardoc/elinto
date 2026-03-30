// Problem: H. Hathsin's piths
// Contest: Codeforces - 2025 ICPC Gran Premio de Mexico 2da Fecha
// URL: https://codeforces.com/gym/105979/problem/H
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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

struct Point {
	int x, y, z;
};
int n, h, k;

int getDist(Point A, Point B) {
	return ((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}

bool checkConn(int type1, int type2, int d) {
	if (type1 == 0 and type2 == 0) return false;
	else if (type1 == 0 and type2 == 1) return d <= k;
	else if (type1 == 1 and type2 == 0) return d <= h;
	else return (d <= max(h, k));
}

void solve() {
	cin >> n >> h >> k;
	h *= h;  
	k *= k;
	
	vector<Point> ledges(n);
	for (int i = 0; i < n ; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		ledges[i] = {x, y, z};
	}
	
	int a, b;
	cin >> a >> b;
	
	queue<int> q;
	vector<int> dist(n + 1, INF);
	for (int i = 0; i < n; i++) {
		if (ledges[i].x == a and ledges[i].y == b) {
			q.push(i);
			dist[i] = 0;
		}
	}
	
	int ans = INF;
	
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		Point U = ledges[u];
		if (U.y == 0) {
			ans = min(ans, dist[u]);
			continue;
		}
		
		if (U.z and U.y * U.y <= h) {
			ans = min(ans, dist[u] + 1);
		}
		
		for (int i = 0; i < n; i++) {
			if (dist[i] != INF or i == u) continue;
			
			int d = getDist(U, ledges[i]);
			int type1 = U.z;
			int type2 = ledges[i].z;
			bool connected = checkConn(type1, type2, d);
			
			if (connected) {
				q.push(i);
				dist[i] = dist[u] + 1;
			}
		}
	}
	
	cout << (ans == INF ? -1:ans) << ln;
	
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
