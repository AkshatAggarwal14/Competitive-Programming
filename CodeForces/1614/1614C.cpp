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

const ll MOD = 1e9 + 7;
ll power(ll x, ll y, ll p) {
    ll res = 1;
    x %= p;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

ll xorSum(vector<ll> a) {
    ll bits = 0;
    for (ll i = 0; i < sz(a); ++i) bits |= a[i];
    ll ans = (bits % MOD) * (power(2LL, sz(a) - 1, MOD) % MOD);
    return (ans % MOD);
}
//https://www.geeksforgeeks.org/sum-xor-possible-subsets/
const ll N = 30;
void Solution() {
    ll n, m, l, r, val;
    cin >> n >> m;
    vector<tuple<ll, ll, ll>> v(m);
    for (ll i = 0; i < m; ++i) {
        cin >> l >> r >> val;
        l--, r--;
        v[i] = make_tuple(l, r, val);
    }
    // bit by bit
    // set all bits of each term 1, then go bit by bit, and if for a certain bit in a given range the bit must be 0 then make that bit 0 in answer.
    vector<bitset<N>> a(n, bitset<N>((1LL << N) - 1));
    for (ll i = 0; i < N; ++i) {
        ll mask = (1LL << i);
        vector<ll> cnt(n + 1, 0);
        for (ll j = 0; j < m; ++j) {
            ll L = get<0>(v[j]);
            ll R = get<1>(v[j]);
            bool value = (get<2>(v[j])) & mask;
            if (!value) cnt[L] += 1, cnt[R + 1] -= 1;
        }
        for (ll j = 1; j <= n; ++j) cnt[j] += cnt[j - 1];
        for (ll j = 0; j < n; ++j) a[j][i] = !(cnt[j]);
        // debug statements.
        for (ll j = 0; j < n; ++j) cerr << a[j][i] << ' ';
        cerr << '\n';
    }
    vector<ll> seq(n);
    for (ll i = 0; i < n; ++i) seq[i] = a[i].to_ullong();
    dbg(seq);
    cout << xorSum(seq) << '\n';
}

void Better() {
    ll n, m, l, r, val, or_all = 0;
    cin >> n >> m;
    for (ll i = 0; i < m; ++i) {
        cin >> l >> r >> val;
        or_all |= val;
    }
    ll ans = (or_all % MOD) * (power(2LL, n - 1, MOD) % MOD);
    cout << (ans % MOD) << '\n';
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
    Better();
    return 0;
}