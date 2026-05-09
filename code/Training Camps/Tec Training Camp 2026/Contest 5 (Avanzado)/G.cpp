// Problem: G. Eat the Chip
// Contest: Codeforces - TC Tec 2026 Contest 5 (Avanzado)
// URL: https://codeforces.com/group/eZBA1VtmXM/contest/691508/problem/G
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

void solve() {
    int h,w, xa, ya, xb, yb;
    cin >> w >> h >> ya >> xa >> yb >> xb;
    int pmedio = (ya+yb)/2;
    if(yb-ya <= 0) {cout << "Draw" << endl; return;}
    
    if((yb-ya-1)%2){
    	if(xb == xa){cout << "Bob" << endl; return;}
    	if(xa > xb){
    		int dern = yb-h+xb;
    		int derb = ya+h-xa;
    		if(dern >= pmedio) {cout << "Bob" << endl; return;}
    		else {cout << "Draw" << endl; return;}
    	}
    	else{
    		int izqn = yb-xb+1;
    		int izqb = ya+xa-1;
    		if(izqn >= pmedio){cout << "Bob" << endl; return;}
    		else{cout << "Draw" << endl; return;}
    	}
    } 
    else{
    	if(abs(xb-xa)<=1){cout << "Alice" << endl; return;}
    	if(xb > xa){
    		int dern = yb-h+xb;
    		int derb = ya+h-xa;
    		if(pmedio+1 >= derb) {cout << "Alice" << endl; return;}
    		else {cout << "Draw" << endl; return;}
    	}
    	else{
    		int izqn = yb-xb+1;
    		int izqb = ya+xa-1;
    		if(pmedio+1 >= izqb){cout << "Alice" << endl; return;}
    		else{cout << "Draw" << endl; return;}
    	}
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
