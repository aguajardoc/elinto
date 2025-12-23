// Problem: 571 - Jugs
// Contest: UVa Online Judge
// URL: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=512
// Memory Limit: 32 MB
// Time Limit: 3000 ms
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
#define INF 2e18
#define PI 3.14159265358979323846
#define MOD 1000000007

double eps = 1e-9;

void process(int a, int b, int ua, int ub, vector<vector<int>>& dist, map<pair<int, int>, pair<pair<int, int>, string>>& p, queue<pair<int, int>>& q, string type) {
	if (dist[a][b] == 1e9) {
		dist[a][b] = dist[ua][ub] + 1;
		q.push({a, b});
		p[{a, b}] = {{ua, ub}, type};
	}
}

void solve() {
    int a, b, n;
    while (cin >> a) {
    	cin >> b >> n;
    	
    	// we start at 0 in both
		vector<vector<int>> dist(a + 1, vector<int> (b + 1, 1e9));
    	map<pair<int, int>, pair<pair<int, int>, string>> p;
    	queue<pair<int, int>> q;
    	q.push({0, 0});
    	dist[0][0] = 0;
    	p[{0, 0}] = {{-1, -1}, "NA"};
    	
    	// possible moves
    	// +a to a, +b to b
    	// +second to a, +first to b
    	// a = 0, b = 0;
    	while (!q.empty()) {
    		pair<int, int> u = q.front();
    		q.pop();
    		int ua = u.first;
    		int ub = u.second;
    		
    		// fill a
    		if (ua == 0) {
    			process(a, ub, ua, ub, dist, p, q, "fill A");
    		}
    		// fill b
    		if (ub == 0) {
    			process(ua, b, ua, ub, dist, p, q, "fill B");
    		}
    		// pour b to a
    		if (ua + ub <= a) {
    			process(ua + ub, 0, ua, ub, dist, p, q, "pour B A");				
    		}
    		// pour b to a
    		if (ua + ub > a) {
				process(a, ub - (a - ua), ua, ub, dist, p, q, "pour B A");
    		}
    		// pour a to b
    		if (ua + ub <= b) {
    			process(0, ua + ub, ua, ub, dist, p, q, "pour A B");				
    		}
    		// pour a to b
    		if (ua + ub > b) {
    			process(ua - (b - ub), b, ua, ub, dist, p, q, "pour A B");
    		}
    		// empty a
    		process(0, ub, ua, ub, dist, p, q, "empty A");
    		// empty b
    		process(ua, 0, ua, ub, dist, p, q, "empty B");
    	}
    	
    	pair<int, int> state;
    	for (int i = 0; i <= a; i++) {
    		for (int j = 0; j <= b; j++) {
    			if (i == n or j == n){
    				if (dist[i][j] != 1e9) {
    					state = {i, j};
    				}
    			}
    			// if (dist[i][j] != 1e9) {
    				// cout << "reached: " << i << ", " << j << ln;
    			// }
    		}
    	}
    	
    	vector<string> ans = {"success"};
    	pair<pair<int, int>, string> cur = p[state];
    	while (cur.first.first != -1) {
    		ans.push_back(cur.second);
    		cur = p[cur.first];
    	}
    	reverse(ans.begin(), ans.end());
    	
    	for (auto& i : ans) {
    		cout << i << ln;
    	}
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
