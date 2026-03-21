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

int query(int i, int j) {
	int r;
	cout << "? " << i << " " << j << endl;
	cin>> r;
	return r;
}

void ans(int k) {
	cout << "! " << k << endl;
}

void solve() {
    int n;
    cin >> n;
    
    for (int i = 3; i < 2*n; i+=2) {
    	int r = query(i, i + 1);
    	if (r) {
    		ans(i);
    		return;
    	}
    }
    
    int finq = query(1, 3);
    int finq2 = query(1, 4);
    
    if (finq or finq2) {
    	ans(1);
    }
    else ans(2);
}

signed main() {
    // fast_cin();
    
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
