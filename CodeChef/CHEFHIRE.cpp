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

struct Details {
    string name;
    ll academic, other;
    Details() = default;
    Details(string name_, ll academic_, ll other_)
        : name(name_), academic(academic_), other(other_) {}
    bool operator<(const Details &o) const { return academic < o.academic; }
};

void Solution() {
    ll n;
    cin >> n;
    vector<Details> A(n);
    for (auto &[s, a, o] : A) cin >> s >> a >> o;
    stable_sort(A.rbegin(), A.rend());
    for (auto &[s, a, o] : A) cout << s << ' ' << a << ' ' << o << '\n';
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
    while (tc--) {
        Solution();
    }
    return 0;
}