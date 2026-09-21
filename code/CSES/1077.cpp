// Problem: Sliding Window Cost
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1077/
// Memory Limit: 512 MB
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

struct RollingMedian {
    multiset<int> L, R;
    int sol = 0, sor = 0;
    // R has all after half
 
    void fix() {
        int n = L.size() + R.size();
        if (n % 2) {
            if (R.size() > L.size()) {
                sol += *R.begin();
                sor -= *R.begin();
                L.insert(*R.begin());
                R.erase(R.find(*R.begin()));
            }
        }
        else {
            if (L.size() > R.size()) {
                sol -= *L.rbegin();
                sor += *L.rbegin();
                R.insert(*L.rbegin());
                L.erase(L.find(*L.rbegin()));
            }
        }
    }
 
    void add(int x) {
        if (L.empty() or x <= *L.rbegin()) {
            L.insert(x);
            sol += x;
        }
        else {
            R.insert(x);
            sor += x;
        } 
        
        fix();
    }
 
    void erase(int x) {
        if (L.count(x)) {
            L.erase(L.find(x));
            sol -= x;
        }
        else {
            R.erase(R.find(x));
            sor -= x;
        }
 
        fix();
    }

    int get() {
        return *L.rbegin();
    }
    
    int get_res() {
        int m = this->get();
        int LP = L.size() * m - sol;
        int RP = sor - m * R.size();
        int res = LP + RP;
        return res;
    }
};


void solve() {
    int n,k; cin >> n >> k;
    RollingMedian rm;
    vector<int> a(n); for (auto& i : a) cin >> i;
    
    for (int i = 0; i < k; i++) {
        rm.add(a[i]);
    }
 
    cout << rm.get_res() << " ";
 
    for (int i = k; i < n; i++) {
        rm.erase(a[i-k]);
        rm.add(a[i]);
        cout << rm.get_res() << " ";
    }
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
