// Problem: D. Bermuda Rectangle
// Contest: Codeforces - Codeforces Round 1117 (Div. 2)
// URL: https://codeforces.com/contest/2257/problem/D
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

int S, q;
vector<int> d, rec, recrev, psum;

int brute(int x, int y) {
    int ans = 0;
    int n = d.size();
    int prev = 0;
    for (int i = 0; i < n; i++) {
        if (prev > x) break;
        
        int z1 = min(y, rec[i]);
        int z2 = (min(d[i], x) - prev);
        
        ans += z1 * z2;
                
        // dbg(z1, z2, ans);
                
        prev = d[i];
    }
    
    return ans;
}

int optim(int x, int y) {
    int thy = upper_bound(recrev.begin(), recrev.end(), y) - recrev.begin();
    int thx = upper_bound(d.begin(),d.end(), x) - d.begin();
    int ans = 0;
    int n = d.size();
    int last = min(n - 1, thx);
    int prev = 0;
    
    thy = n - thy;
    
    // dbg(thy, thx);
    
    for (int i = 0; i <= last; i++) {
        // dbg(i, prev, x);
        if (prev > x) break;
        int z1, z2;
        if (i < thy) z1 = y;
        else z1 = rec[i];
        
        if (i < thx) z2 = d[i] - prev;
        else z2 = x - prev;
        
        ans += z1 * z2;
        
        // dbg(z1, z2, ans);
        
        prev = d[i];
    }
    
    return ans;
}

vector<int> recd;

void init() {
    int n = d.size();
    recd.assign(n + 1, 0);
    int prev = 0;
    for (int i = 0; i < n; i++) {
        recd[i+1] = recd[i] + rec[i] * (d[i] - prev);
        prev = d[i];
    }
}

int optim2(int x, int y) {
    int thy = upper_bound(recrev.begin(), recrev.end(), y) - recrev.begin();
    int thx = upper_bound(d.begin(),d.end(), x) - d.begin();
    int ans = 0;
    int n = d.size();
    int last = min(n - 1, thx);
    int prev = 0;
    
    thy = n - thy;
    
    if (thy <= thx) {
        // 0 to thy - 1
        int z11 = y;
        int z21 = psum[thy] - psum[0];
        
        ans += z11 * z21;
        
        // dbg(ans);
        
        // thy to thx - 1
        int z12 = recd[thx] - recd[thy];
        
        ans += z12;
        
        // dbg(ans);
        
        // thx to last
        if (thx == last) {
            ans += rec[last] * (x - d[last - 1]);
        }
        
        // dbg(ans);
    }
    else {
        // 0 to thx - 1
        int z11 = y;
        int z21 = psum[thx] - psum[0];
        
        ans += z11 * z21;
        
        // dbg(ans);
        
        // thx to last
        if (thx == last) {
            ans += y * (x - d[last - 1]);
        }
        
        // dbg(ans);
    }
    
    return ans;
}

void solve() {
    cin >> S >> q;
    d.clear();
    rec.clear();
    recrev.clear();
    for (int i = 1; i * i <= S; i++) {
        if (S % i == 0) {
            d.pb(i);
            rec.pb(S/i);
        }
    }
    
    vector<int> dtemp = d;
    vector<int> rtemp = rec;
    
    reverse(rtemp.begin(), rtemp.end());
    reverse(dtemp.begin(), dtemp.end());
    
    rec.insert(rec.end(), dtemp.begin(), dtemp.end());
    d.insert(d.end(), rtemp.begin(), rtemp.end());
    
    recrev = rec;
    reverse(recrev.begin(), recrev.end());
    
    psum.assign(d.size() + 1, 0);
    int prev = 0;
    int n = d.size();
    for (int i = 0; i < n; i++) {
        psum[i+1] = (d[i] - prev) + psum[i];
        
        prev = d[i];
    }
    
    init();
    
    // for (auto& i : d) {
        // cout << i << " ";
    // }
    // cout << ln;
    // for (auto& i : rec) {
        // cout << i << " ";
    // }
    // cout << ln;
    
    while (q--) {
        int x, y; cin >> x >> y;
        
        // cout << "\nBRUTE:\n";
        // int bans = brute(x, y);
        // cout << "\nFAST1:\n";
        // int oans = optim(x, y);
        int fans = optim2(x, y);
        
        // cout << bans << " " << oans << " " << fans << ln;
        // assert(bans == oans and bans == fans);
        
        cout << fans << ln;
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
