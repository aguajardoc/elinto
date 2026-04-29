// Problem: K. Kernel of the Disks
// Contest: Codeforces - 2026 ICPC Gran Premio de Mexico 1ra Fecha
// URL: https://codeforces.com/gym/106495/problem/K
// Memory Limit: 256 MB
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

struct Circle {
	int x, y, r;
};


bool inside(ld px, ld py, Circle C) {
	ld LHS = ((ld)px - C.x) * ((ld)px - C.x) + 
			((ld)py - C.y) * ((ld)py - C.y);
			
	ld RHS = C.r * C.r;
	
	return (LHS <= RHS + 2 * C.r * eps);
}

vector<ld> getInt(Circle A, Circle B) {
	B.x -= A.x;
	B.y -= A.y;
	double r = A.r, aa = -2*B.x, b=-2*B.y, c = B.x*B.x+B.y*B.y+A.r*A.r-B.r*B.r; // given as input
	if (c == 0) return {};
double x0 = -aa*c/(aa*aa+b*b), y0 = -b*c/(aa*aa+b*b);
if (c*c > r*r*(aa*aa+b*b)+eps)
    return {};
else if (abs (c*c - r*r*(aa*aa+b*b)) < eps) {
    return {x0 + A.x, y0 + A.y};
}
else {
    double d = r*r - c*c/(aa*aa+b*b);
    double mult = sqrt (d / (aa*aa+b*b));
    double ax, ay, bx, by;
    ax = x0 + b * mult;
    bx = x0 - b * mult;
    ay = y0 - aa * mult;
    by = y0 + aa * mult;
    return {ax + A.x, ay + A.y, bx + A.x, by + A.y};
}
}

vector<ld> lineCircInt(vector<ld> line, Circle A) {
	double r = A.r, a = line[0], b = line[1], c = line[2] + a * A.x + b * A.y; // given as input
double x0 = -a*c/(a*a+b*b), y0 = -b*c/(a*a+b*b);
if (c*c > r*r*(a*a+b*b)+eps)
    return {};
else if (abs (c*c - r*r*(a*a+b*b)) < eps) {
    
    return {x0 + A.x, y0 + A.y};
}
else {
    double d = r*r - c*c/(a*a+b*b);
    double mult = sqrt (d / (a*a+b*b));
    double ax, ay, bx, by;
    ax = x0 + b * mult;
    bx = x0 - b * mult;
    ay = y0 - a * mult;
    by = y0 + a * mult;
    
    return {ax + A.x, ay + A.y, bx + A.x, by + A.y};
}
}

vector<ld> makeLine(ld x0, ld y0, ld x1, ld y1) {
	ld A = y1 - y0;
	ld B = - (x1 - x0);
	ld C = y0 * (x1 - x0) - x0 * (y1 - y0);
	
	return {A,B,C};
}

void solve() {
    int n;
    cin >> n;
    int px, py;
    cin >> px >> py;
    
    vector<Circle> circ(n);
    for (int i = 0; i < n; i++) {
    	cin >> circ[i].x >> circ[i].y >> circ[i].r;
    }
    
    // Check if inside all
    bool IA = true;
    for (int i = 0; i < n; i++) {
    	if (!inside(px, py, circ[i])) IA = false;
    }
    
    if (IA) {
    	cout << 0 << ln;
    	return;
    }
    
    ld ans = INF;
    // Check all corners -> intersection btw i and j
    for (int i = 0; i < n; i++) {
    	for (int j = i + 1; j < n; j++) {
    		vector<ld> POI = getInt(circ[i], circ[j]);
    		
    		for (int k = 0; k < POI.size(); k += 2) {
    			// get point
    			ld PX = POI[k];
    			ld PY = POI[k+1];
    			
    			// check if inside all
    			bool IA = true;
			    for (int l = 0; l < n; l++) {
			    	if (!inside(PX, PY, circ[l])) IA = false;
			    }
			    
			    if (!IA) continue;
			    
			    // else get dist and update ans
			    ans = min (ans,
			    	hypot(px - PX, py - PY)
			    );
    		}
    	}
    }
    
    
    // Check all boundaries -> line to center
    for (int i = 0; i < n; i++) {
    	// Make line from p to center
    	if (px == circ[i].x and py == circ[i].y) continue;
    	vector<ld> line = makeLine(px, py, circ[i].x, circ[i].y);
    	
    	// Find POI
    	vector<ld> POI = lineCircInt(line, circ[i]);
    	for (int k = 0; k < POI.size(); k += 2) {
			// get point
			ld PX = POI[k];
			ld PY = POI[k+1];
			
			// check if inside all
			bool IA = true;
		    for (int l = 0; l < n; l++) {
		    	if (!inside(PX, PY, circ[l])) IA = false;
		    }
		    
		    if (!IA) continue;
		    
		    // else get dist and update ans
		    ans = min (ans,
		    	hypot(px - PX, py - PY)
		    );
		}
    }
    
    
    cout << fixed << setprecision(15) << ans << ln;
    
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