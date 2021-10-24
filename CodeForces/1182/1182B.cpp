// #include "Akshat.hpp"
#include "bits/stdc++.h"
using namespace std;
using ll = int64_t;

void Solution() {
    ll h, w;
    cin >> h >> w;
    vector<vector<char>> vv(h + 2, vector<char>(w + 2, '.'));
    vector<vector<ll>> mark(h + 2, vector<ll>(w + 2, 0));
    for (ll i = 1; i <= h; ++i) {
        for (ll j = 1; j <= w; ++j) {
            cin >> vv[i][j];
        }
    }
    bool flag = false;
    for (ll i = 1; i <= h; ++i) {
        for (ll j = 1; j <= w; ++j) {
            if (vv[i][j] == '*' && vv[i][j + 1] == '*' && vv[i + 1][j] == '*' && vv[i - 1][j] == '*' && vv[i][j - 1] == '*') {
                flag = true;
                ll I = i, J = j;
                mark[I][J] = 1;
                while (I <= h && vv[I][J] == '*') {
                    mark[I][J] = 1;
                    I++;
                }
                I = i, J = j;
                while (I >= 1 && vv[I][J] == '*') {
                    mark[I][J] = 1;
                    I--;
                }
                I = i, J = j;
                while (J >= 1 && vv[I][J] == '*') {
                    mark[I][J] = 1;
                    J--;
                }
                I = i, J = j;
                while (J <= w && vv[I][J] == '*') {
                    mark[I][J] = 1;
                    J++;
                }
                goto last;
            }
        }
    }
last:
    for (ll i = 1; i <= h; ++i) {
        for (ll j = 1; j <= w; ++j) {
            if (vv[i][j] == '*' && mark[i][j] != 1) {
                return void(cout << "NO\n");
            }
        }
    }
    cout << (flag ? "YES\n" : "NO\n");
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Solution();
    return 0;
}