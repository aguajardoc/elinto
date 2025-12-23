// Problem: 10801 - Lift Hopping
// Contest: UVa Online Judge
// URL: https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1742
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

vector<int> process(string& s) {
	int i = 0;
	vector<int> floors;
	string cur;
	while ( i < s.length()) {
		if (s[i] == ' ') {
			if (cur.empty()) continue;
			
			floors.push_back(stoll(cur));
			cur.clear();
		}
		else cur += s[i];
		i++;
	}
	
	return floors;
}

struct Edge {
	int d, ele, floor;
	Edge(int d, pair<int, int> x) : d(d), ele(x.first), floor(x.second) {}
	bool operator<(const Edge& a) const {
		return (d >= a.d);
	}
};

void print(vector<vector<int>>& dist) {
	for (int i = 0; i < dist[0].size(); i++) {
		cout << "Floor: " << i << ln;
		for (int j = 0; j < dist.size(); j++) {
			cout << "Elevator: " << j << ", Dist: " << dist[j][i] << ln;
		}
		cout << ln;
	}
}

void solve() {
    int n;
    while(cin >> n) {
    	int floorTarget;
    	cin >> floorTarget;
    	map<int, vector<int>> floorEle;
    	vector<int> times(n);
    	for (int i = 0; i < n; i++) {
    		cin >> times[i];
    	}
    	cin.ignore();
    	
    	map<pair<int, int>, vector<pair<pair<int, int>, int>>> AL;
    	
    	for (int i = 0; i < n; i++) {
    		string s;
    		getline(cin, s);
    		s += ' ';
    		
    		vector<int> floors = process(s);
    		for (int j = 1; j < floors.size(); j++) {
    			int time = (floors[j] - floors[j - 1]) * times[i];
    			AL[{i, floors[j - 1]}].push_back({{i, floors[j]}, time});
    			AL[{i, floors[j]}].push_back({{i, floors[j - 1]}, time});   
    			
    			floorEle[floors[j]].push_back(i); 			
    		}
    		floorEle[floors[0]].push_back(i); 
    	}
    	
		for (pair<const int, vector<int>>& x : floorEle) {
			vector<int> k = x.second;
			int m = k.size();
			int floor = x.first;
			
			for (int j = 0; j < m; j++) {
				for (int l = 0; l < m; l++) {
					if (j == l) continue;
					AL[{k[j], floor}].push_back({{k[l], floor}, 60});
					AL[{k[l], floor}].push_back({{k[j], floor}, 60});					
				}
			}
		}
		
		// dijkstra!
		vector<vector<int>> dist(n, vector<int> (101, 1e15));
		priority_queue<Edge> pq;
		for (int& ele : floorEle[0]) {
			pq.push(Edge(0, {ele, 0}));
			dist[ele][0] = 0;
		}
		
		
		while (!pq.empty()) {
			Edge x = pq.top();
			int d = x.d;
			int e = x.ele;
			int f = x.floor;
			pq.pop();
			if (d > dist[e][f]) continue;
			
			for (pair<pair<int, int>, int>& y : AL[{e, f}]) {
				int ve = y.first.first;
				int vf = y.first.second;
				int w = y.second;
				if (d + w >= dist[ve][vf]) continue;
				
				dist[ve][vf] = d + w;
				pq.push(Edge(dist[ve][vf], {ve, vf}));
			}
		}
		
		// print(dist);
		
		ll res = 1e15;
		for (int& ele : floorEle[floorTarget]) {
			res = min(res, dist[ele][floorTarget]);
		}
		
		if (res == 1e15) cout << "IMPOSSIBLE" << ln;
		else cout << res << ln;
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
