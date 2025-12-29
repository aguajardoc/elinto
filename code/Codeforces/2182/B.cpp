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

int process(int a, int b) {
	int layer = 1;
	int turn = 0;
	int layers = 0;
	
	while (a or b) {
		if (!turn) {
			if (a - layer >= 0) {
				a -= layer;
				turn = 1;
				layer *= 2;
				layers++;
			}
			else return layers;
		}
		else {
			if (b - layer >= 0) {
				b -= layer;
				turn = 0;
				layer *= 2;
				layers++;
			}
			else return layers;
		}
	}
	
	return layers;
}

void solve() {
    int a, b;
    cin >> a >> b;
    int ans = 0;
    ans = max(process(a, b), process(b, a));
    
    cout << ans << ln;
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
