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

vector<string> mat(5);

void solve() {
    for (int i = 0; i < 5; i++) {
        cin >> mat[i];
    }
    
    // get rows
    bool rowA = false, rowB = false;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            string t = mat[i].substr(j, 3);
            if (t == "AAA") rowA = true;
            if (t == "BBB") rowB = true;
        }
    }
    
    // get cols
    bool colA = false, colB = false;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            string t;
            t += mat[j][i];
            t += mat[j+1][i];
            t += mat[j+2][i];
            
            if (t == "AAA") colA = true;
            if (t == "BBB") colB = true;
        }
    }
    
    vector<vector<pair<int, int>>> coordDiag  = {
        {{2, 0}, {3, 1}, {4, 2}},
        {{1, 0}, {2, 1}, {3, 2}, {4, 3}},
        {{0, 0}, {1, 1}, {2, 2}, {3, 3}, {4, 4}},
        {{0, 1}, {1, 2}, {2, 3}, {3, 4}},
        {{0, 2}, {1, 3}, {2, 4}},

        {{4, 2}, {3, 3}, {2, 4}},
        {{4, 1}, {3, 2}, {2, 3}, {1, 4}},
        {{4, 0}, {3, 1}, {2, 2}, {1, 3}, {0, 4}},
        {{3, 0}, {2, 1}, {1, 2}, {0, 3}},
        {{2, 0}, {1, 1}, {0, 2}},
    };
    
    
    bool diagA = false, diagB = false;
    for (auto& i : coordDiag){
        string t;
        for (auto& [x, y] : i) {
            t += mat[x][y];
        }
        
        int m = t.length();
        m -= 2;
        for (int j = 0; j < m; j++) {
            string t2 = t.substr(j, 3);
            
            if (t2 == "AAA") diagA = true;
            if (t2 == "BBB") diagB = true;
        }
    }
    
    bool ansA = rowA or colA or diagA;
    bool ansB = rowB or colB or diagB;
    
    
    if (!(ansA ^ ansB)) {
        cout << "draw" << ln;
    }
    else if (ansA) {
        cout << "A wins" << ln;
    }
    else cout << "B wins" << ln;
    
    
}

signed main() {
    fast_cin();
    
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(  );
    }

    return 0;
}
// g++ A.cpp && ./a.out <input.in>output.out
