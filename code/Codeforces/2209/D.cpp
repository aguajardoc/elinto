// Problem: D. Ghostfires
// Contest: Codeforces - Codeforces Round 1087 (Div. 2)
// URL: https://codeforces.com/contest/2209/problem/D
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

void solve() {
    int r, g, b;
    cin >> r >> g >> b;
    
   	int rg = 0, gb = 0, rb = 0;
   	
   	while ((r > 0) + (g > 0) + (b > 0) >= 2) {
   		if (r <= g and r <= b) {
   			gb++; g--;b--;
   		}
   		else if (g <= r and g <= b) {
   			rb++; r--; b--;
   		}
   		else {
   			rg++; r--; g--;
   		}
   	}
   	
   	char p,x,y;
   	int cpx, cpy, cxy;
   	
   	if (g or (!r and !b)) {
   		p = 'G', x = 'R', y = 'B';
   		cpx = rg, cpy = gb, cxy = rb;
   	}
   	else if (r) {
   		p = 'R', x = 'G', y = 'B';
   		cpx = rg, cpy = rb, cxy = gb;
   	}
   	else {
   		p = 'B', x = 'G', y = 'R';
   		cpx = gb, cpy = rb, cxy = rg;
   	}
   	
   	string ans;
   	if (r or g or b) ans += p;
   	
   	while (cpx--) {
   		ans += x;
   		ans += p;
   	}
   	
   	bool py = false;
   	while (cpy--) {
   		ans += y;
   		ans += p;
   		py = true;
   	}
   	
   	while (cxy--) {
   		ans += (py ? y : x);
   		ans += (py ? x : y);
   	}
   	
   	cout << ans << ln;
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

//g++ A.cpp && ./a.out <input.in>output.out
