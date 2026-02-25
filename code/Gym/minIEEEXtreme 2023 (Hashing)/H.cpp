// Problem: H. Consistent Occurrences
// Contest: Codeforces - Topic 9 - Hashing
// URL: https://codeforces.com/group/OyefIGO3t4/contest/447289/problem/H
// Memory Limit: 256 MB
// Time Limit: 4000 ms
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

// Usage: rng();
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

const int M1 = MOD;
const int M2 = MOD + 2;

const int b1 = uniform_int_distribution<int>(31, M1 - 1)(rng);
const int b2 = uniform_int_distribution<int>(31, M2 - 1)(rng);

int n, m;

vector<int> pows1, pows2;
vector<pair<int, int>> rollingS;

void fillPows() {
	pows1.reserve(n);
    pows2.reserve(n);
	int C1 = 1;
	int C2 = 1;
	
	pows1.pb(C1);
	pows2.pb(C2);
	
	for (int i = 1; i < n; i++) {
		C1 = (C1 * b1) % M1;
		C2 = (C2 * b2) % M2;
		
		pows1.pb(C1);
		pows2.pb(C2);
	}
	
	reverse(pows1.begin(), pows1.end());
	reverse(pows2.begin(), pows2.end());
}

void getRolling(string& s, vector<pair<int, int>>& a) {
	a.reserve(s.length() + 1);
	a.pb({0, 0});
	int C1 = 0;
	int C2 = 0;
	
	for (int i = 0; i < (int)s.length(); i++) {
		C1 = (C1 + pows1[i] * (s[i] - 'a' + 1)) % M1;
		C2 = (C2 + pows2[i] * (s[i] - 'a' + 1)) % M2;
		
		a.pb({C1, C2});
	}
}

vector<int> checkCount(string& s, int T, vector<pair<int, int>>& Ts, int nums) {
	vector<pair<pair<int, int>, int>> eq;
	eq.reserve(Ts.size());
	
	for (int i = 0; i < (int)Ts.size(); i++) {
		eq.pb({{Ts[i]}, i});
	}
	
	sort(eq.begin(), eq.end());
	
	vector<int> LE(nums, -1);
	vector<int> ct(nums, 0);
	
	for (int i = 0; i < n; i++) {
		if (i + T > n) break;
		int S1 = (rollingS[i + T].first - rollingS[i].first);
		if (S1 < 0) S1 += M1;
		int S2 = (rollingS[i + T].second - rollingS[i].second);
		if (S2 < 0) S2 += M2;
		
		S1 = (S1 * pows1[n - i - 1]) % M1;
		S2 = (S2 * pows2[n - i - 1]) % M2;
		
		pair<int, int> NH = {S1, S2};
		
		auto it = lower_bound(eq.begin(), eq.end(), make_pair(NH, -1ll));
		
		while (it != eq.end() and it->first == NH) {
			int j = it->second;
			if (i >= LE[j]) {
				ct[j]++;
				LE[j] = i + T;
			}
			it++;
		}
	}
	
	return ct;
}

void solve() {
	cin >> n >> m;
	
	string s;
	cin >> s;
	
	fillPows();
	getRolling(s, rollingS);
	
	vector<int> lens;
	lens.reserve(m);
	vector<string> ti(m);
	
	for (int i = 0; i < m; i++) {
		cin >> ti[i];
		
		lens.pb((int)ti[i].length());
	}
	
	sort(lens.begin(), lens.end());
	lens.resize(unique(lens.begin(), lens.end()) - lens.begin());
	
	int k = lens.size();
	vector<vector<pair<int, int>>> rollingSize(k);
	vector<vector<int>> idxs(k);
	
	for (int i = 0; i < m; i++) {
		vector<pair<int, int>> rollingT;
		getRolling(ti[i], rollingT);
		
		int T = ti[i].length();
		int x = lower_bound(lens.begin(), lens.end(), T) - lens.begin();
		
		rollingSize[x].pb(rollingT.back());
		idxs[x].pb(i);
	}
	
	vector<int> ans(m);
	
	for (int i = 0; i < k; i++) {
		vector<int> interim = checkCount(s, lens[i], rollingSize[i], (int)rollingSize[i].size());
		
		for (int j = 0; j < (int)idxs[i].size(); j++){
			ans[idxs[i][j]] = interim[j];
		}
	}
	for (auto& i : ans) {
		cout << i << ln;
	}
	
	
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