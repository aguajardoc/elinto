// Problem: D. Infinite August
// Contest: Codeforces - 2026-2027 ICPC NERC, Kyrgyzstan Regional Contest
// URL: https://codeforces.com/gym/106802/problem/D
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

vector<int> dmap = {0,31,28,31,30,31,30,31,31,30,31,30,31};

int is_leap(int y) {
	return (y % 400 == 0 or (y % 4 == 0 and y % 100 != 0));
}

int days_in(int month, int year) {
	return dmap[month] + (month == 2) * is_leap(year);
}

void solve() {
	int m1,y1,d2,m2,y2; cin >> m1 >> y1 >> d2 >> m2 >> y2;
	
	int days = 1, d1 = 1;
	for (;!(d1 == d2 and m1 == m2 and y1 == y2); days++) {
		d1++;
		if (d1 > days_in(m1, y1)) {
			d1 = 1;
			m1++;
		}
		if (m1 == 13) {
			m1 = 1;
			y1++;
		}
		
		// dbg(d1, m1, y1);
	}
	
	// dbg(d1, m1, y1);
	// dbg(d2, m2, y2);
	
	cout << days << ln;
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
