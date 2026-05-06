// Problem: J. Koxia and Number Theory
// Contest: Codeforces - TC Tec 2026 Contest 1 (Avanzado)
// URL: https://codeforces.com/group/eZBA1VtmXM/contest/690676/problem/J
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

bitset<111> bs;
vector<int> primos;

void sieve() {
	bs.set();
	bs[0] = bs[1] = false;
	
	for (int i = 2; i <= 110; i++) {
		if (!bs[i]) continue;
		for (int j = i * i; j <= 110; j+=i) {
			bs[j] = false;
		}
		primos.pb(i);
	}
}

void solve() {
	vector <map<int,int>> cong (120);
	
	int n; cin >> n;
	vector <ll> arr (n);
	map <ll,int> iguales;
	for(int i = 0; i<n; i++){
		ll x; cin >> x; arr[i] = x; iguales[x]++;
	}
	
	for(auto i : iguales){
		if(i.second > 1){
			cout << "NO" << endl; return;
		}
	}
	
	for(int i : arr){
		for(int p : primos){
			cong[p][i%p]++;
		}
	}
	bool jala1 = true;
	for(int p : primos){
		bool jala2 = false;
		for(int i = 0; i<p; i++){
			if(cong[p][i] < 2){
				jala2 = true;
			}
		}
		if(!jala2){
			jala1 = false;
		}
	}
	if(jala1){
		cout << "YES" << endl; return;
	}
	
	cout << "NO" << endl;
}

signed main() {
    fast_cin();
    sieve();
    
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
