// Problem: 1029. Ministry
// Contest: Timus Online Judge
// URL: https://acm.timus.ru/problem.aspx?space=1&num=1029
// Memory Limit: 64 MB
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

int dp[101][501][3], n, m, cost[101][501];
tuple<int, int, int> moves[101][501][3];


int recurse(int floor, int room, int dir) {
	if (floor == m) return 0;
	if (room < 0 or room >= n) return INF;
	
	if (dp[floor][room][dir] != -1) return dp[floor][room][dir];
	
	int resD = recurse(floor + 1, room, 0);
	int resL = INF;
	if (dir != 2) resL = recurse(floor, room - 1, 1);
	int resR = INF;
	if (dir != 1) resR = recurse(floor, room + 1, 2);
	int base = cost[floor][room];
	
	if (resD <= resL and resD <= resR) {
		moves[floor][room][dir] = {floor + 1, room, 0};
		return dp[floor][room][dir] = resD + base;
	}
	
	if (resL < resD and resL < resR) {
		moves[floor][room][dir] = {floor, room - 1, 1};
		return dp[floor][room][dir] = resL + base;
	}
	
	moves[floor][room][dir] = {floor, room + 1, 2};
	return dp[floor][room][dir] = resR + base;
}

void solve() {
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
    	for (int j = 0; j < n; j++) {
    		cin >> cost[i][j];
    	}
    }
    
    fill_n(&dp[0][0][0], 101*501*3, -1);
    int ans = INF;
    int bestStart = 0;
    for (int i = 0; i < n; i++) {
    	int x = recurse(0, i, 0);
    	if (x < ans) {
    		ans = x;
    		bestStart = i;
    	}
    }
    
    // cout << ans << ln;
    int floor = 0, room = bestStart, dir = 0;
    while (floor != m) {
    	cout << room + 1 << " ";
    	int nf = get<0>(moves[floor][room][dir]);
    	int nr = get<1>(moves[floor][room][dir]);
    	int nd = get<2>(moves[floor][room][dir]);
    	
    	floor = nf, room = nr, dir = nd;
    }
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
