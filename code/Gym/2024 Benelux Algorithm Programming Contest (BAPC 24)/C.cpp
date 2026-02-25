// Problem: C. Concurrent Contests
// Contest: Codeforces - 2024 Benelux Algorithm Programming Contest (BAPC 24)
// URL: https://codeforces.com/gym/105492/problem/C
// Memory Limit: 1024 MB
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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> skill(n); 
    vector<int> prizes(m);
    for (int i = 0; i < n; i++) {
    	cin >> skill[i].first;
    	skill[i].second = i;
    }
    for (auto& i : prizes) cin >> i;
    
    vector<vector<int>> ans(m);
    vector<int> curSkill(m, 0);
    
    sort(skill.rbegin(), skill.rend());
    
    for (int i = 0; i < n; i++) {
    	int best = 0, expected = INF;
    	int ski = skill[i].first;
    	
    	for (int j = 0; j < m; j++) {
    		if (prizes[j] * (ski + curSkill[best]) > prizes[best] * (ski + curSkill[j])) {
    			best = j;
    		}
    	}
    	
    	ans[best].pb(skill[i].second + 1);
    	curSkill[best] += ski;
    }
    
    for (auto& i : ans) {
    	cout << i.size() << " ";
    	for (auto& j : i) {
    		cout << j << " ";
    	}
    	cout << ln;
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