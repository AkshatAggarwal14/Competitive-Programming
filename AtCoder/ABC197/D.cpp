#ifndef ONLINE_JUDGE
// https://github.com/AkshatAggarwal14/Competetive-Programming/tree/master/CodeForces
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = int64_t;
auto sz = [](const auto &container) -> ll { return container.size(); };

void Solution() {
    // https://math.stackexchange.com/questions/1267646/finding-vertices-of-regular-polygon
    // matrix exponentation and recentering shit
    ll n;
    cin >> n;
    double x0, y0, x2, y2;
    cin >> x0 >> y0 >> x2 >> y2;
    double cx = (x0 + x2) / 2;  //centre
    double cy = (y0 + y2) / 2;
    x0 -= cx;
    y0 -= cy;
    double theta = 2.0 * acos(-1) / (double(n));
    double ax, ay;
    ax = x0 * cos(theta) - y0 * sin(theta);
    ay = x0 * sin(theta) + y0 * cos(theta);
    ax += cx;
    ay += cy;
    cout << ax << ' ' << ay << '\n';
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    // ll tc; cin >> tc; while (tc--)
    Solution();
    cerr << "Time:" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}