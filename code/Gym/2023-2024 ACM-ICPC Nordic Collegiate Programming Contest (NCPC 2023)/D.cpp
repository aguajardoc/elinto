// Problem: D. Die Hard
// Contest: Codeforces - 2023-2024 ACM-ICPC Nordic Collegiate Programming Contest (NCPC 2023)
// URL: https://codeforces.com/gym/105427/problem/D
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

void solve() {
    vector<vector<int>> dice(3, vector<int>(6, 0));
    
    for (int i = 0; i < 3; i++) {
    	for (int j = 0; j < 6; j++) {
    		cin >> dice[i][j];
    	}
    }
    
	for(int i = 0; i<3; i++){
		int victoryroyale = 0;
		for(int j = 0; j<3; j++){
			if(i==j) continue;
			int gano = 0;
			int tot = 0;
			for(int ii = 0; ii<6; ii++){
				for(int jj = 0; jj < 6; jj++){
					if(dice[i][ii] == dice[j][jj]) continue;
					tot++;
					if(dice[i][ii] > dice[j][jj]) gano++;
				}
			}
			if(2*gano >= tot && tot>0) victoryroyale++;
		}
		if(victoryroyale == 2){
			cout << i+1 << '\n';
			return;
		}
	}
	
	cout << "No dice" << '\n';
	return;
    
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
