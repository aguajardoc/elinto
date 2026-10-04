// Problem: A. Ladies Brunch
// Contest: Codeforces - CODEFEM - Mexican Womens Competitive Programming League
// URL: https://codeforces.com/gym/106718/problem/A
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

map<string, int> price, people;

struct Node {
    int val, lazy;
    Node() {
        val = 0, lazy = 0;
    }
};

struct Segtree {
    vector<Node> st;
    int n;
    
    Segtree(int _n) {
        n = _n;
        st.assign(4 * n, Node());
    }  
    
    void push(int p, int l, int r) {
        if (!st[p].lazy) return;
        
        int m = (l + r) / 2;
        st[2*p].val += (m - l + 1) * st[p].lazy;
        st[2*p+1].val += (r - m) * st[p].lazy;
        
        st[2*p].lazy += st[p].lazy;
        st[2*p+1].lazy += st[p].lazy;
        
        st[p].lazy = 0;
    }
    
    void update(int p, int l, int r, int i, int j, int v) {
        if (l > j or r < i) return;
        if (l >= i and r <= j) {
            st[p].val += (r - l + 1) * v;
            st[p].lazy += v;
            return;
        }
        
        push(p, l, r);
        
        int m = (l + r) / 2;
        
        update(2*p, l, m, i, j ,v);
        update(2*p+1, m + 1, r, i, j, v);
        
        st[p].val = st[2*p].val + st[2*p+1].val;
    }
    
    
    int query(int p, int l, int r, int i, int j) {
        if (l > j or r < i) return 0;
        if (l >= i and r <= j) {
            return st[p].val;
        }
        
        push(p, l, r);
        
        int m = (l + r) / 2;
        
        return(
            query(2*p, l, m, i, j) + 
            query(2*p + 1, m + 1, r, i, j)
        );
    }
    
    void update(int i, int j, int v) {
        update(1, 0, n-1, i, j, v);
    }
    
    int query(int i, int j) {
        return query(1, 0, n - 1, i , j);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        people[s] = i;
    }
    for (int i = 0; i < m; i++) {
        string s; int x; cin >> s >> x;
        price[s] = x;
    }
    
    Segtree st(n);
    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        int type; cin >> type;
        if (type == 1) {
            string person, prod;
            cin >> person >> prod;
            st.update(people[person], people[person], price[prod]);
        }
        else if (type == 2) {
            int l, r; cin >> l >> r;
            string prod;
            cin >> prod;
            
            if (l <= r) {
                st.update(l, r, price[prod]);
            }
            else {
                st.update(l, n - 1, price[prod]);
                st.update(0, r, price[prod]);
            }
        }
        else {
            string person; cin >> person;
            cout << st.query(people[person], people[person]) << ln;
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
