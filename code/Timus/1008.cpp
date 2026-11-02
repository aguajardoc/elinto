// Problem: 1008. Image Encoding
// Contest: Timus Online Judge - Third Open USTU Collegiate Programming Contest (PhysTech Cup), March 18, 2000
// URL: https://acm.timus.ru/problem.aspx?space=1&num=1008
// Memory Limit: 64 MB
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

const ll INF = LLONG_MAX / 4;
const ld PI = acos(-1);
const int MOD = 1000000007;
const double eps = 1e-9;

void q_to_loc(int x, int y) {
	queue<pair<int, int>> q;
	q.push({x, y});
	
	vector<pair<int, int>> ans = {{x, y}};
	set<pair<int, int>> visited = {{x, y}};
	while (!q.empty()) {
		string s; cin >> s;
		auto [x, y] = q.front();
		q.pop();
		
		for (auto& i : s) {
			int nx = x, ny = y;
			if (i == 'R') nx++;
			else if (i == 'T') ny++;
			else if (i == 'L') nx--;
			else if (i == 'B') ny--;
			else continue;
			
			if (!visited.insert({nx, ny}).second) continue;
			
			q.push({nx, ny});
			ans.pb({nx, ny});
		}
	}
	
	sort(ans.begin(), ans.end());
	cout << ans.size() << ln;
	for (auto& [x, y] : ans) {
		cout << x << " " << y << ln;
	}
}

void loc_to_q(int n) {
	set<pair<int, int>> black;
	vector<pair<int, int>> bv(n);
	for (int i = 0; i < n; i++) {
		cin >> bv[i].first >> bv[i].second;
		black.insert({bv[i].first, bv[i].second});
	}
	
	queue<pair<int, int>> q;
	q.push({bv[0].first, bv[0].second});
	black.erase({bv[0].first, bv[0].second});
	vector<string> ans;
	
	int idx = 0;
	string dirs = "RTLB";
	vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
	while (!q.empty()) {
		ans.pb("");
		auto [x, y] = q.front();
		q.pop();
		
		int j = 0;
		for (auto& [dx, dy] : dir) {
			int nx = x + dx;
			int ny = y + dy;
			
			if (!black.count({nx, ny})) {
				j++;
				continue;
			}
			
			black.erase({nx, ny});
			ans[idx] += dirs[j];
			q.push({nx, ny});
			
			j++;
		}
		
		ans[idx] += ',';
		idx++;
	}
	cout << bv[0].first << " " << bv[0].second << ln;
	ans.back() = '.';
	for (auto& i : ans) {
		cout << i << ln;
	}
}

void solve() {
    string S; getline(cin, S);
    if (S.find(' ') != string::npos) {
    	int x, y;
    	string cur;
    	int j = 0;
    	for (int i = 0; i < 2; i++) {
    		while (j < S.length() and S[j] != ' ') {
    			cur += S[j];
    			j++;
    		}
    		if (i == 0) {
    			x = stoi(cur);
    			cur.clear();
    			j++;
    		}
    		else y = stoi(cur);
    	}
    	
    	q_to_loc(x, y);
    }
    else {
    	int n = stoi(S);
    	loc_to_q(n);
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
