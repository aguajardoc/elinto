// Problem: E. Classy Numbers
// Contest: Codeforces - TC Tec 2026 Contest 5 (Avanzado)
// URL: https://codeforces.com/group/eZBA1VtmXM/contest/691508/problem/E
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
#define int ll
#define ld long double
#define pb push_back

const ll INF = LLONG_MAX / 4;
const ld PI = acos(-1);
const int MOD = 1000000007;
const double eps = 1e-9;

int i,j;

vector<vector<ll>> matriz(19,vector<ll>(3,0));
vector<ll> matriz1(19,0);
vector<ll> matriz2(19,0);
vector<ll> matriz3(19,0);
    

void solve() {
    string s1,s2;
    ll x;
    cin >> x >> s2;
    x--;
    s1 = to_string(x);
    
    
    int a,b,c;
    int pa,pb,pc;
    pa=1;pb=1;pc=1;
    a=b=c=0;
    int h = s1.size();
    for(i=0;i<h;i++) {
    	if(a == 0 && s1[i] != '0') {
    		a = s1[i] - '0';
    		pa = h - i;
    	} else if(b == 0 && s1[i] != '0') {
    		b = s1[i] - '0';
    		pb = h - i;
    	} else if(c == 0 && s1[i] != '0') {
    		c = s1[i] - '0';
    		pc = h - i;
    	}
    }
    
    ll ans1 = 0;
    ans1 += matriz3[pa-1];
    ans1 += (a-1)*matriz2[pa-1];
    ans1 += matriz2[pb-1];
    ans1 += (b-1)*matriz1[pb-1];
    ans1 += matriz1[pc-1];
    ans1 += a+b+c;


    pa=1;pb=1;pc=1;
    a=b=c=0;
    h = s2.size();
    for(i=0;i<h;i++) {
    	if(a == 0 && s2[i] != '0') {
    		a = s2[i] - '0';
    		pa = h - i;
    	} else if(b == 0 && s2[i] != '0') {
    		b = s2[i] - '0';
    		pb = h - i;
    	} else if(c == 0 && s2[i] != '0') {
    		c = s2[i] - '0';
    		pc = h - i;
    	}
    }
    
    ll ans2 = 0;
    ans2 += matriz3[pa-1];
    ans2 += (a-1)*matriz2[pa-1];
    ans2 += matriz2[pb-1];
    ans2 += (b-1)*matriz1[pb-1];
    ans2 += matriz1[pc-1];
    ans2 += a+b+c;
    
    

    
    cout << ans2 - ans1 << endl;
    
    
}

signed main() {
    fast_cin();

    for(i=1;i<19;i++) {
    	matriz[i][0] = 9;
    }
    for(i=2;i<19;i++) {
    	matriz[i][1] = 9*9*(i-1);
    }
    for(i=3;i<19;i++) {
    	matriz[i][2] = 9*9*9*((i-2)*(i-1))/2;
    }
    
    for(i=1;i<19;i++) {
    	matriz1[i] = matriz1[i-1] + matriz[i][0];
    }
    
    for(i=1;i<19;i++) {
    	matriz2[i] = matriz2[i-1] + matriz[i][0] + matriz[i][1];
    }
    
    for(i=1;i<19;i++) {
    	matriz3[i] = matriz3[i-1] + matriz[i][0] + matriz[i][1] + matriz[i][2];
    }
    
    
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
