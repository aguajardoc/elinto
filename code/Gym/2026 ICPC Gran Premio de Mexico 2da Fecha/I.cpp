// Problem: I. I don't have the name I was supposed to have
// Contest: Codeforces - 2026 ICPC Gran Premio de Mexico 2da Fecha
// URL: https://codeforces.com/gym/106540/problem/I
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using namespace std;

#define ln '\n'
#define fast_cin() \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
#define lli ll
#define ld long double
#define pb push_back

const ll INF = LLONG_MAX/4;
const ld PI = acos(-1);
const double eps = 1e-9;

bool correct_chars(string& s) {
    for (auto& i : s) {
        if (isalnum(i)) continue;
        bool x = false;
        for (auto& c : {' ', '!', '?', '.', ',', ';', '$', '#', '^', '{', '}', '_', '=', '+', '*'}) {
            if (i == c) x = true;
        }
        if (!x) return false;
    }

    return true;
}

bool consec_spaces(string& s) {
    int n = s.length();

    for (int i = 1; i < n; i++) {
        if (s[i] == ' ' and s[i-1] == ' ') return false;
    }

    return true;
}

bool aux_digit(char c) {
    bool good = false;
    if (isalnum(c)) {
        good = true;
    }
    else {
        for (auto& x : {' ', '_', '^', '}', '{'}) {
            if (x == c) good = true;
        }
    }

    // cout << c << " " << good << ln;

    return good;
}

bool digit_surround(string& s) {
    int n = s.length();
    // cout << s << ln;
    for (int i = 0; i < n; i++) {
        if (!isdigit(s[i])) continue;

        bool poss = true;
        // cout << s[i] << " " << ln;
        // check right
        if (i) {
            char c = s[i-1];
            poss &= aux_digit(c);
        }

        // check left
        if (i != n - 1) {
            char c = s[i+1];
            poss &= aux_digit(c);
        }

        if (!poss) return false;
    }

    return true;
}

bool no_leading_zeros(string& s) {
    // if a zero, then next cant be another digit
    int n = s.length();
    bool have = false;

    for (int i = 0; i < n - 1; i++) {
        if (!have and s[i] == '0') {
            if (isdigit(s[i+1])) return false;
        }
        if (isdigit(s[i])) have = true;
        else have = false;
    }

    return true;
}

bool getalnum(string t) {
    for (auto& c : t) {
        // cout << c << " " << isalnum(c) << ln;
        if (!isalnum(c)) return false;
    }
    return true;
}

bool getdg(string t) {
    for (auto& c : t) {
        if (!isdigit(c)) return false;
    }
    return true;
}

bool brace_format(string& s) {
    vector<string> cont;

    string cur;
    bool has = false;
    // cout << s << ln;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            // cout << cur << ln;
            // cout << has << ln;
            if (has) cont.pb(cur);
            has = false;
            cur.clear();
        }
        else {
            cur += s[i];
            for (auto& c : {'_', '^', '{', '}'}) {
                if (s[i] == c) has = true;
            }
        }
    }

    // Extra checks
    for (auto& i : cont) {
        int n = i.length();
        for (int j = 0; j < n; j++) {
            if (i[j] == '_' or i[j] == '^') {
                if (j == 0) return false;
                if (j == n - 1) return false;

                if (i[j + 1] != '{') return false;
            }

            if (i[j] == '{') {
                if (j == 0) return false;
                if (i[j-1] != '_' and i[j-1] != '^') return false;
            }
        }
    }

    // Valid par and Check alnum for before, and digit check inside
    for (auto& i : cont) {
        int start = 0;
        bool bracket = false;
        int startbrack;
        
        int n = i.length();
        // cout << i << ln;
        for (int j = 0; j < n; j++) {
            if (i[j] == '_' or i[j] == '^') {
                // Check all previous
                if (j == 0) return false;
                // cout << i.substr(start, j - start);
                bool alnm = getalnum(i.substr(start, j - start));

                if (!alnm) return false;
            }
            if (i[j] == '{') {
                if (bracket) return false; // no nest!

                bracket = true;
                startbrack = j + 1;
            }
            if (i[j] == '}') {
                if (!bracket) return false; // cant
                bracket = false;

                bool dig = getdg(i.substr(startbrack, j - startbrack));
                start = j + 1;

                if (!dig) return false;
            }
        }

        if (bracket) return false;
    }

    return true;
}

bool valid(string& s) {
    // Only letters, digits, spaces, and special symbols
    if (!correct_chars(s)) return false;

    // No leading or trailing space
    if (s.front() == ' ' or s.back() == ' ') return false;

    // Exact X_{Y} or X^{Y} format
    // X is an integer or alphanumeric
    // Y is an integer
    // No nesting
    if (!brace_format(s)) return false;

    // Every digit is surrounded by other digits, letters or spaces or scripts
    if (!digit_surround(s)) return false;

    // Numbers dont have leading zeros
    if (!no_leading_zeros(s)) return false;

    // No consecutive spaces
    if (!consec_spaces(s)) return false;

    // YIPPIEEEEE
    return true;
}

void solve() {
    int n;
    cin >> n;
    cin.ignore();

    bool poss = true;
    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        poss &= valid(s);
        // cout << s << ln;
        // cout << valid(s) << ln;
        // cout << ln;
    }

    cout << (poss ? "Ok":"Validation failed") << ln;
}

int main() {
    fast_cin();

    int T = 1;
    for (int i = 1; i <= T; i++) {
        solve();
    }

    return 0;
}