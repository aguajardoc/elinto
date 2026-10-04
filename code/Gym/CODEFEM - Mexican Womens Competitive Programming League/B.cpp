// Problem: B. Emily's Agenda
// Contest: Codeforces - CODEFEM - Mexican Womens Competitive Programming League
// URL: https://codeforces.com/gym/106718/problem/B
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

int get_time() {
    string s;
    cin >> s;
    string H = s.substr(0, 2);
    string M = s.substr(3, 2);
    
    int h = stoi(H), m = stoi(M);
    return h * 60 + m;
}

struct Range {
    int l, r;
    bool operator <(const auto& oth) const {
        return r < oth.r;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<Range> a(n);
    for (int i = 0; i < n; i++) {
        a[i].l = get_time();
        a[i].r = get_time();
        if (a[i].r <= a[i].l) a[i].r += 1440;
    }
    
    sort(a.begin(), a.end());
    int ans = 0;
    int time = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].l >= time) {
            time = a[i].r;
            ans++;
        }
    }
    
    cout << ans << ln;
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
