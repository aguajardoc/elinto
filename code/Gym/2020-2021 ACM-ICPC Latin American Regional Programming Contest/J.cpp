// Problem: J. Job Allocator
// Contest: Codeforces - 2020-2021 ACM-ICPC Latin American Regional Programming Contest
// URL: https://codeforces.com/gym/103185/problem/J
// Memory Limit: 1024 MB
// Time Limit: 1500 ms
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
const int N = 8;

struct Node {
    int next[N+1], val;
    Node() {
        val = 0;
        for (auto& i : next) i = -1;
    }
};

struct FTREE {
    vector<Node> st;
    int n;
    
    FTREE() {
        st.pb(Node());
    }
    
    void extend(int p, int running_tot) {
        for (int i = 0; i <= N; i++) {
            if (i + running_tot > N) break;
            if (st[p].next[i] == -1) {
                st[p].next[i] = st.size();
                st.pb(Node());
            }
        }
    }
    
    void update(int p, int depth, vector<int>& valid, int v, int run) {
        if (depth == N) {
            st[p].val += v;
            return;
        }
        extend(p, run);
        // just follow the path of valid
        
        update(st[p].next[valid[depth]], depth + 1, valid, v, run + valid[depth]);
    }
    
    
    int query(int p, int depth, vector<int>& valid, int leeway, int run) {
        if (depth == N) {
            return st[p].val;
        }
        extend(p, run);
        
        int res = 0;
        for (int i = valid[depth]; i <= valid[depth] + leeway; i++) {
            if (st[p].next[i] == -1) break;
            
            res += query(st[p].next[i], depth + 1, valid, leeway - (i - valid[depth]), run + i);
        }
        
        return res;
    }
    
    void update(vector<int>& valid, int v) {
        update(0, 0, valid, v, 0);
    }
    
    int query(vector<int>& valid) {
        int leeway = N;
        for (auto& i : valid) leeway -= i;
        
        return query(0, 0, valid, leeway, 0);
    }
};

void solve() {
    int n, k;
    cin >> n >> k;
    
    vector<vector<int>> machines;
    FTREE st;
    
    while(n--) {
        char type; int k;
        cin >> type >> k;
        
        if (type == 'D') {
            st.update(machines[k-1], -1);
            continue;
        }
        
        vector<int> valid(N, 0);
        for (int i = 0; i < k; i++) {
            int x;
            cin >> x;
            valid[x-1]++;
        }
        
        if (type == 'C') {
            machines.pb(valid);
            st.update(valid, 1);
        }
        else {
            cout << st.query(valid) << ln;
        }
        
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
