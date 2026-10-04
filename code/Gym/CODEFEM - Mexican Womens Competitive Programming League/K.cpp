// Problem: K. JajaScript
// Contest: Codeforces - CODEFEM - Mexican Womens Competitive Programming League
// URL: https://codeforces.com/gym/106718/problem/K
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
// #define int ll
#define ld long double
#define pb push_back

const ll INF = LLONG_MAX / 4;
const ld PI = acos(-1);
const int MOD = 1000000007;
const double eps = 1e-9;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define sz(x) (int)(x).size()
typedef vector<int> vi;

struct AhoCorasick {
    enum {alpha = 26, first = 'a'}; // change t h i s !
    struct Node {
        // (nmatches i s optional )
        int back, next[alpha], start = -1, end = -1, nmatches = 0;
        Node(int v) { memset(next, v, sizeof(next)); }
    };
    vector<Node> N;
    vi backp;
    vector<int> order;
    int insert(string& s, int j) {
        assert(!s.empty());
        int n = 0;
        for (char c : s) {
            int& m = N[n].next[c - first];
            if (m == -1) { n = m = sz(N); N.emplace_back(-1); }
            else n = m;
        }
        if (N[n].end == -1) N[n].start = j;
        backp.push_back(N[n].end);
        N[n].end = j;
        N[n].nmatches++;
        return n;
    }
    AhoCorasick() : N(1, -1) {}
    AhoCorasick(vector<string>& pat) : N(1, -1) {
        rep(i,0,sz(pat)) insert(pat[i], i);
        build();
    }
    vi find(string word) {
        int n = 0;
        vi res;  ll count = 0;
        for (char c : word) {
            n = N[n].next[c - first];
            res.push_back(N[n].end);
            count += N[n].nmatches;
        }
        return res;
    }
    vector<vi> findAll(vector<string>& pat, string word) {
        vi r = find(word);
        vector<vi> res(sz(word));
        rep(i,0,sz(word)) {
            int ind = r[i];
            while (ind != -1) {
                res[i - sz(pat[ind]) + 1].push_back(ind);
                ind = backp[ind];
            }
        }
        return res;
    }
    
    void build() {
        N[0].back = sz(N);
        N.emplace_back(0);
        queue<int> q;
        for (q.push(0); !q.empty(); q.pop()) {
            int n = q.front(), prev = N[n].back;
            order.pb(n);
            rep(i,0,alpha) {
                int &ed = N[n].next[i], y = N[prev].next[i];
                if (ed == -1) ed = y;
                else {
                    N[ed].back = y;
                    (N[ed].end == -1 ? N[ed].end : backp[N[ed].start])
                        = N[y].end;
                    N[ed].nmatches += N[y].nmatches;
                    q.push(ed);
                }
            }
        }
    }
};

struct Rule {
    int u, v, p;
};

void input(int n, AhoCorasick& aho, vector<Rule>& R, int offset) {
    for (int i = 0; i < n; i++) {
        string s1, s2; int p;
        cin >> s1 >> s2 >> p;
        R[i] = {
            aho.insert(s1, 2*i + offset),
            aho.insert(s2, 2*i+1 + offset),
            p
        };
    }
}

void solve() {
    string s; cin >> s;
    int n, m;
    
    AhoCorasick aho;
    
    cin >> n;
    vector<Rule> ada(n);
    input(n, aho, ada, 0);
    
    cin >> m;
    vector<Rule> grace(m);
    input(m, aho, grace, 2*n);
    
    aho.build();
    
    vector<int> ct(aho.N.size(), 0);
    int cur = 0;
    for (auto& c : s) {
        cur = aho.N[cur].next[c-'a'];
        ct[cur]++;
    }
    
    for (int i = (int)aho.order.size() - 1; i >= 0; i--) {
        int u = aho.order[i];
        ct[aho.N[u].back] += ct[u];
    }
    
    ll score_ada = 0, score_grace = 0;
    for (auto& r : ada) score_ada += (ll)ct[r.u] * ct[r.v] * r.p;
    for (auto& r : grace) score_grace += (ll)ct[r.u] * ct[r.v] * r.p;
    
    if (score_ada > score_grace) {
        cout << "Ada " << score_ada << ln;
    }
    else if (score_ada < score_grace) {
        cout << "Grace " << score_grace << ln;
    }
    else cout << "Empate " << score_grace << ln;
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
