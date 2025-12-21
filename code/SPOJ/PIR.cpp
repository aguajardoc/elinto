// Problem: Pyramids
// Contest: SPOJ - Classical
// URL: https://www.spoj.com/problems/PIR/
// Memory Limit: 1536 MB
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
#define INF 2e18
#define PI 3.14159265358979323846
#define MOD 1000000007

double eps = 1e-9;


ld determinant(int n, vector<vector<ld>>& a) {
	double det = 1;
	for (int i=0; i<n; ++i) {
	    int k = i;
	    for (int j=i+1; j<n; ++j)
	        if (abs (a[j][i]) > abs (a[k][i]))
	            k = j;
	    if (abs (a[k][i]) < eps) {
	        det = 0;
	        break;
	    }
	    swap (a[i], a[k]);
	    if (i != k)
	        det = -det;
	    det *= a[i][i];
	    for (int j=i+1; j<n; ++j)
	        a[i][j] /= a[i][i];
	    for (int j=0; j<n; ++j)
	        if (j != i && abs (a[j][i]) > eps)
	            for (int k=i+1; k<n; ++k)
	                a[j][k] -= a[i][k] * a[j][i];
	}
	
	return det;
}

void solve() {
    ll AB, AC, AD, BC, BD, CD;
    cin >> AB>>AC>>AD>>BC>>BD>>CD;
    
    vector<vector<ld>> a = {{0, 1, 1, 1, 1},
    						{1, 0, AB * AB, AC * AC, AD * AD},
    						{1, AB * AB, 0, BC * BC, BD * BD},
    						{1, AC * AC, BC * BC, 0, CD * CD},
    						{1, AD * AD, BD * BD, CD * CD, 0}};
    
	ld V = sqrt(((ld)1/288) * determinant(5, a));
	cout << fixed << setprecision(4) << V << ln;
}

signed main() {
    fast_cin();
    
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
