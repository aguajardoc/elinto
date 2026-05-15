// Problem: H. Heroes of Velmar
// Contest: Codeforces - 2023-2024 ACM-ICPC Nordic Collegiate Programming Contest (NCPC 2023)
// URL: https://codeforces.com/gym/105427/problem/H
// Memory Limit: 512 MB
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

map<string, int> energy, power;

vector<vector<vector<string>>> loc(2, vector<vector<string>> (3));
vector<int> W(2), T(2);
vector<vector<int>> loc_pow(2, vector<int> (3, 0));

void init() {
	energy["Shadow"] 		= 4;
	energy["Gale"] 			= 3;
	energy["Ranger"] 		= 2;
	energy["Anvil"] 		= 5;
	energy["Vexia"] 		= 2;
	energy["Guardian"] 		= 6;
	energy["Thunderheart"] 	= 5;
	energy["Frostwhisper"] 	= 1;
	energy["Voidclaw"] 		= 1;
	energy["Ironwood"] 		= 1;
	energy["Zenith"] 		= 6;
	energy["Seraphina"] 	= 1;
	
	power["Shadow"] 		= 6;
	power["Gale"] 			= 5;
	power["Ranger"] 		= 4;
	power["Anvil"] 			= 7;
	power["Vexia"] 			= 3;
	power["Guardian"] 		= 8;
	power["Thunderheart"] 	= 6;
	power["Frostwhisper"] 	= 2;
	power["Voidclaw"] 		= 3;
	power["Ironwood"] 		= 3;
	power["Zenith"] 		= 4;
	power["Seraphina"] 		= 1;
}

int get_power(string who, int where, int player) {
	if (who == "Thunderheart") {
		if (loc[player][where].size() >= 4) {
			return power[who] * 2;
		}
	}
	
	if (who == "Zenith" and where == 1) {
		return power[who] + 5;
	}
	
	if (who == "Seraphina") {
		return loc[player][where].size();
	}
	
	return power[who];
}

void solve() {
    init();
    
    for (int i = 0, location = 0; i < 6; i++) {
    	
    	if (i == 2 or i == 4) location++;
    	int player = i % 2;
    	
    	int k;
    	cin >> k;
    	for (int j = 0; j < k; j++) {
    		string s;
    		cin >> s;
    		loc[player][location].pb(s);
    	}
    }
    
    for (int player = 0; player < 2; player++) {
    	for (int location = 0; location < 3; location++) {
    		for (auto& s : loc[player][location]) {
    			int pow = get_power(s, location, player);

    			loc_pow[player][location] += pow;
    			T[player] += pow;
    		}
    	}
    }
    
    for (int location = 0; location < 3; location++) {
    	if (loc_pow[0][location] > loc_pow[1][location]) W[0]++;
    	if (loc_pow[0][location] < loc_pow[1][location]) W[1]++;
    }
    
    if (W[0] == W[1]) {
    	if (T[0] > T[1]) cout << "Player 1" << ln;
    	else if (T[1] > T[0]) cout << "Player 2" << ln;
    	else cout << "Tie" << ln;
    }
    else if (W[0] > W[1]) {
    	cout << "Player 1" << ln;
    }
    else cout << "Player 2" << ln;
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
