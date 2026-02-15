// Problem: 10308 - Roads in the North
// Contest: UVa Online Judge
// URL: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1249
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

const ll INF = LLONG_MAX / 4;
const ld PI = acos(-1);
const int MOD = 1000000007;
const double eps = 1e-9;

void process(string& s, int&u, int&v, int& w) {
	s += ' ';
	string cur;
	int r[3];
	int a = 0;
	for(char& c : s) {
		if (c == ' ') {
			if (!cur.empty()) {
				r[a++] = stoll(cur);
				cur.clear();	
			}
		}
		else cur += c;
	}
	
	u = r[0] - 1;
	v = r[1] - 1;
	w = r[2];
}

int getRes(vector<vector<int>>& e) {
	int n = (int)e.size() + 1;
	vector<vector<pair<int, int>>> AL(n);
	for (vector<int>& x : e) {
		AL[x[0]].pb({x[1], x[2]});
		AL[x[1]].pb({x[0], x[2]});
	}
	
	int ans = 0;
	
	for (int i = 0; i < n; i++) {
		if ((int)AL[i].size() != 1) continue;
		
		// run bfs
		vector<int> dist(n, INF);
		dist[i] = 0;
		queue<int> q;
		q.push(i);
		
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			
			for (pair<int, int>& x : AL[u]) {
				if (dist[x.first] != INF) continue;
				
				dist[x.first] = dist[u] + x.second;
				ans = max(ans, dist[x.first]);
				q.push(x.first);
			}
		}
	}
	
	return ans;
}

void solve() {
    int u, v, w;
    vector<vector<int>> entry;
    string s;
    while (getline(cin, s)) {
    	if (s.empty()) {
    		if (!entry.empty()) cout << getRes(entry) << ln;
    		entry.clear();
    		continue;
    	}
    	
    	process(s, u, v, w);
    	
    	entry.pb({u, v, w});
    }
    
    if (!entry.empty()) cout << getRes(entry) << ln;
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
