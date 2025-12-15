// Problem: B. Playing Cubes
// Contest: Codeforces - Codeforces Round 159 (Div. 2)
// URL: https://codeforces.com/contest/257/problem/B
// Memory Limit: 256 MB
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
#define INF 2e18
#define PI 3.14159265358979323846
#define MOD 1000000007

double eps = 1e-9;

pair<int, int> procedure(int n, int m, int start) {
	if (start) m--;
	else n--;
	
	ll P = 0, V = 0;
	int turn = 1;
	while (n or m) {
		if (turn) {
			turn = 1 - turn;
			if (start) {
				if (n) {
					start = 1 - start;
					V++;
					n--;
				}
				else {
					P++;
					m--;
				}
			}
			else {
				if (m) {
					start = 1 - start;
					V++;
					m--;
				}
				else {
					P++;
					n--;
				}
			}
		}
		else {
			turn = 1 - turn;
			if (start) {
				if (m) {
					P++;
					m--;
				}
				else {
					start = 1 - start;
					V++;
					n--;
				}
			}
			else {
				if (n) {
					P++;
					n--;
				}
				else {
					start = 1 - start;
					V++;
					m--;
				}
			}
		}
	}
	
	return make_pair(P, V);
}

void solve() {
    int n, m;
    cin >> n >> m;
    
    cout << max(procedure(n, m, 0), procedure(n, m, 1)).first << " " << max(procedure(n, m, 0), procedure(n, m, 1)).second << ln;
}

signed main() {
    fast_cin();
    
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
