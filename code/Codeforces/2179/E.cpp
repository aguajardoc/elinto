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

void solve() {
    ll n, x, y;
    cin >> n >> x >> y;
    string s;
    cin >> s;
    bool Z = false, O = false;
    vector<int> p(n);
    vector<pair<int, int>> v(n);
    int compX = 0, compY = 0;
    int ogx = x, ogy = y;
	
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		int d = p[i] / 2 + 1;
		if (s[i] == '0') {
			Z = true;
			v[i].first += d;
			x-=d;
			compY += p[i] - d;
		}
		else {
			O = true;
			v[i].second += d;
			y-=d;
			compX += p[i] - d;
		}
		
	}
	
	// I can't even place the bare minimum
	if (x < 0 or y < 0) {
		cout << "NO" << ln;
		return;
	}
	
	// I can't use them to make up the difference
	if (x + y < compX + compY) {
		cout << "NO" << ln;
		return;
	}
	
	// I can make up the difference and put any wherever
	bool ans = true;
	if (Z and !O) {
		if (ogx < ogy + n) ans = false;
	}
	if (O and !Z) {
		if (ogy < ogx + n) ans = false;
	}

	cout << (ans ? "YES":"NO") << ln;
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