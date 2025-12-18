// Problem: B. Facetook Priority Wall
// Contest: Codeforces - Codeforces Beta Round 67 (Div. 2)
// URL: https://codeforces.com/contest/75/problem/B
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
#define INF 2e18
#define PI 3.14159265358979323846
#define MOD 1000000007

double eps = 1e-9;

void getWord(string& s, int& j, string& x) {
	int n = s.length();
	for (; j < n; j++) {
		if (s[j] == ' ') {
			break;
		}
		x += s[j];
	}
	j++;
}

void ignoreWord(string& s, int& j) {
	int n = s.length();
	for (; j < n; j++) {
		if (s[j] == ' ') {
			break;
		}
	}
	j++;
}

void solve() {
    string me;
    cin >> me;
    int n;
    cin >> n;
    map<string, int> points;
    map<char, int> typeToPoints = {{'l', 5},
    								{'c', 10},
    								{'p', 15}};
    cin.ignore();
    for (int i = 0; i < n; i++) {
    	string s;
    	getline(cin, s);
    	string sender, recipient;
    	int j = 0;
    	getWord(s, j, sender);
    	// int np = typeToPoints(s[j]);
    	int np = 5;
    	if (s[j] == 'c') np *= 2;
    	if (s[j] == 'p') np *= 3;    	
    	if (s[j] == 'l') {
    		// second word is recipient
    		ignoreWord(s, j);
    		getWord(s, j, recipient);
    	}
    	else {
    		// third word is recipient
    		ignoreWord(s, j);
    		ignoreWord(s, j);
    		getWord(s, j, recipient);
    	}
    	recipient.pop_back();
    	recipient.pop_back();
    	
    	if (recipient == me) swap(sender, recipient);
    	points[recipient];
    	if (sender != me) points[sender];
    	if (sender == me) {
    		points[recipient] += np;
    	}
    }
    
    vector<pair<ll, string>> pointspp;
    for (auto& i : points) {
    	// dbg(i.first, i.second);
    	pointspp.push_back({(ll)i.second, i.first});
    }
    sort(pointspp.begin(), pointspp.end(), [](const auto& a, const auto& b) {
    	if (a.first != b.first) return a.first > b.first;
    	else return a < b;
    });
    
    for (int i = 0; i < pointspp.size(); i++) {
    	cout << pointspp[i].second << ln;
    }
}

signed main() {
    fast_cin();
    
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
