// #include "Akshat.hpp"
#include "bits/stdc++.h"
using namespace std;
using ll = int64_t;

void Solution() {
    ll a, b;
    cin >> a >> b;
    if (a) {
        if (b)
            cout << "Solution\n";
        else
            cout << "Solid\n";
    } else
        cout << "Liquid\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll tc;
    cin >> tc;
    while (tc--)
        Solution();
    cerr << fixed << setprecision(4) << (double)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}