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
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll &A : a) cin >> A;
    set<ll> odds;
    ll operations = 0;
    for (ll _ = 0; _ < 3; ++_) {  //? why 3 iterations work but 2 dont
        odds.clear();
        for (ll i = 1; i < n - 1; ++i)
            if (a[i] & 1) odds.insert(i);
        for (ll i = 1; i < n - 1; ++i) {
            auto nxt = odds.upper_bound(i);
            while (a[i] >= 2 && nxt != odds.end()) {
                a[i] -= 2;
                operations++;
                a[0]++;
                a[*nxt]++;
                nxt = odds.erase(nxt);
            }
        }
        dbg(a);
        reverse(all(a));
        if (odds.empty()) break;
    }
    for (ll i = 1; i < n - 1; ++i) {
        if (a[i] & 1) return void(cout << "-1\n");
        operations += a[i] / 2;
    }
    cout << operations << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}