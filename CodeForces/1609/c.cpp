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

const ll N = 1'000'000;
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

// make pair with count of contiguous..
vector<pair<ll, ll>> compress(const vector<ll> &t) {
    if (t.empty()) return {};
    vector<pair<ll, ll>> res;
    ll cnt = 0, last = t[0];
    for (ll i = 0; i < sz(t); ++i) {
        if (t[i] == last) {
            cnt++;
        } else {
            res.push_back({last, cnt});
            last = t[i], cnt = 1;
        }
    }
    if (cnt) res.push_back({last, cnt});
    return res;
}

// sieve to check prime, fast!!
bool isPrime(ll n) { return (spf[n] == n); }

void Solution() {
    ll n, e, ctr = 0;
    cin >> n >> e;
    vector<ll> a(n), temp;
    vector<pair<ll, ll>> choice;
    for (ll &x : a) cin >> x;
    for (ll i = 0; i < e; ++i) {  // O(e*(n/e))
        temp.clear();
        choice.clear();
        for (ll j = i; j < n; j += e) temp.push_back(a[j]);  // jumps with gap e

        choice = compress(temp);
        //! calculate for each choice
        for (ll i = 0; i < sz(choice) - 1; ++i) {
            pair<ll, ll> c1 = choice[i], c2 = choice[i + 1];
            // now working with consecutive numbers in each choice
            // (1, P) -> only first P used
            if (c1.first == 1 && isPrime(c2.first)) ctr += (c1.second);
            // (P, 1) -> only last P used
            if (isPrime(c1.first) && c2.first == 1) ctr += (c2.second);
            // (1, P, 1) -> ones should have only 1 Prime in between
            if (c1.first == 1 && isPrime(c2.first) && c2.second == 1 && i + 2 < sz(choice) && choice[i + 2].first == 1)
                ctr += (c1.second * choice[i + 2].second);  // 1s before * 1s after
        }
    }
    cout << ctr << '\n';
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
    ll tc; cin >> tc; while (tc--)
    Solution();
    return 0;
}