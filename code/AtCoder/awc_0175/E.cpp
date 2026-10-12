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


struct SegtreeGap {
    int TREE_SIZE = 1;
    vector<int> st;

    SegtreeGap(int n) {
        while (TREE_SIZE < n) TREE_SIZE <<= 1;
        st.assign(2*TREE_SIZE, 0);
    }

    void update(int i, int x) {
        i += TREE_SIZE;
        st[i] += x;
        i >>= 1;

        while(i) {
            st[i] = st[2*i] + st[2*i+1];
            i >>= 1;
        }
    }

    int query(int l, int r) {
        l += TREE_SIZE;
        r += TREE_SIZE;
        int res = 0;

        while(l <= r) {
            if (l&1) res += st[l++];
            if (!(r&1)) res += st[r--];

            l >>= 1;
            r >>= 1;
        }

        return res;
    }

};

struct Node {
    int v, lazy;
    Node() {
        v = 0, lazy = -INF;
    }
};

struct SegtreeLen {
    vector<Node> st;
    int n;

    SegtreeLen(int n) {
        this->n = n;
        st.assign(4 * n, Node());
    }

    void push(int p, int l, int r) {
        if (st[p].lazy == -INF) return;

        int m = (l + r) / 2;
        st[2*p].v = st[p].lazy;
        st[2*p+1].v = st[p].lazy;

        st[2*p].lazy = st[p].lazy;
        st[2*p+1].lazy = st[p].lazy;

        st[p].lazy = -INF;
    }

    void update(int p, int l, int r, int i, int j, int v) {
        if (l > j or r < i) return;
        if (l >= i and r <= j) {
            st[p].v = v;
            st[p].lazy = v;
            return;
        }

        push(p, l, r);

        int m = (l + r) / 2;
        update(2*p, l, m, i, j, v);
        update(2*p+1, m + 1, r, i, j, v);

        st[p].v = st[2*p].v + st[2*p+1].v;
    }

    int query(int p, int l, int r, int i, int j) {
        if (l > j or r < i) return 0;
        if (l >= i and r <= j) return st[p].v;

        push(p, l, r);

        int m = (l + r) / 2;
        return (
            query(2*p, l, m, i, j) + 
            query(2*p + 1, m + 1, r, i, j)
        );
    }

    void update(int l, int r, int v) {
        update(1, 0, n - 1, l, r, v);
    }

    int query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};

struct Gap {
    int start, len, ending, idx;
};
int n, q;
bool is_side(Gap& g) {
    return (g.start == 0 or g.ending == n - 1);
}

void print(SegtreeLen& st, int n) {
    for (int i = 0; i < n; i++) {
        cout << st.query(i, i) << " ";
    }
    cout << ln;
}

void print(SegtreeGap& st, int n) {
    for (int i = 0; i < n; i++) {
        cout << st.query(i, i) << " ";
    }
    cout << ln;
}

void solve() {
    cin >> n >> q;
    string s; cin >> s;
    SegtreeGap stg(3*n);
    SegtreeGap stg2(3*n);
    SegtreeGap stsides(3*n);
    SegtreeGap stsides2(3*n);
    SegtreeLen stl(3*n);

    map<int, Gap> gaps;
    int gap_ct = 0;
    bool startGap = 1, endGap = 0;
    int cur = 0;
    int ones = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            cur++;
        }
        else {
            if (!i) startGap = 0;
            if (cur) {
                gaps[gap_ct] = Gap({i - cur, cur, i - 1, gap_ct++});
                cur = 0;
            }
            ones++;
        }
    }

    if (cur) {
        endGap = 1;
        gaps[gap_ct] = Gap({n - cur, cur, n - 1, gap_ct++});
    }

    stl.update(0, n - 1, -1);
    // print(stl, n);

    for (auto& [idx, gap] : gaps) {

        stl.update(gap.start, gap.ending, gap.idx);
        
        if (is_side(gap)) {
            stsides.update(gap.len, 1);
            stsides2.update(gap.len, gap.len);
        }   
        else {
            stg.update(gap.len, 1);
            stg2.update(gap.len, gap.len);
        }     
    }

    // dbg(s);
    // print(stl, n);
    // print(stg, n);
    // print(stsides, n);

    while (q--) {
        int type, x;
        cin >> type >> x;

        if (type == 1) {
            x--;
            if (s[x] == '0') {
                s[x] = '1';
                ones++;
                // we close a gap
                int gap_idx = stl.query(x, x);
                // dbg(gap_idx);
                Gap gap = gaps[gap_idx];
                stl.update(x, x, -1);
                if (gap.len == 1) {
                    // Remove this entirely
                    if(is_side(gap)) {
                        stsides.update(1, -1);
                        stsides2.update(1, -1);
                    }
                    else {
                        stg.update(1, -1);
                        stg2.update(1, -1);
                    }

                    gaps.erase(gap.idx);
                }
                else {
                    Gap L = {gap.start, x - gap.start, x - 1, gap_ct++};
                    Gap R = {x + 1, gap.ending - x, gap.ending, gap_ct++};

                    // Remove this entirely
                    if(is_side(gap)) {
                        stsides.update(gap.len, -1);
                        stsides2.update(gap.len, -gap.len);
                    }
                    else {
                        stg.update(gap.len, -1);
                        stg2.update(gap.len, -gap.len);
                    }

                    if (L.len > 0) {
                        if(is_side(L)) {
                            stsides.update(L.len, 1);
                            stsides2.update(L.len, L.len);
                        }
                        else {
                            stg.update(L.len, 1);
                            stg2.update(L.len, L.len);
                        }

                        stl.update(L.start, L.ending, L.idx);
                    }
                    if (R.len > 0) {
                        if(is_side(R)) {
                            stsides.update(R.len, 1);
                            stsides2.update(R.len, R.len);
                        }
                        else {
                            stg.update(R.len, 1);
                            stg2.update(R.len, R.len);
                        }

                        stl.update(R.start, R.ending, R.idx);
                    }

                    gaps[L.idx] = L;
                    gaps[R.idx] = R;
                }
            }
            else {
                s[x] = '0';
                ones--;

                // We expand a gap
                bool left = false, right  = false;
                Gap L, R;
                if (x and stl.query(x-1,x-1) != -1) {
                    L = gaps[stl.query(x-1,x-1)];
                    left = true;
                    gaps.erase(L.idx);
                }
                if (x != n - 1 and stl.query(x+1,x+1) != -1) {
                    R = gaps[stl.query(x+1,x+1)];
                    right = true;
                    gaps.erase(R.idx);
                }

                // Left and right ==> joined into one
                if (left and right) {
                    Gap M = {L.start, R.ending - L.start + 1, R.ending, gap_ct++};
                    
                    if(is_side(L)) {
                        stsides.update(L.len, -1);
                        stsides2.update(L.len, -L.len);
                    }
                    else {
                        stg.update(L.len, -1);
                        stg2.update(L.len, -L.len);
                    }

                    if(is_side(R)) {
                        stsides.update(R.len, -1);
                        stsides2.update(R.len, -R.len);
                    }
                    else {
                        stg.update(R.len, -1);
                        stg2.update(R.len, -R.len);
                    }


                    if (M.len > 0) {
                        if(is_side(M)) {
                            stsides.update(M.len, 1);
                            stsides2.update(M.len, M.len);
                        }
                        else {
                            stg.update(M.len, 1);
                            stg2.update(M.len, M.len);
                        }

                        stl.update(M.start, M.ending, M.idx);
                        gaps[M.idx] = M;
                    }
                }

                // Only left
                else if (left){
                    if(is_side(L)) {
                        stsides.update(L.len, -1);
                        stsides2.update(L.len, -L.len);
                    }
                    else {
                        stg.update(L.len, -1);
                        stg2.update(L.len, -L.len);
                    }

                    L.len++;
                    L.ending++;
                    gaps[L.idx] = L;

                    if(is_side(L)) {
                        stsides.update(L.len, 1);
                        stsides2.update(L.len, L.len);
                    }
                    else {
                        stg.update(L.len, 1);
                        stg2.update(L.len, L.len);
                    }

                    stl.update(L.start, L.ending, L.idx);
                }
                // Only right
                else if (right) {
                    if(is_side(R)) {
                        stsides.update(R.len, -1);
                        stsides2.update(R.len, -R.len);
                    }
                    else {
                        stg.update(R.len, -1);
                        stg2.update(R.len, -R.len);
                    }

                    R.len++;
                    R.start--;
                    gaps[R.idx] = R;

                    if(is_side(R)) {
                        stsides.update(R.len, 1);
                        stsides2.update(R.len, R.len);
                    }
                    else {
                        stg.update(R.len, 1);
                        stg2.update(R.len, R.len);
                    }

                    stl.update(R.start, R.ending, R.idx);
                }
                // new gap entirely
                else {
                    Gap M = {x, 1, x, gap_ct++};
                    if (M.len > 0) {
                        if(is_side(M)) {
                            stsides.update(M.len, 1);
                            stsides2.update(M.len, M.len);
                        }
                        else {
                            stg.update(M.len, 1);
                            stg2.update(M.len, M.len);
                        }

                        stl.update(M.start, M.ending, M.idx);
                        gaps[M.idx] = M;
                    }
                }
            }
        }
        else {
            int toq = 2 * x;
            int res = 
                toq * stg.query(toq + 1, 2*n) + 
                stg2.query(0, toq) + 
                (ones > 0) * x * stsides.query(x + 1, 2*n) + 
                (ones > 0) * stsides2.query(0, x) + 
                ones;

            // dbg(toq * stg.query(toq + 1, 2*n));
            // dbg(stg2.query(0, toq));
            // dbg(x * stsides.query(x + 1, 2*n));
            // dbg(stsides2.query(0, x));
            // dbg(ones);

            cout << res << ln;
        }

        // dbg(s);
        // print(stl, n);
        // print(stg, n);
        // print(stsides, n);
        
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
