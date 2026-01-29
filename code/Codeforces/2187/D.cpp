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

pair<int, int> getR(int x, int y) {
	int p = x;
	int q1 = y, q2 = y;
	// Case 1: first valid
	// First conflict;
	int clash = -1;
	for (int i = 33; i >= 0; i--) {
		if (q1 & (1ll  << i) and x & (1ll << i)) {
			clash = i;
			break;
		}
	}
	// First bit that can from 0
	for (int i = clash + 1; i < 33; i++) {
		if (!(q1 & (1ll << i)) and !(x & (1ll << i))) {
			q1 += (1ll << i);
			// kill all after
			for (int j = i - 1; j >= 0; j--) {
				if (q1 & (1ll << j)) {
					q1 -= (1ll << j);
				}
			}
			break;
		}
	}
	
	
	// Case 2: last valid
	// kill all bits that cant
	for (int i = 0; i < 33; i++) {
		if (q2 & (1ll << i) and x & (1ll << i)) {
			q2 -= (1ll << i);
		}
	}
	// Recoup until cant
	for (int i = 0; i < 33; i++) {
		if (!(q2 & (1ll << i)) and !(x & (1ll << i))) {
			if (q2 + (1ll << i) <= y) q2 += (1ll << i);
		}
	}
	
	int q;
	// dbg(q1, q2);
	if (abs(y - q1) < abs(y - q2)) q = q1;
	else q = q2;
	
	// dbg(p, q);
	
	return {p, q};
}

void solve() {
    int x, y;
    cin >> x >> y;
    
    int p, q;
    
    pair<int, int> A1 = getR(x, y);
    pair<int, int> A2 = getR(y, x);
    int d1 = abs(A1.first - x) + abs(A1.second - y);
    int d2 = abs(A2.second - x) + abs(A2.first - y);
    
    
    if (d1 < d2) {
    	p = A1.first;
    	q = A1.second;
    }
    else {
    	p = A2.second;
    	q = A2.first;
    }
    
    cout << p << " " << q << ln;
}

signed main() {
    fast_cin();
    
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
