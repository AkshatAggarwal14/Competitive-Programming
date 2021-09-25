#ifndef ONLINE_JUDGE
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#define debug(...)
#endif

using ll = int64_t;
#define fo(i, n) for (ll i = 0; i < n; i++)
#define sz(x) ((ll)(x).size())
const double eps = 1e-12;
const double PI = acos(-1);

int n;
void rotate_grid(vector<vector<char>> &grid) {
    vector<vector<char>> mat(n, vector<char>(n));
    for (int j = 0, a = 0; j < n; j++, a++)
        for (int i = n - 1, b = 0; i >= 0; i--, b++)
            mat[a][b] = grid[i][j];
    grid = mat;
}

vector<vector<char>> flip_vertical(vector<vector<char>> &grid) {
    vector<vector<char>> mat(n, vector<char>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            mat[i][j] = grid[i][n - 1 - j];
        }
    }
    return mat;
}

vector<vector<char>> flip_horizontal(vector<vector<char>> grid) {
    vector<vector<char>> mat(n, vector<char>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            mat[i][j] = grid[n - 1 - i][j];
        }
    }
    return mat;
}

void Solution() {
    cin >> n;
    vector<vector<char>> m1(n, vector<char>(n)), m2(n, vector<char>(n));
    fo(i, n) fo(j, n) cin >> m1[i][j];
    fo(i, n) fo(j, n) cin >> m2[i][j];
    vector<vector<vector<char>>> vv, choices;
    vv.push_back(m2);
    fo(i, 3) {
        rotate_grid(m2);
        vv.push_back(m2);
    }
    for (vector<vector<char>> &V : vv) {
        choices.push_back(V);
        choices.push_back(flip_vertical(V));
        choices.push_back(flip_horizontal(V));
        choices.push_back(flip_horizontal(flip_vertical(V)));
    }
    for (vector<vector<char>> &X : choices) {
        if (X == m1) {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
#ifdef NCR
    init();
#endif
    ll tc = 1;
    //cin >> tc;
    for (ll i = 1; i <= tc; ++i) {
        // cout << "Case #" << i << ": ";
        Solution();
    }
    return 0;
}