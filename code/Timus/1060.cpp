// Problem: 1060. Flip Game
// Contest: Timus Online Judge
// URL: https://acm.timus.ru/problem.aspx?space=1&num=1060
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
// #define int ll
#define ld long double
#define pb push_back

const unsigned short INF = UINT16_MAX;
const ld PI = acos(-1);
const int MOD = 1000000007;
const double eps = 1e-9;

void solve() {
	unsigned short start = 0;
	unsigned short end_b = 0, end_w = (1ll << 16) - 1;
	for (unsigned short i = 0; i < 4; i++) {
		string s; cin >> s;
		for (unsigned short j = 0; j < 4; j++) {
			unsigned short bit = 4*i + j;
			
			if (s[j] == 'b') start |= (1ll << bit);
		}
	}
	
	unsigned short dist[1 << 16];
	fill_n(&dist[0], 1 << 16, INF);
	dist[start] = 0;
	
	queue<unsigned short> q; q.push(start);
	vector<pair<unsigned short, unsigned short>> dir = 
		{{0, 0}, {-1, 0}, {1, 0}, {0, -1}, {0, 1}};
	
	while (!q.empty()) {
		unsigned short u = q.front();
		
		q.pop();
		
		for (unsigned short i = 0; i < 4; i++) {
			for (unsigned short j = 0; j < 4; j++) {
				unsigned short v = u;
				
				for (auto& [dx, dy] : dir) {
					unsigned short nx = i + dx;
					unsigned short ny = j + dy;
					if (nx < 0 or nx >= 4 or ny < 0 or ny >= 4) continue;
					unsigned short bit = 4*nx + ny;
					v ^= (1ll << bit);
				}
				
				
				// dbg(dist.count(v));
				// dbg(dist[v]);
				// dbg(dist.count(start));
				if (dist[v] == INF) {
					dist[v] = dist[u] + 1;
					q.push(v);
				}
			}
		}
	}
	
	unsigned short ans = min(dist[end_w], dist[end_b]);
	cout << (ans == INF ? "Impossible":to_string(ans)) << ln;
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
