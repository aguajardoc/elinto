// Problem: F. Binary Bubble Sort Inversions
// Contest: Codeforces - Codeforces Round 1119 (Div. 3)
// URL: https://codeforces.com/contest/2259/problem/F
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i : a) cin >> i;
    string s; cin >> s;
    
    vector<int> inv0;
    map<int, int> offsetMap;
    int ones = 0;
    int inv = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) ones++;
        else {
            if (ones) {
                inv += ones;
                inv0.pb(ones);
                offsetMap[ones]++;
            }
        }
    }
    
    cout << inv << " ";
    int active = inv0.size();
    int offset = 0;
    for (int i = 0; i < n; i++) {
        // dbg(active);
        if (s[i] == '0') {
            if (!inv0.empty() and inv0.back() > offset) {
                offsetMap[inv0.back()]--;
                inv -= inv0.back() - offset;
                inv0.pop_back();
                active--;
            }
        }
        else {
            inv -= active;
            offset++;
            active -= offsetMap[offset];
            offsetMap[offset] = 0;
        }
        cout << inv << " ";
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
