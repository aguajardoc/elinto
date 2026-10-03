// Problem: D. Fairest Help Desk
// Contest: Codeforces - ICPC Masters Mexico 2026
// URL: https://codeforces.com/gym/106646/problem/D
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

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
// typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

// const ll INF = LLONG_MAX / 4;
const ld PI = acos(-1);
const int MOD = 1000000007;
const double eps = 1e-9;

template <class T>
int sgn(T x) {
    return (x > 0) - (x < 0);
}

template <class T>
struct Point {
    typedef Point P;
    T x, y;

    explicit Point(T x = 0, T y = 0) : x(x), y(y) {}

    bool operator<(P p) const { return tie(x, y) < tie(p.x, p.y); }
    bool operator==(P p) const { return tie(x, y) == tie(p.x, p.y); }

    P operator+(P p) const { return P(x + p.x, y + p.y); }
    P operator-(P p) const { return P(x - p.x, y - p.y); }
    P operator*(T d) const { return P(x * d, y * d); }
    P operator/(T d) const { return P(x / d, y / d); }

    T dot(P p) const { return x * p.x + y * p.y; }
    T cross(P p) const { return x * p.y - y * p.x; }
    T cross(P a, P b) const { return (a - *this).cross(b - *this); }

    T dist2() const { return x * x + y * y; }
    double dist() const { return sqrt((double)dist2()); }

    // Angle to x-axis in interval [-pi, pi]
    double angle() const { return atan2(y, x); }

    P unit() const { return *this / dist(); }  // makes dist() = 1
    P perp() const { return P(-y, x); }        // rotates +90 degrees
    P normal() const { return perp().unit(); }

    // Returns point rotated 'a' radians counter-clockwise around the origin
    P rotate(double a) const {
        return P(x * cos(a) - y * sin(a), x * sin(a) + y * cos(a));
    }

    friend ostream& operator<<(ostream& os, P p) {
        return os << "(" << p.x << "," << p.y << ")";
    }
};

typedef ld T;
typedef Point<T> P;

const T INF = numeric_limits<T>::max();

bool on_x(const P& a, const P& b) { return a.x < b.x; }
bool on_y(const P& a, const P& b) { return a.y < b.y; }

struct Node {
    P pt;  // if this is a leaf, the single point in it
    T x0 = INF, x1 = -INF, y0 = INF, y1 = -INF;  // bounding box
    Node *first = nullptr, *second = nullptr;

    // Minimum squared distance from bounding box to point p
    T distance(const P& p) {
        T x = (p.x < x0 ? x0 : (p.x > x1 ? x1 : p.x));
        T y = (p.y < y0 ? y0 : (p.y > y1 ? y1 : p.y));
        return (P(x, y) - p).dist2();
    }

    Node(vector<P>&& vp) : pt(vp[0]) {
        for (const P& p : vp) {
            x0 = min(x0, p.x); x1 = max(x1, p.x);
            y0 = min(y0, p.y); y1 = max(y1, p.y);
        }

        if (vp.size() > 1) {
            // Split along x if width >= height
            sort(all(vp), x1 - x0 >= y1 - y0 ? on_x : on_y);

            // Divide by taking half the array for each child
            int half = sz(vp) / 2;
            first  = new Node({vp.begin(), vp.begin() + half});
            second = new Node({vp.begin() + half, vp.end()});
        }
    }
};

struct KDTree {
    Node* root;

    KDTree(const vector<P>& vp) : root(new Node({all(vp)})) {}

    pair<T, P> search(Node *node, const P& p) {
        if (!node->first) {
            // Uncomment if we should not match the query point itself:
            // if (p == node->pt) return {INF, P()};
            return make_pair((p - node->pt).dist2(), node->pt);
        }

        Node *f = node->first;
        Node *s = node->second;
        T bfirst = f->distance(p);
        T bsec   = s->distance(p);

        if (bfirst > bsec) {
            swap(bsec, bfirst);
            swap(f, s);
        }

        // Search closest side first, other side only if bounded distance < best
        auto best = search(f, p);
        if (bsec < best.first) {
            best = min(best, search(s, p));
        }

        return best;
    }

    // Find nearest point and its squared distance (requires operator< for Point)
    pair<T, P> nearest(const P& p) {
        return search(root, p);
    }
};

// typedef Point<double> P;

double ccRadius(const P& A, const P& B, const P& C) {
    return (B - A).dist() * (C - B).dist() * (A - C).dist() /
           abs((B - A).cross(C - A)) / 2;
}

P ccCenter(const P& A, const P& B, const P& C) {
    P b = C - A, c = B - A;
    return A + (b * c.dist2() - c * b.dist2()).perp() / b.cross(c) / 2;
}

pair<P, double> mec(vector<P> ps) {
    shuffle(all(ps), mt19937(time(0)));
    P o = ps[0];
    double r = 0, EPS = 1 + 1e-8;

    rep(i, 0, sz(ps)) if ((o - ps[i]).dist() > r * EPS) {
        o = ps[i], r = 0;
        rep(j, 0, i) if ((o - ps[j]).dist() > r * EPS) {
            o = (ps[i] + ps[j]) / 2;
            r = (o - ps[i]).dist();
            rep(k, 0, j) if ((o - ps[k]).dist() > r * EPS) {
                o = ccCenter(ps[i], ps[j], ps[k]);
                r = (o - ps[i]).dist();
            }
        }
    }

    return {o, r};
}

bool f(ld x, vector<P>& teams, vector<ld>& dists) {
    vector<P> unhappy;
    int n = teams.size();
    for (int i = 0; i < n; i++) {
        if (dists[i] > x) {
            unhappy.pb(teams[i]);
        }
    }
    
    if (unhappy.size() <= 1) return true;
    
    pair<P, ld> mec_res = mec(unhappy);
    
    return (mec_res.second <= x);
}

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<P> desks(n), teams(m);
    for (int i = 0; i < n; i++) {
        cin >> desks[i].x >> desks[i].y;
    }
    for (int i = 0; i < m; i++) {
        cin >> teams[i].x >> teams[i].y;
    }
    
    KDTree kdt(desks);
    vector<ld> dist(m);
    ld r = 0;
    for (int i = 0; i < m; i++) {
        dist[i] = sqrt(kdt.nearest(teams[i]).first);
        r = max(r, dist[i]);
    }
    
    ld l = 0;
    ld ans = INF;
    for (int i = 0; i < 67; i++) {
        ld m = (l + r) / 2;
        
        bool fm = f(m, teams, dist);
        
        if (fm) {
            ans = min(ans, m);
            r = m;
        }
        else {
            l = m;
        }
    }
    
    cout << fixed << setprecision(10) << ans << ln;
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
