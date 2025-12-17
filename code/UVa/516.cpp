// Problem: 516 - Prime Land
// Contest: UVa Online Judge
// URL: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=457
// Memory Limit: 32 MB
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
#define INF 2e18
#define PI 3.14159265358979323846
#define MOD 1000000007

double eps = 1e-9;

bitset<100000> bs;
vector<int> p;

void sieve() {
	bs.set();
	bs[0] = bs[1] = false;
	
	for (ll i = 2; i <= 10000; i++) {
		if (!bs[i]) continue;
		for (ll j = i * i; j <= 10000; j+=i) {
			bs[j] = false;
		}
		
		p.push_back(i);
	}
}

vector<pair<ll,ll>> processInput(string s) {
	vector<pair<ll,ll>> pct;
	string cur;
	s += ' ';
	for (auto& i : s) {
		if (i == ' ') {
			if (cur.empty()) continue;
			
			if (pct.empty() or pct.back().second != 0) {
				pct.push_back({stoll(cur), 0});
			}
			else {
				pct.back().second = stoll(cur);
			}
			
			cur.clear();
		}
		else {
			cur += i;
		}
	}
	return pct;
}

map<int, int> pfac(ll x) {
	map<int, int> factors;
	for (int i = 0; i < p.size() and p[i] * p[i] <= x; i++) {
		while (x % p[i] == 0) {
			factors[p[i]]++;
			x /= p[i];
		}
	}
	if (x > 1) factors[x]++;
	
	return factors;
}

void solve() {
    string s;
    while(getline(cin, s)) {
    	if (s.length() == 1 and s[0] == '0') break;
    	vector<pair<ll, ll>> pct = processInput(s);
    	
    	ll number = 1;
    	for (int i = 0; i < pct.size(); i++) {
    		for (int j = 0; j < pct[i].second; j++) {
    			number *= pct[i].first;
    		}
    	}
    	
    	number--;
    	map<int, int> fac = pfac(number);
    	vector<pair<int, int>> facv;
    	for (auto& i : fac){
    		facv.push_back(i);
    	}
    	int n = facv.size();
    	sort(facv.rbegin(), facv.rend());
    	for (int i = 0; i < n - 1; i ++) {
    		cout << facv[i].first << " " << facv[i].second << " ";
    	}
    	cout << facv.back().first << " " << facv.back().second << ln;
    }
}

signed main() {
    fast_cin();
    sieve();
    
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
