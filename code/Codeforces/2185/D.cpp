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
    int n, m, h;
    cin >> n >> m >> h;
    vector<int> a(n);
    for (auto& i : a) cin >> i;
    vector<int> b = a;
    vector<int> resets(n, 0);
    int lr = 0;
    
    for (int i = 1; i <= m; i++) {
    	int x, y;
    	cin >> x >> y;
    	x--;
    	if (resets[x] < lr) {
    		b[x] = a[x];
    		resets[x] = lr;
    	}
    	b[x] += y;
    	if (b[x] > h) {
    		lr = i;
    		resets[x] = i;
    		b[x] = a[x];
    	}
    }
    
    for (int i = 0; i < n; i++) {
    	if (lr > resets[i]) {
    		cout << a[i] << " ";
    	}
    	else cout << b[i] << " ";
    }
    cout << ln;
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
