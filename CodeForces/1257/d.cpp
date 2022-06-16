#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
auto sz = [](const auto &container) -> ll { return ll(container.size()); };
#define all(x) (x).begin(), (x).end()
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

void Solution() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll &A : a) cin >> A;
    ll n_heroes;
    cin >> n_heroes;
    vector<ll> max_power(n, -INF);  // find max power for given endurance
    // if hero can do 5 monsters, with power 100, he can do 4 too
    for (ll i = 0, p, si; i < n_heroes; ++i) {
        cin >> p >> si, --si;
        max_power[si] = max(max_power[si], p);
    }
    for (ll i = n - 2; i >= 0; --i) max_power[i] = max(max_power[i], max_power[i + 1]);

    /*
    Sparse_Table<ll> st(
        a,
        [](const ll &A, const ll &B) -> ll { return max(A, B); },
        []() -> ll { return -INF; });
    int index = 0;
    ll ans = 0;
    // dbg(max_p);

    while (index < n) {
        int L = index, R = int(n) - 1;
        --L, ++R;
        while (R > L + 1) {
            int M = (L + R) / 2;
            // if max power of given length is >= max of array
            // binary search for how far can i go (longest endurance possible) if the hero selected can fight the monster with maximum power in this range
            if (max_power[M - index] >= st.query(index, M)) {
                L = M;
            } else {
                R = M;
            }
        }
        if (index == L + 1) return void(cout << "-1\n");  // if none found
        index = L + 1;                                    // if found move to next segment
        ++ans;                                            // how many segments?
    }

    cout << ans << '\n';
    */
    //! can be done directly as the each point is in exactly one segment so it will be O(N)
    ll index = 0;
    ll ans = 0;
    // dbg(max_power);

    while (index < n) {
        ll L = index, x = -INF;
        while (L < n && (max_power[L - index] >= max(x, a[L]))) {
            x = max(x, a[L]);
            ++L;
        }
        if (index == L) return void(cout << "-1\n");  // if none found
        index = L;                                    // if found move to next segment
        ++ans;                                        // how many segments?
    }

    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}