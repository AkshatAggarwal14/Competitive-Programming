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

pair<ll, ll> eo(vector<ll> v) {
    ll e = 0, o = 0;
    for (ll i = 1; i < sz(v) - 1; ++i) {
        if (v[i] > v[i + 1] && v[i] > v[i - 1]) e++;
        if (v[i] < v[i + 1] && v[i] < v[i - 1]) o++;
    }
    return {e, o};  // hill, valley
}

void Solution() {
    ll n, a, b;
    cin >> n >> a >> b;
    ll a1 = a, b1 = b, ele;
    vector<ll> p(n, 0);
    if ((abs(a - b) > 1) || (a + b > n - 2)) return void(cout << -1 << '\n');
    if (a < b) {
        ele = 1;
        for (ll i = 1; i < n; i += 2) {
            p[i] = ele++;
            if (--b == 0) break;
        }
        for (ll i = 0; i < n; ++i)
            if (p[i] == 0) p[i] = ele++;
    } else if (a > b) {
        ele = n;
        for (ll i = 1; i < n; i += 2) {
            p[i] = ele--;
            if (--a == 0) break;
        }
        for (ll i = 0; i < n; ++i)
            if (p[i] == 0) p[i] = ele--;
    } else {
        ele = 1;
        for (ll i = 0; i <= 2 * a; i += 2)
            p[i] = ele++;
        for (ll i = 1; i <= 2 * a; i += 2)
            p[i] = ele++;
        for (ll i = 2 * a + 1; i < n; ++i) p[i] = ele++;
    }
    assert(eo(p) == make_pair(a1, b1));
    for (ll i = 0; i < n; ++i) cout << p[i] << ' ';
    cout << '\n';
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
    Solution();
    return 0;
}