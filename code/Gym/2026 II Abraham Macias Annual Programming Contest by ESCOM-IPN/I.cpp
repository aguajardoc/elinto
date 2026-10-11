// Problem: I. Your Best American Poly
// Contest: Codeforces - 2026 II Abraham Macias Annual Programming Contest by ESCOM-IPN
// URL: https://codeforces.com/gym/106721/problem/I
// Memory Limit: 512 MB
// Time Limit: 15000 ms
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

struct pt{
    ld x, y;
    pt operator + (const pt & p) const {
        return pt{x + p.x, y + p.y};
    }
    pt operator - (const pt & p) const {
        return pt{x - p.x, y - p.y};
    }
    ld cross(const pt & p) const {
        return x * p.y - y * p.x;
    }
};

void reorder_polygon(vector<pt> & P){
    size_t pos = 0;
    for(size_t i = 1; i < P.size(); i++){
        if(P[i].y < P[pos].y || (P[i].y == P[pos].y && P[i].x < P[pos].x))
            pos = i;
    }
    rotate(P.begin(), P.begin() + pos, P.end());
}

vector<pt> minkowski(vector<pt> P, vector<pt> Q){
    // the first vertex must be the lowest
    reorder_polygon(P);
    reorder_polygon(Q);
    // we must ensure cyclic indexing
    P.push_back(P[0]);
    P.push_back(P[1]);
    Q.push_back(Q[0]);
    Q.push_back(Q[1]);
    // main part
    vector<pt> result;
    size_t i = 0, j = 0;
    while(i < P.size() - 2 || j < Q.size() - 2){
        result.push_back(P[i] + Q[j]);
        auto cross = (P[i + 1] - P[i]).cross(Q[j + 1] - Q[j]);
        int sign = (cross > 0) - (cross < 0);
        
        if(sign > 0 && i < P.size() - 2)
            ++i;
        if(sign < 0 && j < Q.size() - 2)
            ++j;
    }
    return result;
}

vector<pt> create_circle(ld r) {
    const int SIDES = 1000;
    ld rate = (ld)PI * 2 / SIDES;
    vector<pt> circle(SIDES);
    for (int i = 0; i < SIDES; i++) {
        ld x = r * cos(i * rate);
        ld y = r * sin(i * rate);
        
        circle[i] = {x, y};
    }
    
    return circle;
}

ld area(const vector<pt>& fig) {
    ld res = 0;
    for (unsigned i = 0; i < fig.size(); i++) {
        pt p = i ? fig[i - 1] : fig.back();
        pt q = fig[i];
        res += (p.x - q.x) * (p.y + q.y);
    }
    return fabs(res) / 2;
}

void solve() {
    int n, k; cin >> n >> k;
    vector<pt> P(n);
    ld avg_x = 0, avg_y = 0;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        P[i].x = x;
        P[i].y = y;
        
        avg_x += x;
        avg_y += y;
    }
    
    avg_x /= n;
    avg_y /= n;
    
    ld ans = INF;
    ld l = eps, r = INF;
    for (int i = 0; i < 1000; i++) {
        ld m = (l + r) / 2;
        
        vector<pt> Q = create_circle(m);
        vector<pt> MS = minkowski(P, Q);
        
        ld A = area(MS);
        
        if (A > k) {
            ans = min(ans, m);
            r = m;
        }
        else l = m;
    }
    
    cout << fixed << setprecision(10) << ans << ln;
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
