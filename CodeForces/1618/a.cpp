#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = int64_t;
auto sz = [](const auto &container) -> ll { return container.size(); };
#define all(x) (x).begin(), (x).end()
template <class T, class U = T>
bool amin(T &a, U &&b) { return b < a ? a = std::forward<U>(b), true : false; }
template <class T, class U = T>
bool amax(T &a, U &&b) { return a < b ? a = std::forward<U>(b), true : false; }

vector<ll> gen(vector<ll> a) {
    vector<ll> res;
    res.push_back(a[0]);
    res.push_back(a[1]);
    res.push_back(a[2]);
    res.push_back(a[0] + a[1]);
    res.push_back(a[0] + a[2]);
    res.push_back(a[1] + a[2]);
    res.push_back(a[1] + a[2] + a[0]);
    sort(all(res));
    return res;
}

void Solution() {
    vector<ll> a(7);
    for (ll &x : a) cin >> x;
    vector<ll> b(a);
    do {
        for (ll j = 0; j <= 4; ++j) {
            vector<ll> temp = {a[j], a[j + 1], a[j + 2]};
            if (gen(temp) == b) {
                for (ll &x : temp) cout << x << ' ';
                cout << '\n';
                return;
            }
        }
    } while (next_permutation(all(a)));
}

// ---------------------------------------------------------------------------
void Better() {
    vector<ll> a(7);
    for (ll &x : a) cin >> x;
    cout << a[0] << ' ' << a[1] << ' ' << a[6] - a[0] - a[1] << '\n';
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    ll tc; cin >> tc; while (tc--)
    Better();
    return 0;
}