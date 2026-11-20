// Problem: Swap Game
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1670
// Memory Limit: 512 MB
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
// #define int ll
#define ld long double
#define pb push_back

const ll INF = LLONG_MAX / 4;
const ld PI = acos(-1);
const int MOD = 1000000007;
const double eps = 1e-9;

int p10[10] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};

int at(int i, int j) {
	return i * 3 + j;
}

int sx1[12] = {0,0,0,0,0,1,1,1,1,1,2,2};
int sy1[12] = {0,0,1,1,2,0,0,1,1,2,0,1};

int sx2[12] = {0,1,0,1,1,1,2,2,1,2,2,2};
int sy2[12] = {1,0,2,1,2,1,0,1,2,2,1,2};

unordered_map<int, int> dist;

void swap(int& v, int i, int j, int x, int y) {
	int d1 = at(i, j), d2 = at(x, y);
	int p1 = p10[d1];
	int p2 = p10[d2];
	int w1 = (v / p1) % 10;
	int w2 = (v / p2) % 10;
	v -= w1 * p1;
	v += w1 * p2;
	
	v -= w2 * p2;
	v += w2 * p1;
}

void solve() {
    int start = 0, solved = 0;
    for (int i = 0; i < 3; i++) {
    	for (int j = 0; j < 3; j++) {
    		int c; cin >> c;
    		start *= 10;
    		start += c;
    		
    		solved *= 10;
    		solved += (3*i + j + 1);
    	}
    }
    
    dist.reserve(9*8*7*6*5*4*3*2+1);
    queue<int> q;
    q.push(start);
    
    dist[start] = 0;
    int times = 0;
    while (!q.empty()) {
    	if (dist.count(solved)) {
    		cout << dist[solved] << ln;
    		return;
    	}
    	int u = q.front();
    	q.pop();
    	
    	for (int i = 0; i < 12; i++) {
    		int v = u;
    		swap(v, sx1[i], sy1[i], sx2[i], sy2[i]);
    		if (dist.count(v)) continue;
    		dist[v] = dist[u] + 1;
    		q.push(v);
    	}
    }
    
    cout << dist[solved] << ln;
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
