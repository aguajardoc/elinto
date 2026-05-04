// Problem: B - Painting a Wall with Tape
// Contest: AtCoder - AtCoder Weekday Contest 0054 Beta
// URL: https://atcoder.jp/contests/awc0054/tasks/awc0054_b
// Memory Limit: 1024 MB
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

const ll INF = LLONG_MAX / 4;
const ld PI = acos(-1);
const int MOD = 1000000007;
const double eps = 1e-9;

void solve() {
    int n, w;
    cin >> n >> w;
    
    vector<pair<int, int>> tape(n);
    for (int i = 0; i < n; i++) {
    	cin >> tape[i].first >> tape[i].second;
    	tape[i].second += tape[i].first - 1;
    }
    
    sort(tape.begin(), tape.end());
    int res = 0;
    int last = 0;
    for (int i = 0; i < n; i++) {
    	tape[i].first = max(tape[i].first, last);
    	int added = tape[i].second - tape[i].first + 1;
    	if (added>0) res += added;
    	last = max(last, tape[i].second + 1);
    }
    
    cout << res << ln;
    
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
