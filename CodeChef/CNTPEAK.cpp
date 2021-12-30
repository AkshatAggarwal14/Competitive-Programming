#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
constexpr auto sz = [](const auto &container) -> ll { return ll(container.size()); };
#define all(x) (x).begin(), (x).end()
template <class T, class U = T>
constexpr bool amin(T &a, U &&b) { return b < a && (a = std::forward<U>(b), true); }
template <class T, class U = T>
constexpr bool amax(T &a, U &&b) { return a < b && (a = std::forward<U>(b), true); }
const ll MOD = 1e9 + 7;

void Solution() {
    // simulate the problem and generate all choices
    vector<vector<ll>> choices;
    ll n;
    cin >> n;
    auto rec = [&](const auto &self, vector<ll> &A) {
        if (sz(A) == n) {
            choices.push_back(A);
            return;
        }
        vector<ll> a(A), b(A), c(A);
        a.push_back(0);
        b.push_back(1);
        c.push_back(2);
        self(self, a);
        self(self, b);
        self(self, c);
    };
    vector<ll> X;
    rec(rec, X);
    auto f = [&](const vector<ll> &V) {
        ll res = 0;
        for (ll i = 1; i < n - 1; ++i)
            if ((V[i] > V[i - 1] && V[i] > V[i + 1]) || (V[i] < V[i - 1] && V[i] < V[i + 1]))
                res++;
        return res;
    };
    ll ans = 0;
    for (auto &x : choices) ans += f(x);
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    vector<ll> ans = {0, 0, 10, 60, 270, 1080, 4050, 14580, 51030, 174960};
    while (tc--) {
        // Solution();
        ll n;
        cin >> n;
        cout << ans[n - 1] << '\n';
    }
    return 0;
}