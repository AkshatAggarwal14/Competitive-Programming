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

const ll N = 3010;
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

void Solution() {
    ll n, ans = 0;
    cin >> n;
    for (ll i = 1; i <= n; ++i) {
        set<ll> st;
        ll t = i;
        while (t != 1) {
            st.insert(spf[t]);
            t /= spf[t];
        }
        if (sz(st) == 2) ans++;
    }
    cout << ans << '\n';
}

// clang-format off
int main() {
    fill();
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    // ll tc; cin >> tc; while (tc--)
    Solution();
    return 0;
}