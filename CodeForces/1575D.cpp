#include "bits/stdc++.h"
using namespace std;
using ll = int64_t;
#define fo(i, n) for (ll i = 0; i < n; i++)
#define sz(x) ((ll)(x).size())

// ---------------------------------<Solve>-------------------------------

void Solution() {
    string s;
    cin >> s;
    ll n = s.length();
    if (s == "0" || s == "X" || s == "_") return void(cout << 1 << '\n');
    if (n == 1) return void(cout << 0 << '\n');
    // now n >= 2 && n <= 8
    string bak = s.substr(n - 2);
    string frnt = s.substr(0, n - 2);

    ll ans = 1;
    fo(i, sz(frnt)) {
        if (s[i] == '_') {
            if (i == 0)
                ans *= 9;
            else
                ans *= 10;
        }
    }
    ll it = frnt.find('X');
    bool yes_f = (it == 0);
    bool yes = (it != -1);
    bool no = (it == -1);
    bool nothin = (frnt == "");
    // dbg(ans);
    cerr << ans << '\n';
    // 25 75 50 00
    if (bak == "__") {
        if (nothin)
            ans *= 3;
        else {
            ans *= 4;
            if (yes_f)
                ans *= 9;
            else if (yes)
                ans *= 10;
        }
        cout << ans;
    } else if (bak == "_X") {
        if (nothin)
            ans *= 3;
        else {
            ans *= 2;
            if (yes_f)
                ans *= 1;
            else if (yes || no)
                ans *= 2;
        }
        cout << ans;
    } else if (bak == "X_") {
        if (nothin)
            ans *= 3;
        else {
            if (yes_f)
                ans *= 3;  //25 75 50
            else if (yes || no)
                ans *= 4;
        }
        cout << ans;
    } else if (bak == "XX") {
        if (nothin)
            ans = 0;
        else {
            // so XX can be 00
            if (yes_f)
                ans = 0;
            else if (yes || no) {
            }
        }
        cout << ans;
    } else if (bak[0] == '_') {
        if (yes_f)
            ans *= 9;
        else if (yes)
            ans *= 10;
        if (bak[1] == '5') {
            ans *= 2;  //25 75
            cout << ans;
        } else if (bak[1] == '0') {
            if (nothin) {
            } else
                ans *= 2;  // 00 50
            cout << ans;
        } else {
            ans = 0;
            cout << ans;
        }
    } else if (bak[1] == '_') {
        if (yes_f)
            ans *= 9;
        else if (yes)
            ans *= 10;  // Xs in frnt
        if (bak[0] == '2' || bak[0] == '5' || bak[0] == '7' || bak[0] == '0') {
        } else
            ans = 0;
        cout << ans;
    } else if (bak[0] == 'X') {
        if (bak[1] == '0') {  // X0
            if (nothin) {
                ans = 1;
            } else {
                if (yes_f) {
                } else if (yes || no)
                    ans *= 2;
            }
            cout << ans;
        } else if (bak[1] == '5') {  // X5
            ans *= 2;                // bcoz of X
            cout << ans;
        } else
            cout << 0;
    } else if (bak[1] == 'X') {
        if (bak[0] == '2' || bak[0] == '7') {  // 2X
            cout << ans;
        } else if (bak[0] == '5' || bak[0] == '0') {  // 5X
            if (yes_f) ans = 0;                       // 0X now as frnt cant be empty
            cout << ans;
        } else
            cout << 0;
    } else if (bak == "25" || bak == "75" || bak == "50" || bak == "00") {
        if (yes_f)
            ans *= 9;
        else if (yes)
            ans *= 10;
        cout << ans;
    } else
        cout << 0;
    cout << '\n';
}

// --------------------------------</Solve>-------------------------------

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
    ll tc = 1;
    cin >> tc;
    while (tc--)
        Solution();
    return 0;
}

// --------------------------------</Testcase>------------------------------

/*
56
X6
6X
0
X
_
__
X__
___
_X__
9_X__
_X
X_X
__X
_X_X
9_X_X
X_
X_X_
_X_
_XX_
9_XX_
XX
X_XX
_XX
_XXX
9_XXX
XXX_0
XXX_5
XX_2
XX2_
XX5_
XX7_
XX0_
XX3_
X_X0
_X0
_XX0
X5
X2
X7
7X
2X
X5X
5X
__5X
90X
_0X
X0X
1X73
1_X25
1X50
1_X75
X75
X__0
343
_X_X_X_0
XXXXXX
*/