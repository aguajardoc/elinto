// Problem: C. Try and Catch
// Contest: Codeforces - Codeforces Round 123 (Div. 2)
// URL: https://codeforces.com/contest/195/problem/C
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

string getType(string x) {
	auto start = x.find('(');
	start++;
	while (x[start] == ' ') start++;
	auto ending = x.find(',');
	int len = ending - start;
	string res = x.substr(start, len);
	while (res.back() == ' ') res.pop_back();
	
	return res;
}

string getMessage(string x) {
	auto start = x.find('"');
	start++;
	while (x[start] == ' ') start++;
	string res;
	while (x[start] != '"') {
		res += x[start++];
	}
	while (res.back() == ' ') res.pop_back();
	
	return res;
}

void solve() {
    int n;
    cin >> n;
    string type;
    vector<string> input(n);
    vector<int> validCatches;
    int depth = 0;
    cin.ignore();
    
    for (int i = 0; i < n; i++) {
    	getline(cin, input[i]);
    	
    	auto itt = input[i].find("try");
    	auto itc = input[i].find("catch");
    	auto it = input[i].find("throw");
    	
    	if (itt < itc and itt < it) {
    		depth++;
    	}
    	else if (itc < itt and itc < it) {
    		depth--;
    		// dbg(i, depth, input[i]);
    		if (validCatches.empty() or depth >= (int)validCatches.size()) continue;
    		
    		// else initialized and has chance
    		// contains the line of the catch!
    		if (validCatches[depth] == -1)
    			validCatches[depth] = i;
    	}
    	
    	else if (it < itc and it < itt) {
    		validCatches.assign(depth, -1);
    		int idx = it + 5;
    		while (input[i][idx] != ')') {
    			if (input[i][idx] != ' ' and input[i][idx] != '(') 
    				type += input[i][idx];
    			idx++;
    		}
    	}
    }
    
    
    // now iterate in backwards order over the catches,
    // first to have correct type wins
    int m = validCatches.size();
    for (int i = m - 1; i >= 0; i--) {
    	// dbg(m, i, validCatches[i]);
    	if (validCatches[i] == -1) continue;
    	string catchLine = input[validCatches[i]];
    	string ntype = getType(catchLine);
    	string message = getMessage(catchLine);
    	
    	// dbg(ntype, message);
    	
    	if (ntype == type) {
    		cout << message << ln;
    		return;
    	}
    }
    
    cout << "Unhandled Exception" << ln;
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
