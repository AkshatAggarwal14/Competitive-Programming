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

ll LIS(vector<ll> &arr) {
    vector<ll> ans;
    ll n = sz(arr);
    for (ll i = 0; i < n; i++) {
        auto it = lower_bound(ans.begin(), ans.end(), arr[i]);
        if (it == ans.end()) {
            ans.push_back(arr[i]);
        } else {
            *it = arr[i];
        }
    }
    return sz(ans);
}

void Brute(ll n) {
    vector<ll> p(n);
    iota(all(p), 1);
    ll c1 = 0, c2 = 0;
    do {
        vector<ll> pr(all(p));
        reverse(all(pr));
        dbg(LIS(p), LIS(pr));
        if (LIS(p) != LIS(pr)) {
            c1++;
            continue;
        }
        c2++;
        cout << n << ": ";
        for (ll &x : p) cout << x << ' ';
        cout << '\n';
    } while (next_permutation(all(p)));
    cout << c1 << ' ' << c2 << '\n';
}
/*
odd: 1 2 3 4 9 8 7 6 5
even: 5 4 3 2 1 10 6 7 8 9
*/

void Solution() {
    ll n;
    cin >> n;
    vector<ll> p;
    if (n & 1) {
        for (ll i = 1; i <= n / 2; ++i) p.push_back(i);
        p.push_back(n);
        for (ll i = n - 1; i > n / 2; --i) p.push_back(i);
    } else {
        if (n == 2) return void(cout << "NO\n");
        for (ll i = n / 2; i >= 1; --i) p.push_back(i);
        p.push_back(n);
        for (ll i = n / 2 + 1; i < n; ++i) p.push_back(i);
    }
    vector<ll> pr(all(p));
    reverse(all(pr));
    dbg(p);
    // assert(LIS(p) == LIS(pr));
    cout << "YES\n";
    for (ll &x : p) cout << x << ' ';
    cout << '\n';
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