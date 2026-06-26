// Problem: Problem 3. Milk Pails
// Contest: USACO - USACO 2016 February Contest, Silver
// URL: https://usaco.org/index.php?page=viewproblem2&cpid=620
// Memory Limit: 256 MB
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
    freopen("pails.in", "r", stdin); \
    freopen("pails.out", "w", stdout)
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

struct State {
	int x, y, moves;

	bool operator<(const State& oth) const {
		if (x != oth.x) return x < oth.x;
		if (y != oth.y) return y < oth.y;
		return moves < oth.moves;
	}
};

signed main() {
    fast_cin();
    iofiles();
	int x, y, k, m;
	cin >> x >> y >> k >> m;
	
	int ans = m;
	
	queue<State> q;
	set<State> visited;
	q.push({0, 0, 0});
	visited.insert({0, 0, 0});
	
	while (!q.empty()) {
		State u = q.front();
		// cout << u.x << " " << u.y << " " << u.moves << endl;
		q.pop();
		if (u.moves > k) continue;
		ans = min({
			ans,
			abs((u.x + u.y) - m)
		});
		
		// Fill x to top
		if (visited.insert({x, u.y, u.moves+1}).second)
		q.push({x, u.y, u.moves+1});
		// Fill y to top
		if (visited.insert({u.x, y, u.moves+1}).second)
		q.push({u.x, y, u.moves+1});
		// Empty x
		if (visited.insert({0, u.y, u.moves+1}).second)
		q.push({0, u.y, u.moves+1});
		// Empty y
		if (visited.insert({u.x, 0, u.moves+1}).second)
		q.push({u.x, 0, u.moves+1});
		// Pour x to y
		if (u.x + u.y <= y) {
			if (visited.insert({0, u.y + u.x, u.moves+1}).second)
			q.push({0, u.y + u.x, u.moves+1});
		}
		else {
			// cout << u.x << " " << y - u.y << endl;
			if (visited.insert({u.x - (y - u.y), y, u.moves+1}).second)
			q.push({u.x - (y - u.y), y, u.moves+1});
		}
		// Pour y to x
		if (u.x + u.y <= x) {
			if (visited.insert({u.x + u.y, 0, u.moves+1}).second)
			q.push({u.y + u.x, 0, u.moves+1});
		}
		else {
			if (visited.insert({x, u.y - (x - u.x), u.moves+1}).second)
			q.push({x, u.y - (x - u.x), u.moves+1});
		}
	}
	
	cout << ans << endl;
}
