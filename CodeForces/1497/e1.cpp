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

vector<ll> compress(const vector<ll> &items) {
    if (items.empty()) return {};
    vector<ll> encoded;
    ll count = 0;
    ll last = items[0];
    for (const ll &item : items) {
        if (item == last) {
            count++;
        } else {
            if (count & 1) encoded.push_back(last);  //! push in set if odd
            last = item, count = 1;
        }
    }
    if (count & 1) encoded.push_back(last);
    return encoded;
}

// N = p1^a1 * p2^a2 ..
// N1 * N2 = perfect square if and only if, ai in both are odd or even for same pi
// the sum of ai must be even

// evens can be ignored, odd wale must be equal
void Solution() {
    ll n, k, temp;
    cin >> n >> k;
    set<vector<ll>> st;
    ll ans = 1;
    vector<ll> A;
    for (ll i = 0; i < n; ++i) {
        cin >> temp;
        A = compress(prime_factorisation(temp));  // pi^ai -> odd ai's
        if (st.contains(A)) {
            st.clear();  // start a new segment
            ++ans;
        }
        st.insert(A);
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
    cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}