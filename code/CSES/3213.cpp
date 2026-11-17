// Problem: Water Containers Moves
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/3213
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

struct State {
	int water_moved = 0, a = 0, b = 0, moves = 0;
	
	State(int w, int a, int b, int m) : water_moved(w), a(a), b(b), moves(m) {} 
	
	bool operator<(const auto& oth) const {
		return make_pair(water_moved, moves) < make_pair(oth.water_moved, oth.moves);
	}
	
	bool operator>(const auto& oth) const {
		return make_pair(water_moved, moves) > make_pair(oth.water_moved, oth.moves);
	}
};

int dist[1001][1001], moves[1001][1001], parent_move[1001][1001], prev_a[1001][1001], prev_b[1001][1001];

int fill(int& water, int limit) {
	if (limit == water) return 0;
	int moved = limit - water;
	water = limit;
	return moved;
}

int empty(int& water) {
	if (!water) return 0;
	int moved = water;
	water = 0;
	return moved;
}

int move(int& from_water, int& to_water, int to_cap) {
	if (to_cap == to_water) return 0;
	if (from_water == 0) return 0;
	
	int space = to_cap - to_water;
	int moved = min(space, from_water);
	
	from_water -= moved;
	to_water += moved;
	return moved;
}

string move_map[6] = {
	"FILL A", "FILL B",
	"EMPTY A", "EMPTY B",
	"MOVE A B", "MOVE B A"				
};

void solve() {
    int a, b, x; cin >> a >> b >> x;
    if (x % gcd(a, b) != 0 or a < x) {
    	cout << -1 << ln;
    	return;
    }
    
    dist[0][0] = 0;
    moves[0][0] = 0;
    State start(0, 0, 0, 0);
    priority_queue<State, vector<State>, greater<State>> pq;
    pq.push(start);
    
    while (!pq.empty()) {
    	State u = pq.top();
    	pq.pop();
    	
    	if (dist[u.a][u.b] < u.water_moved) continue;
    	
    	for (int i = 0; i < 6; i++) {
    		State v = u;
    		int change = 0;
    		
    		// FILL MOVES
    		if (i == 0) change = fill(v.a, a);
    		if (i == 1) change = fill(v.b, b);
    			
    		// EMPTY MOVES
    		if (i == 2) change = empty(v.a);
    		if (i == 3) change = empty(v.b);
    		
    		// TRANSFER MOVES
    		if (i == 4) change = move(v.a, v.b, b);
    		if (i == 5) change = move(v.b, v.a, a);
    		
    		if (change) {
    			if (u.water_moved + change < dist[v.a][v.b]) {
					v.water_moved += change;
					v.moves++;
					dist[v.a][v.b] = v.water_moved;
					moves[v.a][v.b] = v.moves;
					parent_move[v.a][v.b] = i;
					prev_a[v.a][v.b] = u.a;
					prev_b[v.a][v.b] = u.b;
					pq.push(v);
				}
    		}
    	}
    }
    
    int water_moved = INF;
    int best_b = 0;
    for (int i = 0; i <= b; i++) {
    	if (dist[x][i] < water_moved) {
    		water_moved = dist[x][i];
    		best_b = i;
    	}
    }
    
    if (water_moved == INF) {
    	cout << -1 << ln;
    	return;
    }
    
    cout << moves[x][best_b] << " " << dist[x][best_b] << ln;
    vector<string> moves_performed;
    while (parent_move[x][best_b] != -1) {
    	int move_idx = parent_move[x][best_b];
    	moves_performed.pb(move_map[move_idx]);
    	
    	int nx = prev_a[x][best_b];
    	int nb = prev_b[x][best_b];
    	
    	x = nx, best_b = nb;
    }
    
    reverse(moves_performed.begin(), moves_performed.end());
    for (auto& i : moves_performed) {
    	cout << i << ln;
    }
}

signed main() {
    fast_cin();
    fill_n(&dist[0][0], 1001*1001, INF);
    fill_n(&moves[0][0], 1001*1001, 0);
    fill_n(&parent_move[0][0], 1001*1001, -1);
    fill_n(&prev_a[0][0], 1001*1001, -1);
    fill_n(&prev_b[0][0], 1001*1001, -1);
    
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
