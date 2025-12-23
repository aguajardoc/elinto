// Problem: 872 - Ordering
// Contest: UVa Online Judge
// URL: https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=813
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
map<char, int> ltn;
map<int, char> ntl;
map<int, set<int>> conds;

string getVars() {
	string s;
	getline(cin, s);
	string vars;
	for (char& i : s) {
		if (i != ' ') vars += i;
	} 
	return vars;
}

void flattenVars(string& vars) {
	for (int i = 0; i < vars.length(); i++) {
		ltn[vars[i]] = i;
		ntl[i] = vars[i];
	}
}

void getConditions() {
	string s;
	getline(cin, s);
	s += ' ';
	string cur;
	for (char& i : s) {
		if (i == ' ') {
			if (cur.empty()) continue;
			conds[ltn[cur[2]]].insert(ltn[cur[0]]);
			cur.clear();
		}
		else cur += i;
	}
}

vector<string> ans;

void recurse(int idx, int taken, string& ordering) {
	if (idx == ltn.size()) {
		// taken must be a valid state!
		ordering.pop_back();
		ans.push_back(ordering);
		ordering += ' ';
		return;
	}
	
	// iterate over non chosen
	for (int i = 0; i < ltn.size(); i++) {
		if (taken & (1ll << i)) continue;
		
		// else check condition
		bool flag = true;
		for (const ll& j : conds[i]) {
			if (!(taken & (1ll << j))) flag = false;
		}
		
		if (flag) {
			ordering += ntl[i];
			ordering += ' ';
			recurse(idx + 1, (taken | (1ll << i)), ordering);
			ordering.pop_back();
			ordering.pop_back();
		}
	}
}

void solve(int c) {
    ltn.clear();
    ntl.clear();
    conds.clear();
    ans.clear();

    string vars = getVars();
    flattenVars(vars);
	getConditions();
	string x;
	recurse(0, 0, x);
	
	if (ans.empty()) {
		cout << "NO" << ln;
	}
	else {
		for (string& i : ans) {
			cout << i << ln;
		}
	}
	if (c != 1)cout << ln;
}

signed main() {
    fast_cin();
    
    int T = 1;
    cin >> T;
    cin.ignore();
    for (int i = 1; i <= T; i++) {
    	cin.ignore();
        solve( i == T );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
