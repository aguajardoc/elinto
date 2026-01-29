// Problem: C. Cycles
// Contest: Codeforces - Codeforces Round 144 (Div. 2)
// URL: https://codeforces.com/contest/233/problem/C
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

void solve() {
	int X;
	cin >> X;
	
	int N = 1;
	vector<vector<int>> AM(N, vector<int> (N, 0));
	
	int cur = 0;
	while (cur < X) {
		bool stuck = true;
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				if (AM[i][j]) continue;
				int loc = 0;
				for (int k = 0; k < N; k++) {
					if (i == k or j == k) continue;
					if (AM[i][k] and AM[j][k]) {
						loc++;
					}
				}
				
				if (cur + loc <= X) {
					cur += loc;
					AM[i][j] = 1;
					AM[j][i] = 1;
					stuck = false;
				}
			}
		}
		
		if (stuck) {
			N++;
			for (auto& i : AM) i.pb(0);
			AM.pb(vector<int> (N, 0));
		}
	}
	
	// dbg(cur);
	cout << N << ln;
	for (auto& i : AM) {
		for (auto& j : i) {
			cout << j;
		}
		cout << ln;
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
