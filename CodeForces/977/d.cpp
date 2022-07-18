#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a) cin >> x;
    vector<array<ll, 3>> p;
    for (auto &x : a) {
        array<ll, 3> t = {x, 0, 0};
        while (x % 2 == 0) t[1]++, x /= 2;
        while (x % 3 == 0) t[2]++, x /= 3;
        p.push_back(t);
    }
    // as divide by 3 -> decreasing order
    // as multiply by 2 -> increasing order
    sort(p.begin(), p.end(), [](const auto &i, const auto &j) {
        if (i[2] > j[2]) return true;
        return i[1] < j[1];
    });
    for (auto &it : p) cout << it[0] << ' ';
    cout << '\n';
}