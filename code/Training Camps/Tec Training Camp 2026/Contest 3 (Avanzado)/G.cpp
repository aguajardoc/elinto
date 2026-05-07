// Problem: G. Least Prefix Sum
// Contest: Codeforces - TC Tec 2026 Contest 3 (Avanzado)
// URL: https://codeforces.com/group/eZBA1VtmXM/contest/691006/problem/G
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

int i,j;

void solve() {
	int n,m;
	cin >> n >> m;
	
	vector<ll> vec1;
	vector<ll> vec2;
	priority_queue<ll> pq1;
	priority_queue<ll> pq2;
	
	ll ans = 0;
	ll k = n-m;
	ll a;
	
	for(i=0;i<m;i++) {
		cin >> a;
		vec1.push_back(a);
	}
	
	reverse(vec1.begin(), vec1.end());
	
	for(i=0;i<k;i++) {
		cin >> a;
		vec2.push_back(a);
	}
	
	vector<ll> Pfx1(m+1,0);
	vector<ll> Pfx2(k+1,0);
	
	for(i=1;i<m;i++) {
		Pfx1[i] = Pfx1[i-1] + vec1[i-1];
		
		if(vec1[i-1] > 0) {
			pq1.push(2*abs(vec1[i-1]));
		}
		
		if(Pfx1[i] > 0) {
			Pfx1[i] -= pq1.top();
			pq1.pop();
			ans++;
		}
	}
	
	
	for(i=1;i<k+1;i++) {
		Pfx2[i] = Pfx2[i-1] + vec2[i-1];
		
		if(vec2[i-1] < 0) {
			pq2.push(2*abs(vec2[i-1]));
		}
		
		if(Pfx2[i] < 0) {
			Pfx2[i] += pq2.top();
			pq2.pop();
			ans++;
		}
	}
	
	if(n == 1) { cout << 0 << endl; }
	else { cout << ans << endl; }
    
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
