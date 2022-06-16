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

const ll N = 2'00'00'00;  // as sum of two
array<ll, N + 1> spf;
vector<ll> pr;
void fill() {
    for (ll i = 2; i <= N; ++i) {
        if (spf[i] == 0) spf[i] = i, pr.push_back(i);
        for (ll j = 0; j < (ll)pr.size() && pr[j] <= spf[i] && i * pr[j] <= N; ++j)
            spf[i * pr[j]] = pr[j];
    }
}

bool isPrime(ll n) {
    assert(n >= 0 && n <= N);
    return (spf[n] == n);
}

void Solution() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll &A : a) cin >> A;
    vector<ll> res = {a[0]};  // atleast 1 always in answer
    for (ll i = 0; i < n - 1; ++i)
        for (ll j = i + 1; j < n; ++j)
            if (isPrime(a[i] + a[j])) res = {a[i], a[j]};  // if 2 nums sum to prime
    vector<ll> ans1;
    ll c1 = count(all(a), 1);
    while (c1--) ans1.push_back(1);
    for (ll i = 0; i < n; ++i) {  // 1 can be paired with prime - 1
        if (a[i] == 1) continue;
        if (isPrime(a[i] + 1)) {
            ans1.push_back(a[i]);
            break;
        }
    }
    if (sz(ans1) > sz(res)) res = ans1;
    cout << sz(res) << '\n';
    for (ll &x : res) cout << x << ' ';
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