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
const ll N = 1000;
vector<ll> operations(N + 1, LLONG_MAX);

mt19937 rng(uint32_t(chrono::steady_clock::now().time_since_epoch().count()));
#define uid(a, b) uniform_int_distribution<ll>(a, b)(rng)

ll knapsack(ll W, vector<ll> weight, vector<ll> value) {
    // making and initializing dp array
    ll n = sz(weight);
    assert(sz(value) == n);
    vector<ll> dp(W + 1, 0);
    for (ll i = 1; i < n + 1; i++) {
        for (ll w = W; w >= 0; w--) {
            // finding the maximum value
            if (weight[i - 1] <= w)
                dp[w] = max(dp[w], dp[w - weight[i - 1]] + value[i - 1]);
        }
    }
    return dp[W];  // returning the maximum value of knapsack
}

void Solution() {
    ll n, k;
    cin >> n >> k;
    vector<ll> op(n), coins(n);
    for (ll &B : op) cin >> B, B = operations[B];
    for (ll &C : coins) cin >> C;
    // DP, atmost k operations, maximise coins
    // max(operations[i]) = 12, thus min(k, 12 * n)
    cout << knapsack(min(k, 12 * n), op, coins) << '\n';
}

int main() {
    // precalc operations required for each
    operations[1] = 0;
    for (ll par = 1; par <= N; par++) {
        for (ll child = 1; child <= N; child++) {
            ll val = par + (par / child);
            if (val <= N) amin(operations[val], operations[par] + 1);
        }
    }
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