// Problem: 101 - The Blocks Problem
// Contest: UVa Online Judge
// URL: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=37
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

void print(vector<vector<int>>& state) {
	for (int i = 0; i < state.size(); i++) {
		cout << i << ":";
		for (int& j : state[i]) {
			cout << " " << j;
		}
		cout << ln;
	}
}

pair<int, int> find(int x, vector<vector<int>>& state) {
	for (int i = 0; i < state.size(); i++) {
		for (int j = 0; j < state[i].size(); j++) {
			if (state[i][j] == x) return {i, j};
		}
	}
	
	return {-1, -1};
}

void returnToInitial(pair<int, int> last, vector<vector<int>>& state) {
	last.second++;
	int x = 0;
	for (int i = last.second; i < (int)state[last.first].size(); i++,x++) {
		// dbg(i);
		state[state[last.first][i]].push_back(state[last.first][i]);
	}

	for (int i = 0; i < x; i++) state[last.first].pop_back();
}

void move(pair<int, int> start, pair<int, int> goal, vector<vector<int>>& state) {
	vector<int> toMove;
	for (int i = start.second; i < (int)state[start.first].size(); i++) {
		toMove.push_back(state[start.first][i]);
	}
	
	state[goal.first].insert(state[goal.first].end(), toMove.begin(), toMove.end());
	
	for (int i = 0; i < toMove.size(); i++) state[start.first].pop_back();
}

void moveOnto(int a, int b, vector<vector<int>>& state) {
	// Find a
	pair<int, int> aLoc = find(a, state);
	// Find b
	pair<int, int> bLoc = find(b, state);
	if (aLoc.first == bLoc.first) return;
	// Return blocks on top of a to initial position
	returnToInitial(aLoc, state);
	// Return blocks on top of b to initial position
	returnToInitial(bLoc, state);
	// Move a to b's position
	move(aLoc, bLoc, state);
}

void moveOver(int a, int b, vector<vector<int>>& state) {
	// Find a
	pair<int, int> aLoc = find(a, state);
	// Find b
	pair<int, int> bLoc = find(b, state);
	if (aLoc.first == bLoc.first) return;
	// Return blocks on top of a to initial position
	returnToInitial(aLoc, state);	
	// Move a to b's position
	move(aLoc, bLoc, state);	
}

void pileOnto(int a, int b, vector<vector<int>>& state) {
	// Find a
	pair<int, int> aLoc = find(a, state);
	// Find b
	pair<int, int> bLoc = find(b, state);
	if (aLoc.first == bLoc.first) return;
	// Return blocks on top of b to initial position
	returnToInitial(bLoc, state);	
	// Move all from a to top of stack onto b
	move(aLoc, bLoc, state);	
}

void pileOver(int a, int b, vector<vector<int>>& state) {
	// Find a
	pair<int, int> aLoc = find(a, state);
	// Find b
	pair<int, int> bLoc = find(b, state);
	if (aLoc.first == bLoc.first) return;
	// Move all from a top top of stack over b's stack
	move(aLoc, bLoc, state);	
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> state(n);
    for (int i = 0; i < n; i++) {
    	state[i] = {i};
    }
    while(true) {
    	string s, t;
    	int a, b;
    	cin >> s;
    	if (s == "quit") {
    		print(state);
    		break;
    	}
    	else {
    		cin >> a >> t >> b;
    		string instruction;
    		instruction += s + ' ' + t;
    		
    		if (instruction == "move onto") {
    			moveOnto(a, b, state);
    		}
    		if (instruction == "move over") {
    			moveOver(a, b, state);
    		}
    		if (instruction == "pile onto") {
    			pileOnto(a, b, state);
    		}
    		if (instruction == "pile over") {
    			pileOver(a, b, state);
    		}    		    		    		
    	}
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
