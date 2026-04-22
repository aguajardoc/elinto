// Problem: B. Bad LaTeX
// Contest: Codeforces - 2026 ICPC Gran Premio de Mexico 1ra Fecha
// URL: https://codeforces.com/gym/106495/problem/B
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
    string s;
    getline(cin, s);
    
    vector<string> words;
    string cur;
    s += ' ';
    for (auto& c : s) {
    	if (c == ' ') {
    		words.pb(cur);
    		cur.clear();
    	}
    	else cur += c;
    }
    
    string ans;
    
    for (auto& word : words) {
    	bool alldig = true;
    	for (auto& c : word) {
    		if (!isdigit(c)) alldig = false;
    	}
    	
    	if (!alldig or word.length() <= 4) {
    		ans += word;
    		ans += ' ';
    		continue;
    	}
    	
    	bool zeros_4 = (word.substr(word.length() - 4, string::npos) == "0000");
    	
    	if (!zeros_4) {
    		ans += word;
    		ans += ' ';
    		continue;
    	}
    	
    	bool pow10 = (word[0] == '1');
    	bool otherDig = 0;
    	for (int c = 1; c < word.length(); c++) {
    		if (word[c] != '0') {
    			pow10 = false;
    			otherDig = true;
    		}
    	}
    	
    	string local;
    	if (pow10) {
    		local += "10^{";
    		local += to_string(word.length() - 1);
    		local += "}";
    	}
    	else {
    		if (!otherDig) {
    			local += word[0];
    			local += "\\cdot10^{";
    			local += to_string(word.length() - 1);
    			local += "}";
    		}
    		else {
    			int lnz = 0;
    			for (int i = 0; i < word.length(); i++) {
    				if (word[i] != '0') lnz = i;
    			}
    			
    			local += word[0];
    			local += '.';
    			for (int i = 1; i <= lnz; i++) {
    				local += word[i];
    			}
    			local += "\\cdot10^{";
    			local += to_string(word.length() - 1);
    			local += "}";
    		}
    	}
    	
    	ans += local;
    	ans += ' ';
    }
    
    ans.pop_back();
    
    cout << ans << ln;
}

signed main() {
    fast_cin();
    
    int T = 1;
    cin >> T;
    cin.ignore();
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
