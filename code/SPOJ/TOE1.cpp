// Problem: Tic-Tac-Toe ( I )
// Contest: SPOJ - Classical
// URL: https://www.spoj.com/problems/TOE1/
// Memory Limit: 1536 MB
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
	vector<string> grid;
	bool turn = 0; // 0: X, 1: O
	
	State() {
		// Llenar matriz con '.'
		grid.resize(3);
		for (int i = 0; i < 3; i++) {
			grid[i] = string(3, '.');
		}
	}
	
};

// Global para usarlo en todos los test cases
set<vector<string>> visited;

bool win(State& v) {
	// Ganas si hay tres seguidos...
	// En fila
	for (int i = 0; i < 3; i++) {
		if (v.grid[i][0] == '.') continue;
		if (v.grid[i][0] == v.grid[i][1] and
		    v.grid[i][0] == v.grid[i][2]) {
		    	return true;
		    }
	}
	
	// En columna
	for (int i = 0; i < 3; i++) {
		if (v.grid[0][i] == '.') continue;
		if (v.grid[0][i] == v.grid[1][i] and
		    v.grid[0][i] == v.grid[2][i]) {
		    	return true;
		    }
	}
	
	// En diagonal
	if (v.grid[1][1] == '.') return false;
	
	if (v.grid[0][0] == v.grid[1][1] and
	    v.grid[0][0] == v.grid[2][2]) {
	    	return true;
	    }
	
	if (v.grid[0][2] == v.grid[1][1] and
	    v.grid[0][2] == v.grid[2][0]) {
	    	return true;
	    }
	
	
	// Si no, no hemos ganado
	return false;
}

void precalc() {
	// Definir estado inicial
	State start;
	
	// Recorrer todos los posibles estados
	queue<State> q;
	
	visited.insert(start.grid);
	q.push(start);
	
	while (!q.empty()) {
		State u = q.front();
		q.pop();
		
		// Transición: 
		// poner uno del turno actual, donde sea
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				// Si ya hay algo, no
				if (u.grid[i][j] != '.') continue;
				
				// Si ya llegamos a ese estado, ignorar
				State v = u;
				v.grid[i][j] = (v.turn ? 'O':'X'); // Settear valor
				v.turn = 1 - v.turn; // Cambiar turno
				
				if (visited.count(v.grid)) continue;
				visited.insert(v.grid);
				
				// Si ya gané, no reviso sus transiciones
				if (!win(v)) {
					q.push(v);
				}
			}
		}
		
	}
}

void solve() {
    State x;
    // Input del estado que quiero revisar
    for (int i = 0; i < 3; i++) {
    	cin >> x.grid[i];
    }
    
    // más ternarios porque sí
    cout << (visited.count(x.grid) ? "yes":"no") << ln;
}

signed main() {
    fast_cin();
    
    // Precalcular estados accesibles
    precalc();
    
    // Procesar casos de prueba
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
