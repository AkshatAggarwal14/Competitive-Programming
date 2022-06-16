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

const ll N = 1'00'00'000;
array<ll, N + 1> spf;
vector<ll> pr;
void fill() {
    for (ll i = 2; i <= N; ++i) {
        if (spf[i] == 0) {
            spf[i] = i;
            pr.push_back(i);
        }
        for (ll j = 0; j < (ll)pr.size() && pr[j] <= spf[i] && i * pr[j] <= N; ++j)
            spf[i * pr[j]] = pr[j];
    }
}

// Returns a vector containing all the prime factors of n (25 --> 5, 5)
vector<ll> prime_factorisation(ll n) {
    vector<ll> ans;
    while (n != 1) {
        ans.push_back(spf[n]);
        n /= spf[n];
    }
    return ans;
}

template <typename T, typename T_iterable>
vector<pair<T, ll>> compress(const T_iterable &items) {
    if (items.empty()) return {};
    vector<pair<T, ll>> encoded;
    ll count = 0;
    T last = items[0];
    for (const T &item : items) {
        if (item == last) {
            count++;
        } else {
            if (count) encoded.push_back({last, count});
            last = item, count = 1;
        }
    }
    if (count) encoded.push_back({last, count});
    return encoded;
}

// N = p1^a1 * p2^a2....         N mod p1 === 0
// let d1 = p1^a1               d1 mod p1 === 0
// d2 = N/d1                    d2 mod p1 !== 0
// d1 + d2 is not divisible by any prime factor of N
// gcd(p1^a1, p2^a2*p3...) === 1

void Solution() {
    ll n;
    cin >> n;
    vector<ll> a(n), d1(n), d2(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        auto C = compress<ll>(prime_factorisation(a[i]));
        if (sz(C) == 1)
            d1[i] = d2[i] = -1;
        else {
            d1[i] = static_cast<ll>(pow(C[0].first, C[0].second));
            d2[i] = a[i] / d1[i];
        }
    }
    for (ll &d : d1) cout << d << ' ';
    cout << '\n';
    for (ll &d : d2) cout << d << ' ';
    cout << '\n';
}

int main() {
    fill();
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}