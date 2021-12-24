#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = int64_t;
auto sz = [](const auto &container) -> ll { return ll(container.size()); };
#define all(x) (x).begin(), (x).end()
template <class T, class U = T>
bool amin(T &a, U &&b) { return b < a && (a = std::forward<U>(b), true); }
template <class T, class U = T>
bool amax(T &a, U &&b) { return a < b && (a = std::forward<U>(b), true); }
const int MOD = 1e9 + 7;

const ll N = 2'00'000;
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

bool isPrime(ll n) {
    assert(n >= 0 && n <= N);
    return (spf[n] == n);
}

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

/*
10 24 40 80
2*5, 2^3*3, 2^3*5, 2^4*5

2: 1 3 3 4
3: 1 
5: 1 1 1

So each number is divisible by a pf, then A * B is divisble by atleast the second smallest power
if n - 1 numbers are divisible by a pf, then A * B is divisible by atleast the smallest power.
*/

void Solution() {
    ll n;
    cin >> n;
    vector<ll> A(n);
    map<ll, priority_queue<ll, vector<ll>, greater<ll>>> pq;  // primes, {powers}
    for (auto &a : A) {
        cin >> a;
        auto C = compress<ll>(prime_factorisation(a));  // compressed
        for (auto &[x, y] : C) pq[x].push(y);           // {num, freq} pushed
    }
    ll res = 1;
    for (auto &[x, y] : pq) {
        // pop smallest if sz == n
        if (sz(y) == n) y.pop();
        // multiply smallest for sz == n - 1
        if (sz(y) == n - 1) res *= static_cast<ll>(pow(x, y.top()));
    }
    cout << res << '\n';
}

//! -----------------------------------------------------------------------------

void Shorter() {
    // lcm and gcd distribute over each other:
    // gcd(lcm(a1, a2), lcm(a1, a3) ... lcm(a1, an)) = lcm(a1, gcd(a2, a3 ... an)) and
    // lcm(gcd(a1, a2), gcd(a1, a3) ... gcd(a1, an)) = gcd(a1, lcm(a2, a3 ... an))
    // ans = gcd(lcm(a1, gcd(a2 .. an)), lcm(a2, gcd(a3 .. an)) ....) or
    // ans = gcd(lcm(gcd(a1 .. a1), a2), lcm(gcd(a1 .. a2), a3) ...)
    ll n, x;
    cin >> n;
    ll ans = 0, pref = 0;
    for (ll i = 0; i < n; i++) {
        cin >> x;
        ans = gcd(ans, lcm(pref, x));
        pref = gcd(x, pref);  // gcd of prefix
    }
    cout << ans << '\n';
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
        // Shorter();
    }
    return 0;
}