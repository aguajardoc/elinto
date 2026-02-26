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
    int n, m;
    cin >> n >> m;
    vector<int> passed(n + m + 1, 0);
    
    vector<int> a(n);
    for (auto& i : a) cin >> i;
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());
    
    for (auto& i : a) {
    	for (int j = i; j <= n + m; j+= i) {
    		passed[j]++;
    	}
    }
    
    int ALICE = 0;
    int BOB = 0;
    int AB = 0;
    vector<int> b(m), c(m);
    int k = a.size();
    for (auto& i : b) {
    	cin >> i;
    	if (passed[i] and passed[i] != k) {
    		AB++;
    	}
    	else if (passed[i] == k) {
    		ALICE++;
    	}
    	else BOB++;
    }
    // dbg(ALICE, BOB, AB);
    
    int turn = 0;
    while (AB) {
    	turn = 1 - turn;
    	AB--;
    }
    
    while (ALICE and BOB) {
    	if (!turn) ALICE--;
    	else BOB--;
    	
    	turn = 1 - turn;
    }
    
    if (!turn) {
    	if (ALICE) cout << "Alice" << ln;
    	else cout << "Bob" << ln;
    }
    else {
    	if (BOB) cout << "Bob" << ln;
    	else cout << "Alice" << ln;
    }
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
