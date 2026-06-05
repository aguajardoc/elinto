// Problem: 1721 - Window Manager
// Contest: UVa Online Judge
// URL: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4794
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

int n, m;

struct Range {
    int L, R;
    Range(int _L, int _R) {
        L = _L, R = _R;
    }
    Range() {
        
    }
    
    bool overlap(const Range& oth) {
        return (not (oth.L >= R or oth.R <= L));
    }
};

struct Window {
    Range hor, vert;
    int idx;
    
    Window() {
        
    }
    Window(int x, int y, int w, int h, int _idx) {
        hor = Range(x, x + w);
        vert = Range(y, y + h);
        idx = _idx;
    }
    
    bool operator<(const Window& oth) {
        return idx < oth.idx;
    }
    
    bool operator==(const Window& oth) {
        return (idx == oth.idx);
    }
    
};

vector<Window> windows;

void print_error(int type, int idx, string command, int dp=0, int d=0) {
    cout << "Command " << idx << ": " << command << " - ";
    
    if (type == 0) {
        cout << "no window at given position" << ln;
    }
    else if (type == 1) {
        cout << "window does not fit" << ln;
    }
    else {
        cout << "moved " << abs(dp) << " instead of " << abs(d) << ln;
    }
}

bool extension_beyond(Window A) {
    return (A.hor.R > n or A.vert.R > m);
}

bool open(int x, int y, int w, int h, int idx, bool mes=1) {
    Window candidate(x, y, w, h, idx);
    
    if (extension_beyond(candidate)) {
        if (mes) print_error(1, idx, "OPEN");
        return false;
    }
    
    for (auto& W : windows) {
        if (W.hor.overlap(candidate.hor) and 
            W.vert.overlap(candidate.vert)) {
            if (mes) print_error(1, idx, "OPEN");
            return false;
        }
    }
    windows.pb(candidate);
    
    return true;
}

void close(int x, int y, int idx=-1) {
    vector<Window> new_windows;
    bool poss = false;
    for (Window& W : windows) {
        if (x >= W.hor.L and
            x < W.hor.R and
            y >= W.vert.L and
            y < W.vert.R
        ) {
            poss = true;
        }
        else {
            new_windows.pb(W);
        }
    }
    
    if (!poss) {
        print_error(0, idx, "CLOSE");
        return;
    }
    
    swap(windows, new_windows);
}

void resize(int x, int y, int w, int h, int idx=-1) {
    vector<Window> prev = windows;
    
    for (int i = 0; i < windows.size(); i++) {
        Window W = windows[i];
        if (x >= W.hor.L and
            x < W.hor.R and
            y >= W.vert.L and
            y < W.vert.R
        ) {
            
            close(x, y);
            if (!open(W.hor.L, W.vert.L, w, h, W.idx, 0)) {
                swap(windows, prev);
                print_error(1, idx, "RESIZE");
            }
            return;
        }
    }
    
    print_error(0, idx, "RESIZE");
}

bool touching(Window& A, Window& B, int dx, int dy) {
    if (dx > 0) {
        return (A.hor.R == B.hor.L and A.vert.overlap(B.vert));
    }
    if (dx < 0) {
        return (A.hor.L == B.hor.R and A.vert.overlap(B.vert));
    }
    if (dy > 0) {
        return (A.vert.R == B.vert.L and A.hor.overlap(B.hor));
    }
    if (dy < 0) {
        return (A.vert.L == B.vert.R and A.hor.overlap(B.hor));
    }
    
    return false;
}

int left_to_touch(Window& A, Window& B, int dx, int dy) {
    if (dx > 0) {
        if (A.vert.overlap(B.vert)) return B.hor.L - A.hor.R;
        return INF;
    }
    if (dx < 0) {
        if (A.vert.overlap(B.vert)) return A.hor.L - B.hor.R;
        return INF;
    }
    if (dy > 0) {
        if (A.hor.overlap(B.hor)) return B.vert.L - A.vert.R;
        return INF;
    }
    if (dy < 0) {
        if (A.hor.overlap(B.hor)) return A.vert.L - B.vert.R;
        return INF;
    }
    
    return INF;
}

void move(int x, int y, int dx, int dy, int idx=-1) {
    // TODO: redo move
    Window target;
    vector<Window> affected, new_windows;
    bool poss = false;
    for (Window& W : windows) {
        if (x >= W.hor.L and
            x < W.hor.R and
            y >= W.vert.L and
            y < W.vert.R
        ) {
            poss = true;
            target = W;
        }
        else new_windows.pb(W);
    }
    
    if (!poss) {
        print_error(0, idx, "MOVE");
        return;
    }
    
    windows = new_windows;
    vector<Window> moving = {target};
    bool kill = false;
    
    for (int i = 0; i < abs(dx) + abs(dy) and !kill; i++) {
        // Check touching
        vector<Window> new_moving = moving;
        bool action = true;
        
        while (action) {
            new_windows.clear();
            action = false;
            
            for (int j = 0; j < windows.size(); j++) {
                bool touches = false;
                for (int k = 0; k < moving.size(); k++) {
                    if (touching(moving[k], windows[j], dx, dy)) {
                        touches = true;
                        action = true;
                        
                        // add to moving
                        new_moving.pb(windows[j]);
                        break;
                    }
                    
                }
                
                if (!touches) {
                    new_windows.pb(windows[j]);
                }
            }
            
            moving = new_moving;
            windows = new_windows;
        }
        
        // Validate all moving
        for (int j = 0; j < moving.size(); j++) {
            bool dies = false;
            if (dx > 0) {
                if (moving[j].hor.R == n) dies = true;
            }
            if (dx < 0) {
                if (moving[j].hor.L == 0) dies = true;
            }
            if (dy > 0) {
                if (moving[j].vert.R == m) dies = true;
            }
            if (dy < 0) {
                if (moving[j].vert.L == 0) dies = true;
            }
            
            if (dies) {
                print_error(2, idx, "MOVE", i, abs(dx) + abs(dy));
                kill = true;
                break;
            }
        }
        
        if (kill) break;
        
        // Alter all in moving
        for (int j = 0; j < moving.size(); j++) {
            if (dx > 0) {
                // dbg(i);
                // dbg(j);
                // dbg(moving[j].hor.L);
                // dbg(moving[j].hor.R);
                moving[j].hor.L++;
                moving[j].hor.R++;
            }
            if (dx < 0) {
                moving[j].hor.L--;
                moving[j].hor.R--;
            }
            if (dy > 0) {
                moving[j].vert.L++;
                moving[j].vert.R++;
            }
            if (dy < 0) {
                moving[j].vert.L--;
                moving[j].vert.R--;
            }
        }
    }
    
    // dbg(moving.size());
    for (auto& w : moving) {
        windows.pb(w);
    }
    
    return;
}

void move_optimal(int x, int y, int dx, int dy, int idx=-1) {
    // TODO: redo move
    Window target;
    int add = 0;
    vector<Window> affected, new_windows;
    bool poss = false;
    for (Window& W : windows) {
        if (x >= W.hor.L and
            x < W.hor.R and
            y >= W.vert.L and
            y < W.vert.R
        ) {
            poss = true;
            target = W;
        }
        else new_windows.pb(W);
    }
    
    if (!poss) {
        print_error(0, idx, "MOVE");
        return;
    }
    
    windows = new_windows;
    vector<Window> moving = {target};
    bool kill = false;
    Window sentinel;
    if (dx > 0) {
        sentinel = Window(n, 0, INF, INF, INF);
    }
    if (dx < 0) {
        sentinel = Window(0, 0, 0, INF, INF);
    }
    if (dy > 0) {
        sentinel = Window(0, m, INF, INF, INF);
    }
    if (dy < 0) {
        sentinel = Window(0, 0, INF, 0, INF);
    }
    
    for (int i = 0; i < abs(dx) + abs(dy) and !kill; i++) {
        // Check touching
        vector<Window> new_moving = moving;
        bool action = true;
        
        int next = abs(dx) + abs(dy) - i;
        
        // dbg(i, next);
        
        while (action) {
            new_windows.clear();
            action = false;
            
            for (int j = 0; j < windows.size(); j++) {
                bool touches = false;
                for (int k = 0; k < moving.size(); k++) {
                    if (touching(moving[k], windows[j], dx, dy)) {
                        next = 0;
                        touches = true;
                        action = true;
                        
                        // add to moving
                        new_moving.pb(windows[j]);
                        break;
                    }
                    else {
                        if (left_to_touch(moving[k], windows[j], dx, dy) > 0) {
                            next = min(next, 
                                left_to_touch(moving[k], windows[j], dx, dy)
                            );
                        }
                    }
                    
                }
                
                if (!touches) {
                    new_windows.pb(windows[j]);
                }
            }
            
            moving = new_moving;
            windows = new_windows;
        }
        
        for (auto& j : moving) {
            next = min(next, abs(left_to_touch(j, sentinel, dx, dy)));
        }
        
        // Validate all moving
        for (int j = 0; j < moving.size(); j++) {
            bool dies = false;
            if (dx > 0) {
                if (moving[j].hor.R == n) dies = true;
            }
            if (dx < 0) {
                if (moving[j].hor.L == 0) dies = true;
            }
            if (dy > 0) {
                if (moving[j].vert.R == m) dies = true;
            }
            if (dy < 0) {
                if (moving[j].vert.L == 0) dies = true;
            }
            
            if (dies) {
                // dbg(i, next);
                print_error(2, idx, "MOVE", i, abs(dx) + abs(dy));
                kill = true;
                break;
            }
        }
        
        if (kill) break;
        
        // Alter all in moving
        if (!next) add++;
        for (int j = 0; j < moving.size(); j++) {
            if (next == 0) {
                if (dx > 0) {
                    // dbg(i);
                    // dbg(j);
                    // dbg(moving[j].hor.L);
                    // dbg(moving[j].hor.R);
                    moving[j].hor.L++;
                    moving[j].hor.R++;
                }
                if (dx < 0) {
                    moving[j].hor.L--;
                    moving[j].hor.R--;
                }
                if (dy > 0) {
                    moving[j].vert.L++;
                    moving[j].vert.R++;
                }
                if (dy < 0) {
                    moving[j].vert.L--;
                    moving[j].vert.R--;
                }
            }
            else {
                if (dx > 0) {
                    moving[j].hor.L+=next;
                    moving[j].hor.R+=next;
                }
                if (dx < 0) {
                    moving[j].hor.L-=next;
                    moving[j].hor.R-=next;
                }
                if (dy > 0) {
                    moving[j].vert.L+=next;
                    moving[j].vert.R+=next;
                }
                if (dy < 0) {
                    moving[j].vert.L-=next;
                    moving[j].vert.R-=next;
                }
            }
        }
        
        // dbg(next);
        if (next) i += next - 1;
    }
    
    // dbg(moving.size());
    for (auto& w : moving) {
        windows.pb(w);
    }
    
    return;
}

void solve() {
    cin >> n >> m;
    
    string command;
    int idx = 0;
    while(cin >> command) {
        idx++;
        
        if (command == "OPEN") {
            int x, y, w, h;
            cin >> x >> y >> w >> h;
            open(x, y, w, h, idx);
        }
        
        else if (command == "RESIZE") {
            int x, y, w, h;
            cin >> x >> y >> w >> h;
            resize(x, y, w, h, idx);
        }
        
        else if (command == "MOVE") {
            int x, y, w, h;
            cin >> x >> y >> w >> h;
            move_optimal(x, y, w, h, idx);
        }
        
        else if (command == "CLOSE") {
            int x, y;
            cin >> x >> y;
            close(x, y, idx);
        }
        else {
            sort(windows.begin(), windows.end());
            cout << windows.size() << " window(s):" << ln;
            for (Window& W : windows) {
                cout << W.hor.L << " " << W.vert.L << " " <<
                W.hor.R - W.hor.L << " " << 
                W.vert.R - W.vert.L << ln;
            }
            
            n = stoll(command);
            cin >> m;
            windows.clear();
            idx = 0;
        }
        
        // cout << "After command " << idx << ln;
        // for (Window& W : windows) {
            // cout << "index: " << ln;
            // cout << W.idx << ln << ln;
//             
            // cout << "H Range:" << ln;
            // cout << W.hor.L << " " << W.hor.R << ln;
            // cout << ln;
//             
            // cout << "V Range:" << ln;
            // cout << W.vert.L << " " << W.vert.R << ln;
            // cout << ln;
            // cout << ln;
        // } 
    }
        
    sort(windows.begin(), windows.end());
    cout << windows.size() << " window(s):" << ln;
    for (Window& W : windows) {
        cout << W.hor.L << " " << W.vert.L << " " <<
        W.hor.R - W.hor.L << " " << 
        W.vert.R - W.vert.L << ln;
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
