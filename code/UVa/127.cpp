// Problem: 127 - "Accordian" Patience
// Contest: UVa Online Judge
// URL: https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=63
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

const ll INF = LLONG_MAX / 4;
const ld PI = acos(-1);
const int MOD = 1000000007;
const double eps = 1e-9;


bool match(string a, string b) {
	return (a[0] == b[0] or a[1] == b[1]);
}

void solve() {
	string card1;
	while (cin >> card1){
		if (card1[0] == '#') break;
	    vector<string> cards(52);
	    cards[0] = card1;
	    
	    for (int i = 1; i < 52; i++) cin >> cards[i]; 
		
		vector<stack<string>> game;
		
		for (int i = 0; i < 52; i++) {
			// Deal a card
			stack<string> newCard;
			newCard.push(cards[i]);
			game.pb(newCard);
		}
			
		// While a move can be made, make it and reiterate
		bool validMove = true;
		while (validMove) {
			validMove = false;
			
			for (int j = 0; j < game.size(); j++) {
				bool m1 = false, m3 = false;
				
				if (j >= 1) {
					if (match(game[j - 1].top(), game[j].top())) m1 = true;
				}
				if (j >= 3) {
					if (match(game[j - 3].top(), game[j].top())) m3 = true;
				}
				
				if (m3) {
					game[j-3].push(game[j].top());
					game[j].pop();
					if (game[j].empty()) game.erase(game.begin() + j);
					validMove = true;
					j -= 3;
					break;
				}
				else if (m1) {
					game[j-1].push(game[j].top());
					game[j].pop();
					if (game[j].empty()) game.erase(game.begin() + j);
					validMove = true;
					j--;
					break;
				}
			}
			
		}
		
		
		int p = game.size();
		cout << p << " pile" << (p == 1 ? " ":"s ") << "remaining: ";
		for (int i = 0; i < p; i++) {
			cout << game[i].size();
			if (i != p - 1) cout << " ";
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
