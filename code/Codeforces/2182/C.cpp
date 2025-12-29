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

int alignments(vector<int> a, vector<int> b, int n) {
	int ans = 0;
	for (int i = 0; i < n; i++) {
		// for all possible starting points
		bool poss = true;
		for (int j = 0; j < n; j++) {
			if (a[(i + j) % n] >= b[j]) {
				poss = false;
				break;
			}
		}
		
		if (poss) ans++;
	}
	
	return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for (auto& i : a) cin >> i;
    for (auto& i : b) cin >> i;
    for (auto& i : c) cin >> i;
    
    int align2 = alignments(b, c, n);
    int align1 = alignments(a, b, n);
    
    // dbg(align1, align2);
    
    int ans = align1 * n * align2;
    
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
