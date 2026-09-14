// Problem: D. Dr. Agos's Dark Mode
// Contest: Codeforces - Codeforces Round 1121 (Div. 2)
// URL: https://codeforces.com/contest/2264/problem/D
// Memory Limit: 256 MB
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

int ans = INF;
vector<int> b;

bool gm3(string s) {
    int a = 0;
    reverse(s.begin(), s.end());
    for (auto& i : s) {
        a *= 2;
        a += (i == '1');
        a %= 3;
    }
    
    
    return (!a);
}

void check(string& s) {
    int res = 0;
    for (int i = 0; i < s.length(); i++) {
        string cur;
        for (int j = i; j < s.length(); j++) {
            cur += s[j];
            if (gm3(cur)) res++;
        }
    }
    
    // dbg(s, res);
    
    if (res < ans) {
        ans = res;
        
        int consec = 1;
        vector<int> x;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i-1]) {
                consec++;
            }
            else {
                x.pb(consec);
                consec = 1;
            }
        }
        if (consec) x.pb(consec);
        
        b = x;
    }
}

void recurse(int idx, int n, int ct1, string& s) {
    if (ct1 == 4) return;
    if (idx == n) {
        check(s);
        return;
    }
    
    s += '0';
    recurse(idx + 1, n, ct1, s);
    s.pop_back();
    s += '1';
    recurse(idx + 1, n, ct1+1, s);
    s.pop_back();
}

void brute(int n) {
    string s;
    ans = INF;
    b.clear();
    recurse(0, n, 0, s);
    dbg(n);
    for (auto& i : b) {
        cout << i << ", ";
    }
    cout << ln;
}

void solve() {
    int n; cin >> n;
    // brute(n);
    
    if (n == 1) cout << "1" << ln;
    if (n == 2) cout << "01" << ln;
    if (n == 3) cout << "101" << ln;
    if (n == 4) cout << "0101" << ln;
    if (n == 5) cout << "01010" << ln;
    if (n == 6) cout << "001010" << ln;
    if (n == 7) cout << "0010100" << ln;
    if (n == 8) cout << "00101001" << ln;
    if (n == 9) cout << "000101001" << ln;
    if (n >= 10) {
        int m = n % 6;
        vector<int> pattern(6, 0);
        
        if (m == 4) {
            pattern[0] = n/3;
            pattern[1] = 1;
            pattern[2] = n/3;
            pattern[3] = 1;
            pattern[4] = n/3-1;
            pattern[5] = 0;
        }
        if (m == 5) {
            pattern[0] = n/3;
            pattern[1] = 1;
            pattern[2] = n/3;
            pattern[3] = 1;
            pattern[4] = n/3;
            pattern[5] = 0;
        }
        if (m == 0) {
            pattern[0] = n/3;
            pattern[1] = 1;
            pattern[2] = n/3-1;
            pattern[3] = 1;
            pattern[4] = n/3-1;
            pattern[5] = 0;
        }
        if (m == 1) {
            pattern[0] = n/3;
            pattern[1] = 1;
            pattern[2] = n/3-1;
            pattern[3] = 1;
            pattern[4] = n/3;
            pattern[5] = 0;
        }
        if (m == 2) {
            pattern[0] = n/3;
            pattern[1] = 1;
            pattern[2] = n/3-1;
            pattern[3] = 1;
            pattern[4] = n/3;
            pattern[5] = 1;
        }
        if (m == 3) {
            pattern[0] = n/3;
            pattern[1] = 1;
            pattern[2] = n/3-2;
            pattern[3] = 1;
            pattern[4] = n/3-1;
            pattern[5] = 1;
        }
        
        string s;
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < pattern[i]; j++) {
                s += '0' + (i % 2);
            }
        }
        
        // dbg(n==s.length());
        cout << s << ln;
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
